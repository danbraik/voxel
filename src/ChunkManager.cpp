#include "ChunkManager.hpp"
#include <iostream>
#include "Mesh.hpp"

ChunkManager::ChunkManager(BlockList &list, Renderer &renderer) : 
	mList(list), mRenderer(renderer), 
	mPositionChunksToLoad(), mChunksToRebuild(),
	EX(1,0,0),EY(0,1,0),EZ(0,0,1)
{
}

Chunk * ChunkManager::createEmptyChunk(const sf::Vector3i &chunkPosition) {
	Chunk * chunk = getFreeChunk();
	chunk->setPosition(chunkPosition);
	return chunk;
}

void ChunkManager::init()
{
	for (int i=0; i< 20;++i)
		for (int j=0; j< 20;++j) 
			reqLoadChunk(sf::Vector3i(i,j,0));
}

void ChunkManager::reinit()
{
	for(ChunkMap::iterator it = mLoadedChunks.begin();
		it != mLoadedChunks.end(); ++it) {
		it->second->init();
		mChunksToRebuild.push_back(it->second);
	}
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
	Chunk * chunk = 0;
	
	if (!isChunkLoaded(chunkPosition, chunk)) {
		return mList.get(Block::NONE);
	}
	
	sf::Vector3i insideChunkBlockPosition =
			absoluteBlockPosition -
			(chunkPosition) * Chunk::SIZE;
	
	return mList.get( chunk->get(insideChunkBlockPosition) );
}

const Block &ChunkManager::getRelativeBlock(const sf::Vector3i & fromChunkPosition,
											const sf::Vector3i & relativeBlockPosition) const
{
	
	sf::Vector3i chunkPosition = 
			getChkPosByRelBkPos(fromChunkPosition, relativeBlockPosition);
	
	Chunk * chunk = 0;
	
	if (!isChunkLoaded(chunkPosition, chunk)) {
		return mList.get(Block::NONE);
	}
	
	sf::Vector3i insideChunkBlockPosition = getInsideBkPosByRelBkPos(fromChunkPosition, 
																	 chunkPosition, 
																	 relativeBlockPosition);
	return mList.get( chunk->get(insideChunkBlockPosition) );
}

void ChunkManager::setBlockType(const sf::Vector3i &absoluteBlockPosition, BlockType type)
{
	sf::Vector3i chunkPosition = 
			getChkPosByAbsBkPos(absoluteBlockPosition);
	
	Chunk * chunk = 0;
	if (!isChunkLoaded(chunkPosition, chunk)) {
		reqLoadChunk(chunkPosition);
		// add cube change to toBeTreat list
		// or not (suppose chunk would be load
		// before we can edit it)
		return;
	}
	
	sf::Vector3i insideChunkBlockPosition =
			getInsideBkPosByAbsBkPos(chunkPosition, absoluteBlockPosition);
	
	chunk->set(insideChunkBlockPosition, type);
	reqRebuildChunk(chunk);
}

void ChunkManager::update()
{
	int maxLoad = 5;
	int maxRebuild = 5;
	
	// -- Load chunks
	int chunksLoaded = 0;
	if (mPositionChunksToLoad.size() > 0) {
		Chunk * nearChunk = 0;
		for(Vec3iList::iterator it = mPositionChunksToLoad.begin();
			it != mPositionChunksToLoad.end() && chunksLoaded < maxLoad; ++it) {
			++chunksLoaded;
			
			const sf::Vector3i & chunkPosition = *it;
			
			
			
			Chunk * chunk = createEmptyChunk(chunkPosition);
			chunk->init(); // load data
			mLoadedChunks[chunkPosition] = chunk;
			
			mChunksToRebuild.push_back(chunk);
			
			if (isChunkLoaded(chunkPosition + EX, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			if (isChunkLoaded(chunkPosition - EX, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			if (isChunkLoaded(chunkPosition + EY, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			if (isChunkLoaded(chunkPosition - EY, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			if (isChunkLoaded(chunkPosition + EZ, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			if (isChunkLoaded(chunkPosition - EZ, nearChunk))
				mChunksToRebuild.push_back(nearChunk);
			
			
			// remove task
			it = mPositionChunksToLoad.erase(it);
		}
		//mPositionChunksToLoad.clear();
	}
	// -- end
	
	
	// -- Rebuild chunks
	int chunkRebuild = 0;
	if (mChunksToRebuild.size() > 0) {
		for(ChunkList::iterator it = mChunksToRebuild.begin();
			it != mChunksToRebuild.end() && chunkRebuild < maxRebuild; ++it) {
			++chunkRebuild;
			(*it)->rebuild(*this);
			
			// rm task
			it = mChunksToRebuild.erase(it);
		}
		//mChunksToRebuild.clear();
	}
	// -- end
	
	
}

void ChunkManager::draw(Renderer &renderer) const
{
	sf::Vector3i oldPosition;
	
	for  (ChunkMap::const_iterator it = mLoadedChunks.begin();
		  it != mLoadedChunks.end(); ++it) {
		
		const sf::Vector3i & chunkPosition = it->first;
		const Chunk * chunk = it->second;
		
		// use oldPosition to compute difference
		// between previous and current chunks
		oldPosition -= chunkPosition;
		
		renderer.translate(
					-oldPosition.x*
					Chunk::SIZE*Block::SIZE,
					-oldPosition.y*
					Chunk::SIZE*Block::SIZE,
					-oldPosition.z*
					Chunk::SIZE*Block::SIZE);
		chunk->draw();
		
		oldPosition = chunkPosition;
	}
}



bool ChunkManager::isChunkLoaded(const sf::Vector3i &chunkPosition, Chunk* & chunk) const
{
	ChunkMap::const_iterator it = 
			mLoadedChunks.find(chunkPosition);
	
	if (it == mLoadedChunks.end())
		return false;
	
	chunk = it->second;
	return true;
}

Chunk *ChunkManager::getChunk(const sf::Vector3i &chunkPosition) const
{
	return mLoadedChunks.find(chunkPosition)->second;
}

void ChunkManager::reqLoadChunk(const sf::Vector3i &chunkPosition)
{
	mPositionChunksToLoad.push_back(chunkPosition);
}

void ChunkManager::reqRebuildChunk(Chunk *chunk)
{
	mChunksToRebuild.push_back(chunk);
}



// Pool of chunk
Chunk *ChunkManager::getFreeChunk()
{
	Chunk * chunk = new Chunk;
	if (chunk == 0)
		std::cerr << "Error when allocating chunk !" << std::endl;
	return chunk;
}

void ChunkManager::giveBackChunk(Chunk* & chunk)
{
	delete chunk;
	chunk = 0;
}

