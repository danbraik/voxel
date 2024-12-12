#include "Chunk3dContainer.hpp"

#define WORLD_SIZE 4096
#define WORLD_OFFSET_X (WORLD_SIZE / 2)
#define WORLD_OFFSET_Y (WORLD_SIZE / 2)
#define WORLD_OFFSET_Z (WORLD_SIZE / 2)


Chunk3dContainer::Chunk3dContainer() : mAllChunks(4096, nullptr), mPool(), mManager(0)
{
}



Chunk * Chunk3dContainer::create(const ChunkCoordinate &position)
{
	Chunk * chunk = mPool.getFreeChunk();
	chunk->reset();
	chunk->setPosition(position);
	chunk->setGlobal(this, mManager);
	chunk->load();
	
	mAllChunks(
        position.x + WORLD_OFFSET_X, 
        position.y + WORLD_OFFSET_Y, 
        position.z + WORLD_OFFSET_Z
    ) = chunk;
	
	return chunk;
}



bool Chunk3dContainer::isThere(const ChunkCoordinate &position, Chunk *&chunk) const
{
	// ChunkMap::const_iterator it = 
	// 			mAllChunks.find(position);
		
	// if (it == mAllChunks.end())
	// 		return false;
		
	// chunk = it->second;
    // std::cout << position.x << ", " << position.y << ", " << position.z << std::endl;
    chunk = mAllChunks.at(
        position.x + WORLD_OFFSET_X, 
        position.y + WORLD_OFFSET_Y, 
        position.z + WORLD_OFFSET_Z
    );
    if (chunk == nullptr)
        return false;
    
	return true;
}

Chunk3dContainer::~Chunk3dContainer()
{
	// for (ChunkMap::iterator it = mAllChunks.begin();
	// 	 it != mAllChunks.end(); ++it) {
	// 	mPool.giveBackChunk(it->second);
	// }
}
