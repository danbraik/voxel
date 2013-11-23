#include <iostream>
#include "ChunkManager.hpp"
#include "Mesh.hpp"
#include "VectorTools.hpp"
#include <algorithm>

ChunkManager::ChunkManager(const BlockList &list, ChunkPersistence &persistence) : 
	mList(list),
	mPositionChunksToLoad(), mChunksToRebuild(),
	mChunksToUnload()	, mPool(*this),mPersistence(persistence)
{
	
}

Chunk * ChunkManager::createEmptyChunk(const sf::Vector3i &chunkPosition) {
	Chunk * chunk = mPool.getFreeChunk();
	if (chunk != 0)
		chunk->setPosition(chunkPosition);
	return chunk;
}

void ChunkManager::init()
{
	const PositionVector & exis = mPersistence.getExistingPositions();
	for(PositionVector::const_iterator it = exis.begin();
		it != exis.end(); ++it)
			reqLoadChunk(*it);
}

void ChunkManager::reinit()
{
	for(ChunkMap::iterator it = mLoadedChunks.begin();
		it != mLoadedChunks.end(); ++it) {
		it->second->init();
		mChunksToRebuild.push_back(it->second);
	}
}

void ChunkManager::deleteChunk(sf::Vector3i &absBkPos)
{
	sf::Vector3i cp = getChkPosByAbsBkPos(absBkPos);
	
	Chunk * chunk;
	if (isChunkLoaded(cp,chunk)) {
		reqUnloadChunk(chunk);
	}
}

void ChunkManager::visible(const sf::Vector3i &absBkPos)
{
	reqLoadChunk(absBkPos);
}




const Block & ChunkManager::getBlock(BlockType type) const
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
	return mList.get( getBlockType(absoluteBlockPosition) );
}

BlockType ChunkManager::getBlockType(const sf::Vector3i &absoluteBlockPosition) const
{
	sf::Vector3i chunkPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	Chunk * chunk = 0;
	
	if (!isChunkLoaded(chunkPosition, chunk)) {
		return Block::NONE;
	}
	
	sf::Vector3i insideChunkBlockPosition =
			absoluteBlockPosition -
			(chunkPosition) * Chunk::SIZE;
	
	return chunk->get(insideChunkBlockPosition);
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
	
	// todo : optimise again, select neighbours
	if (Chunk::isStrictelyInside(insideChunkBlockPosition))
		reqRebuildChunk(chunk);
	else
		rebuildWithNeighbours(chunk, chunkPosition);
}

void ChunkManager::update()
{
	const int maxLoad = 500;
	const int maxRebuild = 1000;
	const int maxUnload = 100;
	
	// -- Load chunks
	int chunksLoaded = 0;
	if (mPositionChunksToLoad.size() > 0) {
		for(Vec3iList::iterator it = mPositionChunksToLoad.begin();
			it != mPositionChunksToLoad.end() && chunksLoaded < maxLoad;
			it = mPositionChunksToLoad.erase(it), ++chunksLoaded) {
			
			const sf::Vector3i & chunkPosition = *it;
			Chunk * chunk = 0;
			
			if(!isChunkLoaded(chunkPosition, chunk)) {
				chunk = createEmptyChunk(chunkPosition);	
				if (chunk == 0)
					break;
				//*				
				if (!mPersistence.loadChunk(chunk))
					chunk->init(); // new chunk
				mLoadedChunks[chunkPosition] = chunk;//*/
				/*
				if (mPersistence.loadChunk(chunk))
					mLoadedChunks[chunkPosition] = chunk;
				else {
					mPool.giveBackChunk(chunk);
					continue;
				}
				//*/
				
				rebuildWithNeighbours(chunk, chunkPosition);
			}
		}
		//mPositionChunksToLoad.clear();
		//std::cout << "CMup: (l) " << chunksLoaded << " loaded." << std::endl;
	}
	// -- end
	
	
	// -- Rebuild chunks
	//std::cout << "CMup: (b) " << mChunksToRebuild.size() << " to rebuild." << std::endl;
	int chunkRebuild = 0;
	if (mChunksToRebuild.size() > 0) {
		for(ChunkList::iterator it = mChunksToRebuild.begin();
			it != mChunksToRebuild.end() && chunkRebuild < maxRebuild;
			it = mChunksToRebuild.erase(it), ++chunkRebuild) {
			
			
			(*it)->rebuild(*this);
		}
		//mChunksToRebuild.clear();
		//std::cout << "CMup: (r) " << chunkRebuild << " rebuilded." << std::endl;
	}
	//std::cout << "CMup: (a) " << mChunksToRebuild.size() << " to rebuild." << std::endl;
	//std::cout << std::endl;
	// -- end
	
	
	
	// -- Unload chunks
	int chunkUnload = 0;
	if (mChunksToUnload.size() > 0) {
		for(ChunkList::iterator it = mChunksToUnload.begin();
			it != mChunksToUnload.end() && chunkUnload < maxUnload; 
			it = mChunksToUnload.erase(it), ++chunkUnload) {
			
			// save to disk
			mPersistence.saveChunk(*it);
			mPool.giveBackChunk(*it);			
			
			
		}
		//mChunksToUnload.clear();
		//std::cout << "CMup: (u) " << chunkUnload << " Unloaded." << std::endl;
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

bool ChunkManager::isChunkLoaded(const sf::Vector3i &chunkPosition, const Chunk *& chunk) const
{
	Chunk * c;
	if (isChunkLoaded(chunkPosition, c)) {
		chunk = c;
		return true;
	}
	return false;
}

Chunk *ChunkManager::getChunk(const sf::Vector3i &chunkPosition) const
{
	return mLoadedChunks.find(chunkPosition)->second;
}

void ChunkManager::rebuildWithNeighbours(Chunk *chunk, const sf::Vector3i &chunkPosition)
{
	mChunksToRebuild.push_back(chunk);
	
	Chunk * nearChunk = 0;
	if (isChunkLoaded(chunkPosition + VectorTools::EX, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EX, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	if (isChunkLoaded(chunkPosition + VectorTools::EY, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EY, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	if (isChunkLoaded(chunkPosition + VectorTools::EZ, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EZ, nearChunk))
		mChunksToRebuild.push_back(nearChunk);
	
	// need to rebuild others too (think about torches)
	// ...
}

void ChunkManager::reqLoadChunk(const sf::Vector3i &chunkPosition)
{
	mPositionChunksToLoad.push_back(chunkPosition);
}

void ChunkManager::reqRebuildChunk(Chunk* & chunk)
{
	mChunksToRebuild.push_back(chunk);
}

void ChunkManager::reqUnloadChunk(Chunk* & chunk)
{
	// avoid to use this chunk in computation
	mLoadedChunks.erase(chunk->getPosition());
	mChunksToUnload.push_back(chunk);
}



ChunkManager::~ChunkManager() {
	for(ChunkMap::iterator it = mLoadedChunks.begin();
		it != mLoadedChunks.end(); ++it) {
		// unload (save to disk)
		mPersistence.saveChunk(it->second);		
		mPool.giveBackChunk(it->second);
	}
}
