#ifndef LOCALCHUNKSYSTEM_HPP
#define LOCALCHUNKSYSTEM_HPP

#include "Chunk.hpp"
class ChunkManager;

class LocalChunkSystem
{
	public:
		LocalChunkSystem(const ChunkManager & manager, 
						 const Chunk * chunk);
		
		const Block & getBlock(BlockType type) const;
		//const Block & getBlock(const sf::Vector3i & absoluteBlockPosition) const;
		const Block & getRelativeBlock(const sf::Vector3i & relativeBlockPosition) const;
		
	private:
		const Block & getInsideChunk(const Chunk * chunk, 
									 const sf::Vector3i & insideBlockPosition) const;
		
		const ChunkManager & mManager;
		const Chunk * c, * cx, * cmx, * cy, * cmy, * cz, * cmz, 
			* cxy, * cmxy, * cmxmy, * cxmy,
			* cxyz, * cmxyz, * cmxmyz, * cxmyz, 
			* cxymz, * cmxymz, * cmxmymz, * cxmymz,
			* cxz, * cxmz, * cyz, * cymz, * cmxz, * cmxmz, * cmyz, * cmymz;
};

#endif // LOCALCHUNKSYSTEM_HPP
