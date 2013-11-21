#ifndef CHUNKMANAGER_HPP
#define CHUNKMANAGER_HPP

#define _GLIBCXX_PERMIT_BACKWARD_HASH 0
#include <hash_map>
#include "Chunk.hpp"


struct HashConfiguration{
   size_t operator()(const sf::Vector3i & v) const {
	   return v.x + 256*v.y+ 256*256*v.z;
   }
};


class ChunkManager
{
	public:
		ChunkManager(BlockList & list);
		
		void init(Renderer &renderer);
		
		const Block & getBlock(BlockType type) const;
		const Block & getBlock(sf::Vector3i pos) const;
		const Block & getRelativeBlock(sf::Vector3i blockPosition) const;
		
		void draw(Renderer & renderer) const;
		
	private:
		bool isChunkLoaded(const sf::Vector3i & chunkPosition) const;
		Chunk * getChunk(const sf::Vector3i & chunkPosition) const;
	
		sf::Vector3i mCurrentPositionChunk;
		
		BlockList & mList;
		
		typedef __gnu_cxx::hash_map<const sf::Vector3i, Chunk*, HashConfiguration> LoadedChunkMap;
		LoadedChunkMap mLoadedChunks;
};

#endif // CHUNKMANAGER_HPP
