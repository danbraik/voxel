#ifndef LOCALCHUNKSYSTEM_HPP
#define LOCALCHUNKSYSTEM_HPP

#include "Block.hpp"
class ChunkManager;

class LocalChunkSystem
{
	public:
		LocalChunkSystem(const ChunkManager & manager, const sf::Vector3i &  chunkPosition);
		
		const Block & getBlock(BlockType type) const;
		const Block & getBlock(const sf::Vector3i & absoluteBlockPosition) const;
		const Block & getRelativeBlock(const sf::Vector3i & fromChunkPosition,
									   const sf::Vector3i & relativeBlockPosition) const;
		
	private:
		
		const ChunkManager & mManager;
};

#endif // LOCALCHUNKSYSTEM_HPP
