#include "Chunk3dContainer.hpp"

Chunk3dContainer::Chunk3dContainer() : mAllChunks()
{
}

Chunk * Chunk3dContainer::create(const ChunkCoordinate &position)
{
	// TODO : use pool
	Chunk * chunk = new Chunk;
	chunk->reset();
	chunk->setPosition(position);
	chunk->setGlobal(this, mManager);
	
	mAllChunks[position] = chunk;
	
	return chunk;
}

Chunk * Chunk3dContainer::get(const ChunkCoordinate &position) const
{
	return mAllChunks.find(position)->second;
}

bool Chunk3dContainer::isThere(const ChunkCoordinate &position, Chunk *&chunk) const
{
	ChunkMap::const_iterator it = 
				mAllChunks.find(position);
		
	if (it == mAllChunks.end())
			return false;
		
	chunk = it->second;
	return true;
}
