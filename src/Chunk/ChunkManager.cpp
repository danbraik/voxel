#include <iostream>
#include "ChunkManager.hpp"
#include "../Render/Mesh.hpp"
#include "../VectorTools.hpp"
#include <algorithm>

ChunkManager::ChunkManager(const BlockList &list, ChunkPersistence &persistence) : 
	mList(list),
	mPositionChunksToLoad(), mChunksToRebuild(),
	mChunksToUnload(), mPersistence(persistence),
	mLoadedChunksGarbage(0), mChunks(), mVisibleChunks()
{
	mChunks.setGlobal(this);
}



void ChunkManager::init()
{
	const PositionVector & exis = mPersistence.getExistingPositions();
	for(PositionVector::const_iterator it = exis.begin();
		it != exis.end(); ++it)
			notifVisibleZone(*it);
}

void ChunkManager::loadChunk(Chunk * chunk) const
{
	ChunkPersistenceCache cache;
	if (mPersistence.isIndexed(chunk->getPosition(), cache)) {
		mPersistence.loadChunk(chunk, cache);
	}
}

void ChunkManager::visible(const sf::Vector3i &absBkPos)
{
	sf::Vector3i cp = getChkPosByAbsBkPos(absBkPos);
	for (int x = -10; x <10;++x)
		for(int y=-10;y< 10;++y)
			for (int z=-10;z<10;++z)
				notifVisibleZone(cp + sf::Vector3i(x,y,z));
}

