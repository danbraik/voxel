#include <iostream>
#include "ChunkPool.hpp"
#include "ChunkManager.hpp"


#define MAX_TOTAL_CHUNKS 500000
#define INIT_CHUNKS 400000
//#define DEBUG_POOL

ChunkPool::ChunkPool(const ChunkManager &manager) :
	mManager(const_cast<ChunkManager&>(manager)),
	mFreeChunks(),
	mUsedChunks(),
	mPoolChunks()
{
	// init pool
	for (int i=0;i<INIT_CHUNKS;++i) {
		Chunk * const chunk = new Chunk;
		mPoolChunks.push_back(chunk);
		mFreeChunks.push(chunk);
	}
}

Chunk *ChunkPool::getFreeChunk()
{
	Chunk * chunk = 0;
	
	if (mFreeChunks.empty()) {
		if (mPoolChunks.size() > MAX_TOTAL_CHUNKS /*limit*/) {
			if (mUsedChunks.size())
				mManager.reqUnloadChunk(mUsedChunks.front());
			return 0;
		} // else
		chunk = new Chunk;
		mPoolChunks.push_back(chunk);
#ifdef DEBUG_POOL
		std::cout << "ChunkPool (n) : +1 chunk (=" << mPoolChunks.size() << ")" << std::endl;
#endif
		if (chunk == 0)
			std::cerr << "Error when allocating chunk !" << std::endl;
	} else {
		chunk = mFreeChunks.top();
		mFreeChunks.pop();
#ifdef DEBUG_POOL
		std::cout << "ChunkPool (n) : " << mFreeChunks.size() << " free chunk(s)" << std::endl;
#endif
	}
	mUsedChunks.push(chunk);
	
	return chunk;
}

void ChunkPool::giveBackChunk(Chunk * chunk)
{
	if (mUsedChunks.size() == 0)
		std::cerr << "No used chunk but you want to give back one" << std::endl;
	mFreeChunks.push(chunk);
	while(mUsedChunks.front() != chunk) {
		mUsedChunks.push(mUsedChunks.front());
		mUsedChunks.pop();
	}
	mUsedChunks.pop();
#ifdef DEBUG_POOL
	std::cout << "ChunkPool (d) : " << mFreeChunks.size() << " free chunk(s)" << std::endl;
#endif
}

ChunkPool::~ChunkPool()
{
	// delete pool
	if (mFreeChunks.size() != mPoolChunks.size())
		std::cerr << "ChunkPool, some chunk were not given back !" << std::endl;
	Chunk * chunk;
	while (!mFreeChunks.empty()) {
		chunk = mFreeChunks.top();
		mFreeChunks.pop();
		delete chunk;
	}
}
