#include <iostream>
#include "ChunkManager.hpp"
#include "Mesh.hpp"
#include "VectorTools.hpp"
#include <algorithm>

ChunkManager::ChunkManager(const BlockList &list, ChunkPersistence &persistence) : 
	mList(list),
	mPositionChunksToLoad(), mChunksToRebuild(),
	mChunksToUnload()	, mPool(*this), mDataPool(), mPersistence(persistence)
{
	
}

bool ChunkManager::acquireChunk(Chunk *& chunk, const ChunkCoordinate & chunkPosition) {
	chunk = mPool.getFreeChunk();
	if (chunk != 0) {
		chunk->reset();
		chunk->setPosition(chunkPosition);
		return true;
	}
	return false;
}

void ChunkManager::releaseChunk(Chunk *chunk)
{
	mDataPool.giveBackChunkData(chunk->getData());
	mPool.giveBackChunk(chunk);
}

bool ChunkManager::acquireChunkData(Chunk * chunk)
{
	ChunkData * cd = mDataPool.getFreeChunkData();
	if (cd != 0) {
		cd->reset();
		chunk->setData(cd);
		return true;
	}
	chunk->setData(0);
	return false;
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
		it->second->reset();
		mChunksToRebuild.insert(it->second);
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

void ChunkManager::loadChunk(const sf::Vector3i &absBkPos)
{
	
	reqLoadChunk(getChkPosByAbsBkPos( absBkPos));
}

void ChunkManager::visible(const sf::Vector3i &absBkPos)
{
	sf::Vector3i cp = getChkPosByAbsBkPos(absBkPos);
	for (int x = -5; x <5;++x)
		for(int y=-5;y< 5;++y)
			for (int z=-2;z<15;++z)
				reqLoadChunk(cp + sf::Vector3i(x,y,z));
}

void ChunkManager::resetChunk(const sf::Vector3i &absBkPos)
{
	sf::Vector3i cp = getChkPosByAbsBkPos(absBkPos);
	Chunk * chunk;
	if (isChunkLoaded(cp,chunk)) {
		std::cout << "Reset chunk ("
				  <<cp.x<<" "<<cp.y<<" "<<cp.z<<")"<<std::endl;
		chunk->reset();
	}
}

// ***************************


const Block & ChunkManager::getBlock(BlockType type) const
{
	return mList.get(type);
}



inline sf::Vector3i ChunkManager::getChkPosByAbsBkPos(const sf::Vector3i &absoluteBlockPosition) const
{
	sf::Vector3i pos = absoluteBlockPosition;
//	if  (pos.x < 0)
//		pos.x -= Chunk::SIZE;
//	if  (pos.y < 0)
//		pos.y -= Chunk::SIZE;
//	if  (pos.z < 0)
//		pos.z -= Chunk::SIZE;
	pos.x >>= Chunk::SIZE_DEC;
	pos.y >>= Chunk::SIZE_DEC;
	pos.z >>= Chunk::SIZE_DEC;

	return pos ;//  / Chunk::SIZE;
}

inline sf::Vector3i ChunkManager::getChkPosByRelBkPos(const sf::Vector3i & fromChunkPosition, const sf::Vector3i &relativeBlockPosition) const
{
	return getChkPosByAbsBkPos(fromChunkPosition * Chunk::SIZE + relativeBlockPosition);
}

inline sf::Vector3i ChunkManager::getInsideBkPosByAbsBkPos(const sf::Vector3i &toChunkPosition, 
														   const sf::Vector3i &absoluteBlockPosition) const
{
	return absoluteBlockPosition - (toChunkPosition * Chunk::SIZE);
}

inline sf::Vector3i ChunkManager::getInsideBkPosByRelBkPos(const sf::Vector3i & fromChunkPosition, 
														   const sf::Vector3i & toChunkPosition,
														   const sf::Vector3i & relativeBlockPosition) const
{
	return relativeBlockPosition - 
			(toChunkPosition - fromChunkPosition) * Chunk::SIZE;
}

const Block &ChunkManager::getBlock(const sf::Vector3i & absoluteBlockPosition) const
{
	return mList.get( getBlockType(absoluteBlockPosition) );
}

BlockType ChunkManager::getBlockType(const sf::Vector3i &absoluteBlockPosition) const
{
	ChunkCoordinate chunkPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	Chunk * chunk = 0;
	
	if (!isChunkLoaded(chunkPosition, chunk)) {
		return Block::AIR;
	}
	
	BlockCoordinate insideChunkBlockPosition =
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
		return mList.get(Block::AIR);
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
		// dont add cube change to some toBeTreat list
		// (suppose chunk would be load
		// before we can edit it)
		return;
	}
	
	sf::Vector3i insideChunkBlockPosition =
			getInsideBkPosByAbsBkPos(chunkPosition, absoluteBlockPosition);
	
	chunk->set(insideChunkBlockPosition, type);
	
	// the current chunk state cannot be
	// generated again (can't generate user action ^^)
	chunk->setModified();
	
	// todo : optimise again, select neighbours
	if (Chunk::isStrictelyInside(insideChunkBlockPosition))
		reqRebuildChunk(chunk);
	else
		rebuildWithNeighbours(chunk, chunkPosition);
}