void ChunkManager::notifVisibleZone(const ChunkCoordinate & position) {
	Chunk * chunk = 0;
	if (! mChunks.isThere(position, chunk)) {
		chunk = mChunks.create(position);
	}
	mVisibleChunks.push_back(chunk);
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

inline sf::Vector3i ChunkManager::getInsideBkPosByAbsBkPos(const ChunkCoordinate &toChunkPosition, 
														   const BlockCoordinate &absoluteBlockPosition) const
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

Block & ChunkManager::getBlock(const BlockCoordinate & absoluteBlockPosition)
{
	ChunkCoordinate chunkPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	Chunk * chunk = 0;
	
	if (!mChunks.isThere(chunkPosition, chunk)) {
		return getNoBlock();
	}
	
	BlockCoordinate insideChunkBlockPosition =
			absoluteBlockPosition -
			(chunkPosition) * Chunk::SIZE;
	
	return chunk->get(insideChunkBlockPosition);
}

const Block & ChunkManager::getBlock(const BlockCoordinate & absoluteBlockPosition) const
{
	ChunkCoordinate chunkPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	Chunk * chunk = 0;
	
	if (!mChunks.isThere(chunkPosition, chunk)) {
		return getNoBlock();
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
		return BlockList::NO_BLOCK;
	}
	
	sf::Vector3i insideChunkBlockPosition = getInsideBkPosByRelBkPos(fromChunkPosition, 
																	 chunkPosition, 
																	 relativeBlockPosition);
	return chunk->get(insideChunkBlockPosition);
}

void ChunkManager::setBlock(const BlockCoordinate &absoluteBlockPosition, Block & block)
{
	ChunkCoordinate chunkPosition = 
			getChkPosByAbsBkPos(absoluteBlockPosition);
	
	Chunk * chunk = 0;
	if (!mChunks.isThere(chunkPosition, chunk)) {
		chunk = mChunks.create(chunkPosition);
		mVisibleChunks.push_back(chunk);
	}
	
	BlockCoordinate insideChunkBlockPosition =
			getInsideBkPosByAbsBkPos(chunkPosition, absoluteBlockPosition);
	
	chunk->setOne(insideChunkBlockPosition, block);
	
	// the current chunk state cannot be
	// generated again (can't generate user action ^^)
	// chunk->setModified();
	
	mChunksToRebuild.push(chunk);
	
	// todo : optimise again, select neighbours
	if (! Chunk::isStrictelyInside(insideChunkBlockPosition)) {
		rebuildNeighbours(chunkPosition);
	}
}

void ChunkManager::update()
{
	
	
//	const int maxLoad = 30;
	const int maxRebuild = 10;
//	const int maxUnload = 100;
	
	
	
//	// -- Load chunks
//	int chunksLoaded = 0;
//	if (mPositionChunksToLoad.size() > 0) {
//		for(PositionSet::iterator it = mPositionChunksToLoad.begin();
//			it != mPositionChunksToLoad.end() && chunksLoaded < maxLoad;
//			mPositionChunksToLoad.erase(it++), ++chunksLoaded) {
			
//			const sf::Vector3i & chunkPosition = *it;
//			Chunk * chunk = 0;
			
//			if(!isChunkLoaded(chunkPosition, chunk)) {
				
//				if (! acquireChunk(chunk, chunkPosition))
//					break;
//				//*				
//				ChunkPersistenceCache cache;
//				if (mPersistence.isIndexed(chunkPosition, cache)) {
//					// assert(chunk has at least one block set by user)
					
//					if (acquireChunkData(chunk)) {
//						mPersistence.loadChunk(chunk, cache);
						
//						// setup
//						//...
						
//						//mLoadedChunks[chunkPosition] = chunk;
//					}
					
//				} else {
					
//					if (mWorldGen.willBeEmpty(chunk)) {
////						chunk->invalidData();
////						mLoadedChunks[chunkPosition] = chunk;
//					} else {
//						if (acquireChunkData(chunk)) {	
//							mWorldGen.gen(chunk);
////							mLoadedChunks[chunkPosition] = chunk;
//						}
//					}
					
//				}
				
////				mLoadedChunks[chunkPosition] = chunk;//*/
//				/*
//				if (mPersistence.loadChunk(chunk))
//					mLoadedChunks[chunkPosition] = chunk;
//				else {
//					mPool.giveBackChunk(chunk);
//					continue;
//				}
//				//*/
				
//				rebuildWithNeighbours(chunk, chunkPosition);
//			}
//		}
//		//mPositionChunksToLoad.clear();
//		//std::cout << "CMup: (l) " << chunksLoaded << " loaded." << std::endl;
//	}
//	// -- end
	
	
	
	
//	// -- Create chunks
//	if (mPositionChunksToCreate.size() > 0) {
//		for(PositionSet::iterator it = mPositionChunksToCreate.begin();
//			it != mPositionChunksToCreate.end();
//			) {
			
//			const sf::Vector3i & chunkPosition = *it;
//			Chunk * chunk = 0;
//			if (isChunkLoaded(chunkPosition, chunk)) {
////				if(chunk->isEmpty())
////					mPositionChunksToCreate.erase(it++);
//				/*else*/ if(acquireChunkData(chunk)) {
//					mPositionChunksToCreate.erase(it++);
//				}
//				else
//					it++;					
//			} else {
//				it++;
//			}
//		}
//	}
//	// -- end
	
	
	
	// -- Rebuild chunks
	//std::cout << "CMup: (b) " << mChunksToRebuild.size() << " to rebuild." << std::endl;
	int chunkRebuild = 0;
	while (!mChunksToRebuild.empty() && chunkRebuild < maxRebuild) {
		Chunk * chunk = mChunksToRebuild.front();
		
		chunkRebuild += (chunk->rebuild()) ? 1 : 0;
		
		mChunksToRebuild.pop();	
	}
//	if (chunkRebuild != 0)
//		std::cout << "CMup: (r) " << chunkRebuild << " rebuilded." << std::endl;
	//std::cout << "CMup: (a) " << mChunksToRebuild.size() << " to rebuild." << std::endl;
	//std::cout << std::endl;
	// -- end
	
	
	
	
//	// -- Unload chunks
//	int chunkUnload = 0;
//	if (mChunksToUnload.size() > 0) {
//		for(ChunkSet::iterator it = mChunksToUnload.begin();
//			it != mChunksToUnload.end() && chunkUnload < maxUnload; 
//			mChunksToUnload.erase(it++), ++chunkUnload) {
			
//			// save to disk
//			// maybe bug : already given back
//			mPersistence.saveChunk(*it);
//			mPool.giveBackChunk(*it);			
			
			
//		}
//		//mChunksToUnload.clear();
//		//std::cout << "CMup: (u) " << chunkUnload << " Unloaded." << std::endl;
//	}
//	// -- end
	
	
	
	
//	// -- Garbage
//	int garbaged = 0;
////	if (mLoadedChunksGarbage > mLoadedChunks.size())
//		mLoadedChunksGarbage = 0;
////	ChunkMap::iterator it = mLoadedChunks.begin();
//	for (int i = 0; i < mLoadedChunksGarbage;++i)
//		++it;
	
//	for(;it != mLoadedChunks.end() && garbaged < 100;++it, ++garbaged) {
		
//		Chunk * chunk = it->second;
		
////		chunk->upEmptyState();
////		if (chunk->isEmpty()) {
//			mDataPool.giveBackChunkData(
//						chunk->invalidData());
//		} else 
//			--garbaged;
//	}
//	mLoadedChunksGarbage += garbaged;
//	// -- end
	
}

void ChunkManager::draw(Renderer &renderer) const
{
	ChunkCoordinate oldPosition;
	
	for  (ChunkVector::const_iterator it = mVisibleChunks.begin();
		  it != mVisibleChunks.end(); ++it) {
		
		const Chunk * chunk = *it;
		const ChunkCoordinate & chunkPosition = chunk->getPosition();
		
		// use oldPosition to compute difference
		// between previous and current chunks
		oldPosition -= chunkPosition;
		
		renderer.translate(
					-oldPosition.x << Chunk::SIZE_DEC,
					-oldPosition.y << Chunk::SIZE_DEC,
					-oldPosition.z << Chunk::SIZE_DEC);
		
		// test
		if (chunkPosition.x < 2)
			chunk->draw(0);
		else if (chunkPosition.x < 6)
			chunk->draw(1);
		else
			chunk->draw(2);
		
		oldPosition = chunkPosition;
	}
}

void ChunkManager::beginGeneration()
{
}

void ChunkManager::genSetBlock(const BlockCoordinate & absoluteBlockPosition, 
								   Block & block)
{
	Chunk * chunk = 0;
	ChunkCoordinate cPosition = getChkPosByAbsBkPos(absoluteBlockPosition);
	if (!mChunks.isThere(cPosition, chunk)) {
		chunk = mChunks.create(cPosition);
		mGeneratedChunks.push_back(chunk);
		chunk->beginSet(false);
	}
	chunk->set(getInsideBkPosByAbsBkPos(cPosition, absoluteBlockPosition), block);
}

void ChunkManager::endGeneration()
{
	for (ChunkVector::iterator it = mGeneratedChunks.begin();
		it != mGeneratedChunks.end(); ++it) {
		
		(*it)->endSet();
		
		mChunksToRebuild.push(*it);
		mVisibleChunks.push_back(*it);
	}
}



bool ChunkManager::isChunkLoaded(const sf::Vector3i &chunkPosition, Chunk* & chunk) const
{
	return mChunks.isThere(chunkPosition, chunk);

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



inline void ChunkManager::rebuildOneNeighbour(const ChunkCoordinate & chunkPosition) {
	Chunk * nearChunk = 0;
	
	if (mChunks.isThere(chunkPosition, nearChunk)) {
		nearChunk->needRebuild();
		mChunksToRebuild.push(nearChunk);
	}
}

void ChunkManager::rebuildNeighbours(const ChunkCoordinate & chunkPosition)
{
	rebuildOneNeighbour(chunkPosition + VectorTools::EXi);
	rebuildOneNeighbour(chunkPosition - VectorTools::EXi);
	rebuildOneNeighbour(chunkPosition + VectorTools::EYi);
	rebuildOneNeighbour(chunkPosition - VectorTools::EYi);
	rebuildOneNeighbour(chunkPosition + VectorTools::EZi);
	rebuildOneNeighbour(chunkPosition - VectorTools::EZi);
	
	// need to rebuild others too (think about torches)
	// ...
}



void ChunkManager::reqLoadChunk(const sf::Vector3i &chunkPosition)
{
	mPositionChunksToLoad.insert(chunkPosition);
}

void ChunkManager::reqRebuildChunk(Chunk* & chunk)
{
	mChunksToRebuild.push(chunk);
}

void ChunkManager::reqUnloadChunk(Chunk* & chunk)
{
	// avoid to use this chunk in computation
//	mLoadedChunks.erase(chunk->getPosition());
//	mChunksToUnload.insert(chunk);
}



ChunkManager::~ChunkManager() {
//	for(ChunkMap::iterator it = mLoadedChunks.begin();
//		it != mLoadedChunks.end(); ++it) {
//		// unload (save to disk)
//		//mPersistence.saveChunk(it->second);		
//		mPool.giveBackChunk(it->second);
	//	}
}


