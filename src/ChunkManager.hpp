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
		ChunkManager(BlockList & list, Renderer & renderer);
		
		void init();
		
		const Block & getBlock(BlockType type) const;
		const Block & getBlock(const sf::Vector3i & absoluteBlockPosition) const;
		const Block & getRelativeBlock(const sf::Vector3i &relativeBlockPosition) const;
		
		void setBlockType(const sf::Vector3i & absoluteBlockPosition, BlockType type);
		
		void draw(Renderer & renderer) const;
		
	private:
		void update(const sf::Vector3i & chunkPosition, Chunk * chunk);

		sf::Vector3i getChkPosByAbsBkPos(const sf::Vector3i & absoluteBlockPosition) const;
		sf::Vector3i getChkPosByRelBkPos(const sf::Vector3i & fromChunkPosition,
										 const sf::Vector3i & relativeBlockPosition) const;
		sf::Vector3i getInsideBkPosByAbsBkPos(const sf::Vector3i & toChunkPosition,
											  const sf::Vector3i & absoluteBlockPosition) const;
		sf::Vector3i getInsideBkPosByRelBkPos(const sf::Vector3i & fromChunkPosition,
											  const sf::Vector3i & toChunkPosition,
											  const sf::Vector3i & relativeBlockPosition) const;
		
		bool isChunkLoaded(const sf::Vector3i & chunkPosition) const;
		Chunk * getChunk(const sf::Vector3i & chunkPosition) const;
		void loadChunk(const sf::Vector3i & chunkPosition);
	
		sf::Vector3i mCurrentPositionChunk;
		
		BlockList & mList;
		
		typedef __gnu_cxx::hash_map<const sf::Vector3i, Chunk*, HashConfiguration> LoadedChunkMap;
		LoadedChunkMap mLoadedChunks;
		
		
		//tmp
		Renderer & mRenderer;
};

#endif // CHUNKMANAGER_HPP
