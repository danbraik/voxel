#include <iostream>
#include "ChunkPool.hpp"
#include "ChunkManager.hpp"
#include "ChunkData.hpp"


#define MAX_TOTAL_CHUNKS 50000
#define INIT_CHUNKS 400
//#define DEBUG_POOL

ChunkDataPool::ChunkDataPool(/*const ChunkManager &manager*/) :
	//mManager(const_cast<ChunkManager&>(manager)),
	mFreeChunks(),
	mUsedChunks(),
	mPoolChunks()
{
	// init pool
	for (int i=0;i<INIT_CHUNKS;++i) {
		ChunkData * const chunk = new ChunkData;
		mPoolChunks.push_back(chunk);
		mFreeChunks.push(chunk);
	}
}

ChunkData * ChunkDataPool::getFreeChunkData()
{
	ChunkData * chunk = 0;
	
	if (mFreeChunks.empty()) {
		if (mPoolChunks.size() > MAX_TOTAL_CHUNKS /*limit*/) {
//			if (mUsedChunks.size())
//				mManager.reqUnloadChunk(mUsedChunks.front());
			return 0;
		} // else
		chunk = new ChunkData;
		mPoolChunks.push_back(chunk);
#ifdef DEBUG_POOL
		std::cout << "ChunkDataPool (n) : +1 chunk (=" << mPoolChunks.size() << ")" << std::endl;
#endif
		if (chunk == 0)
			std::cerr << "Error when allocating chunkdata !" << std::endl;
	} else {
		chunk = mFreeChunks.top();
		mFreeChunks.pop();
#ifdef DEBUG_POOL
		std::cout << "ChunkDataPool (n) : " << mFreeChunks.size() << " free chunk(s)" << std::endl;
#endif
	}
	mUsedChunks.push(chunk);
	
	return chunk;
}

void ChunkDataPool::giveBackChunkData(ChunkData * chunk)
{
	if (chunk == 0)
		return;
	if (mUsedChunks.size() == 0)
		std::cerr << "No used chunkdata but you want to give back one" << std::endl;
	mFreeChunks.push(chunk);
	ChunkData * cd = mUsedChunks.front();
	while(mUsedChunks.front() != chunk) {
		mUsedChunks.push(mUsedChunks.front());
		mUsedChunks.pop();
		if (mUsedChunks.front() == cd)
			break;//BIG BUG from garbage
	}
	mUsedChunks.pop();
#ifdef DEBUG_POOL
	std::cout << "ChunkDataPool (d) : " << mFreeChunks.size() << " free chunk(s)" << std::endl;
#endif
}

ChunkDataPool::~ChunkDataPool()
{
	// delete pool
	if (mFreeChunks.size() != mPoolChunks.size())
		std::cerr << "ChunkDataPool, some chunk were not given back !" << std::endl;
	ChunkData * chunk;
	while (!mFreeChunks.empty()) {
		chunk = mFreeChunks.top();
		mFreeChunks.pop();
		delete chunk;
	}
}
