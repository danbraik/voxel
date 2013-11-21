#include "ChunkManager.hpp"
#include <iostream>
#include "Mesh.hpp"

ChunkManager::ChunkManager(BlockList &list, Renderer &renderer) : mList(list), mRenderer(renderer)
{
}

Chunk * ChunkManager::createEmptyChunk(const sf::Vector3i &chunkPosition) const {
	Chunk * chunk = 0;
	chunk = new Chunk();
	if (chunk == 0)
		std::cerr << "Error when allocating chunk !" << std::endl;
	chunk->setPosition(chunkPosition);
	return chunk;
}

void ChunkManager::init()
{
	for (int i=0; i< 2;++i)
		for (int j=0; j< 2;++j) 
			loadChunk(sf::Vector3i(i,j,0));
	
	
	for  (LoadedChunkMap::const_iterator it = mLoadedChunks.begin();
		  it != mLoadedChunks.end();
		  ++it) {
		it->second->init();
		update(it->second);
	}
}

void ChunkManager::update(Chunk * chunk) {
	mCurrentPositionChunk = chunk->getPosition();
	chunk->update(*this);
}

const Block &ChunkManager::getBlock(BlockType type) const
{
	return mList.get(type);
}



inline sf::Vector3i ChunkManager::getChkPosByAbsBkPos(const sf::Vector3i &absoluteBlockPosition) const
{
	return absoluteBlockPosition / Chunk::SIZE;
}

inline sf::Vector3i ChunkManager::getChkPosByRelBkPos(const sf::Vector3i & fromChunkPosition, const sf::Vector3i &relativeBlockPosition) const
{
	return 
		(fromChunkPosition * Chunk::SIZE + relativeBlockPosition) 
			/ Chunk::SIZE;
}

inline sf::Vector3i ChunkManager::getInsideBkPosByAbsBkPos(const sf::Vector3i &toChunkPosition, 
														   const sf::Vector3i &absoluteBlockPosition) const
{
	return 
			absoluteBlockPosition
			 -
			(toChunkPosition ) * Chunk::SIZE;
}

inline sf::Vector3i ChunkManager::getInsideBkPosByRelBkPos(const sf::Vector3i & fromChunkPosition, 
														   const sf::Vector3i & toChunkPosition,
														   const sf::Vector3i & relativeBlockPosition) const
{
	return 
			relativeBlockPosition -
			(toChunkPosition - fromChunkPosition) * Chunk::SIZE;
}

const Block &ChunkManager::getBlock(const sf::Vector3i & absoluteBlockPosition) const
{
	sf::Vector3i chunkPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	
	if (!isChunkLoaded(chunkPosition)) {
		return mList.get(Block::NONE);
	}
	
	sf::Vector3i insideChunkBlockPosition =
			absoluteBlockPosition -
			(chunkPosition - mCurrentPositionChunk) * Chunk::SIZE;
	
	Chunk * chunk = getChunk(chunkPosition);
	return mList.get( chunk->get(insideChunkBlockPosition) );
}

const Block &ChunkManager::getRelativeBlock(const sf::Vector3i & relativeBlockPosition) const
{
	sf::Vector3i chunkPosition = 
			getChkPosByRelBkPos(mCurrentPositionChunk, relativeBlockPosition);
	
	if (!isChunkLoaded(chunkPosition)) {
		return mList.get(Block::NONE);
	}
	
	sf::Vector3i insideChunkBlockPosition = getInsideBkPosByRelBkPos(mCurrentPositionChunk, 
																	 chunkPosition, 
																	 relativeBlockPosition);
	Chunk * chunk = getChunk(chunkPosition);
	return mList.get( chunk->get(insideChunkBlockPosition) );
}

void ChunkManager::setBlockType(const sf::Vector3i &absoluteBlockPosition, BlockType type)
{
	sf::Vector3i chunkPosition = 
			getChkPosByAbsBkPos(absoluteBlockPosition);
	
	if (!isChunkLoaded(chunkPosition)) {
		loadChunk(chunkPosition);
		// add chunk to toBeLoad list
		// add cube change to toBeTreat list
	}
	
	sf::Vector3i insideChunkBlockPosition =
			getInsideBkPosByAbsBkPos(chunkPosition, absoluteBlockPosition);
			
	
	Chunk * chunk = getChunk(chunkPosition);
	chunk->set(insideChunkBlockPosition, type);
	update(chunk);
}

void ChunkManager::draw(Renderer &renderer) const
{
	
	for  (LoadedChunkMap::const_iterator it = mLoadedChunks.begin();
		  it != mLoadedChunks.end();
		  ++it) {
		const sf::Vector3i & chunkPosition = it->first;
		renderer.translate(
					chunkPosition.x*
					Chunk::SIZE*Block::SIZE,
					chunkPosition.y*
					Chunk::SIZE*Block::SIZE,
					chunkPosition.z*
					Chunk::SIZE*Block::SIZE);
		it->second->draw();
		renderer.translate(
					-chunkPosition.x*
					Chunk::SIZE*Block::SIZE,
					-chunkPosition.y*
					Chunk::SIZE*Block::SIZE,
					-chunkPosition.z*
					Chunk::SIZE*Block::SIZE);
		
	}
}



bool ChunkManager::isChunkLoaded(const sf::Vector3i &chunkPosition) const
{
	LoadedChunkMap::const_iterator it = mLoadedChunks.find(chunkPosition);
	return it != mLoadedChunks.end();
}

Chunk *ChunkManager::getChunk(const sf::Vector3i &chunkPosition) const
{
	return mLoadedChunks.find(chunkPosition)->second;
}

void ChunkManager::loadChunk(const sf::Vector3i &chunkPosition)
{
	Chunk * chunk = createEmptyChunk(chunkPosition);
	chunk->update(*this);
	mLoadedChunks[chunkPosition] = chunk;
}

