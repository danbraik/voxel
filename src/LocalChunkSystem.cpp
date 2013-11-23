#include "LocalChunkSystem.hpp"
#include "ChunkManager.hpp"

LocalChunkSystem::LocalChunkSystem(const ChunkManager &manager, 
								   const sf::Vector3i &chunkPosition) :
	mManager(manager)
{
	
}

const Block &LocalChunkSystem::getBlock(BlockType type) const
{
	return mManager.getBlock(type);
}

const Block &LocalChunkSystem::getBlock(const sf::Vector3i &absoluteBlockPosition) const
{
	return mManager.getBlock(absoluteBlockPosition);
}

const Block &LocalChunkSystem::getRelativeBlock(const sf::Vector3i &fromChunkPosition,
												const sf::Vector3i &relativeBlockPosition) const
{
	mManager.getRelativeBlock(fromChunkPosition, relativeBlockPosition);
}
