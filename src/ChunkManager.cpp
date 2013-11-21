#include "ChunkManager.hpp"
#include <iostream>

ChunkManager::ChunkManager(BlockList &list) : mList(list)
{
}

void ChunkManager::init(Renderer & renderer)
{
	mLoadedChunks[sf::Vector3i(2,2,0)] = new Chunk();
	mLoadedChunks[sf::Vector3i(3,2,0)] = new Chunk();
	mLoadedChunks[sf::Vector3i(2,3,0)] = new Chunk();
	
	for  (LoadedChunkMap::const_iterator it = mLoadedChunks.begin();
		  it != mLoadedChunks.end();
		  ++it) {
		mCurrentPositionChunk = it->first;
		it->second->update(renderer, *this);
		
	}
}

const Block &ChunkManager::getBlock(BlockType type) const
{
	return mList.get(type);
}

const Block &ChunkManager::getBlock(sf::Vector3i blockPosition) const
{
	sf::Vector3i chunkPosition = 
			blockPosition /= Chunk::SIZE;
	
	if (!isChunkLoaded(chunkPosition)) {
		return mList.get(Block::NONE);
	}
	
	sf::Vector3i relativeBlockPosition =
			blockPosition - chunkPosition * Chunk::SIZE;
	
	Chunk * chunk = getChunk(chunkPosition);
	return mList.get( chunk->get(relativeBlockPosition) );
}

const Block &ChunkManager::getRelativeBlock(sf::Vector3i blockPosition) const
{
	sf::Vector3i chunkPosition = 
			(mCurrentPositionChunk * Chunk::SIZE +
			blockPosition) / Chunk::SIZE;
	
	if (!isChunkLoaded(chunkPosition)) {
		return mList.get(Block::NONE);
	}
	
	
	sf::Vector3i relativeBlockPosition =
			
			blockPosition -
			(chunkPosition - mCurrentPositionChunk) * Chunk::SIZE;
			 
	
	Chunk * chunk = getChunk(chunkPosition);
	return mList.get( chunk->get(relativeBlockPosition) );
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
		it->second->draw(renderer);
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

