#ifndef CHUNKMANAGER_HPP
#define CHUNKMANAGER_HPP

#include <list>
#include <stack>
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
		void reinit();
		
		Chunk * createEmptyChunk(const sf::Vector3i & chunkPosition);
		
		const Block & getBlock(BlockType type) const;
		const Block & getBlock(const sf::Vector3i & absoluteBlockPosition) const;
		const Block & getRelativeBlock(const sf::Vector3i & fromChunkPosition,
									   const sf::Vector3i & relativeBlockPosition) const;
		
		void setBlockType(const sf::Vector3i & absoluteBlockPosition, BlockType type);
		
		
		void update(); // pseudo asynchronous update
		
		void draw(Renderer & renderer) const;
		
		~ChunkManager();
		
	private:
		

		sf::Vector3i getChkPosByAbsBkPos(const sf::Vector3i & absoluteBlockPosition) const;
		sf::Vector3i getChkPosByRelBkPos(const sf::Vector3i & fromChunkPosition,
										 const sf::Vector3i & relativeBlockPosition) const;
		sf::Vector3i getInsideBkPosByAbsBkPos(const sf::Vector3i & toChunkPosition,
											  const sf::Vector3i & absoluteBlockPosition) const;
		sf::Vector3i getInsideBkPosByRelBkPos(const sf::Vector3i & fromChunkPosition,
											  const sf::Vector3i & toChunkPosition,
											  const sf::Vector3i & relativeBlockPosition) const;
		
		bool isChunkLoaded(const sf::Vector3i & chunkPosition, Chunk* &chunk) const;
		Chunk * getChunk(const sf::Vector3i & chunkPosition) const;
		
		// asynchronous requests
		void reqLoadChunk(const sf::Vector3i & chunkPosition);
		void reqRebuildChunk(Chunk * chunk);
		
		// internal (used to satisfy requests)
		//...
	
		
		
		
		BlockList & mList;
		
		typedef __gnu_cxx::hash_map<const sf::Vector3i, Chunk*, HashConfiguration> ChunkMap;
		ChunkMap mLoadedChunks;
		
		
		typedef std::list<sf::Vector3i> Vec3iList;
		Vec3iList mPositionChunksToLoad;
		
		typedef std::list<Chunk*> ChunkList;
		ChunkList mChunksToRebuild;
		
		// Chunk pool
		Chunk * getFreeChunk();
		void giveBackChunk(Chunk* & chunk);
		typedef std::stack<Chunk*> ChunkStack;
		ChunkStack mFreeChunks;
		
		
		// use it to compute near positions
		const sf::Vector3i EX, EY, EZ;
		
		//tmp
		Renderer & mRenderer;
};

#endif // CHUNKMANAGER_HPP