void ChunkManager::update()
{
	const int maxLoad = 1;
	const int maxRebuild = 1;
	const int maxUnload = 100;
	
	// -- Load chunks
	int chunksLoaded = 0;
	if (mPositionChunksToLoad.size() > 0) {
		for(PositionSet::iterator it = mPositionChunksToLoad.begin();
			it != mPositionChunksToLoad.end() && chunksLoaded < maxLoad;
			mPositionChunksToLoad.erase(it++), ++chunksLoaded) {
			
			const sf::Vector3i & chunkPosition = *it;
			Chunk * chunk = 0;
			
			if(!isChunkLoaded(chunkPosition, chunk)) {
				
				if (! acquireChunk(chunk, chunkPosition))
					break;
				//*				
				ChunkPersistenceCache cache;
				if (mPersistence.isIndexed(chunkPosition, cache)) {
					// assert(chunk has at least one block set by user)
					
					if (acquireChunkData(chunk)) {
						mPersistence.loadChunk(chunk, cache);
						
						// setup
						//...
						
						mLoadedChunks[chunkPosition] = chunk;
					}
					
				} else {
					if (acquireChunkData(chunk)) {
						if (mWorldGen.willBeEmpty(chunk)) {
							chunk->setCompletelyEmpty();
							mDataPool.giveBackChunkData(chunk->getData());
							chunk->invalidData();
						}
						mLoadedChunks[chunkPosition] = chunk;
					}
				}
				
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
		for(ChunkSet::iterator it = mChunksToRebuild.begin();
			it != mChunksToRebuild.end() && chunkRebuild < maxRebuild;
			 mChunksToRebuild.erase(it++), ++chunkRebuild) {
			
			
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
		for(ChunkSet::iterator it = mChunksToUnload.begin();
			it != mChunksToUnload.end() && chunkUnload < maxUnload; 
			mChunksToUnload.erase(it++), ++chunkUnload) {
			
			// save to disk
			// maybe bug : already given back
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
	mChunksToRebuild.insert(chunk);
	
	Chunk * nearChunk = 0;
	if (isChunkLoaded(chunkPosition + VectorTools::EX, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EX, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	if (isChunkLoaded(chunkPosition + VectorTools::EY, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EY, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	if (isChunkLoaded(chunkPosition + VectorTools::EZ, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	if (isChunkLoaded(chunkPosition - VectorTools::EZ, nearChunk))
		mChunksToRebuild.insert(nearChunk);
	
	// need to rebuild others too (think about torches)
	// ...
}

void ChunkManager::reqLoadChunk(const sf::Vector3i &chunkPosition)
{
	mPositionChunksToLoad.insert(chunkPosition);
}

void ChunkManager::reqRebuildChunk(Chunk* & chunk)
{
	mChunksToRebuild.insert(chunk);
}

void ChunkManager::reqUnloadChunk(Chunk* & chunk)
{
	// avoid to use this chunk in computation
	mLoadedChunks.erase(chunk->getPosition());
	mChunksToUnload.insert(chunk);
}



ChunkManager::~ChunkManager() {
	for(ChunkMap::iterator it = mLoadedChunks.begin();
		it != mLoadedChunks.end(); ++it) {
		// unload (save to disk)
		mPersistence.saveChunk(it->second);		
		mPool.giveBackChunk(it->second);
	}
}
