#ifndef CHUNKMANAGER_HPP
#define CHUNKMANAGER_HPP

#include <list>
#include <stack>
#include <vector>
#include <queue>
#define _GLIBCXX_PERMIT_BACKWARD_HASH 0
#include <hash_map>
#include <hash_set>
#include "Chunk.hpp"
#include "ChunkPool.hpp"
#include "ChunkDataPool.hpp"
#include "ChunkPersistence.hpp"
#include "WorldGenerator.hpp"

struct HashConfiguration{
   size_t operator()(const sf::Vector3i & v) const {
	   return v.x + 256*v.y+ 256*256*v.z;
   }
};

struct HashChunkPtr{
   size_t operator()(Chunk*const& c) const {
	   return (long)c;
   }
};


class ChunkManager
{
	public:
		
		ChunkManager(const BlockList & list, ChunkPersistence & persistence);
		
		// tests
		void init();
		void reinit();
		void deleteChunk(sf::Vector3i & absBkPos);
		void loadChunk(const sf::Vector3i & absBkPos);
		void visible(const sf::Vector3i & absBkPos);
		void resetChunk(const sf::Vector3i & absBkPos);
		
		
		
		const Block & getBlock(BlockType type) const;
		const Block & getBlock(const sf::Vector3i & absoluteBlockPosition) const;
		BlockType getBlockType(const sf::Vector3i & absoluteBlockPosition) const;
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
		
		// test if chunk is loaded. the result is stored at the same time
		bool isChunkLoaded(const sf::Vector3i & chunkPosition, Chunk* &chunk) const;
		bool isChunkLoaded(const sf::Vector3i & chunkPosition, const Chunk* &chunk) const;
		
		bool acquireChunk(Chunk *& chunk, const ChunkCoordinate & chunkPosition);
		void releaseChunk(Chunk * chunk);
		bool acquireChunkData(Chunk * chunk);
		
		
		Chunk * getChunk(const sf::Vector3i & chunkPosition) const;
		
		void rebuildWithNeighbours(Chunk* chunk, const sf::Vector3i & chunkPosition);
		
		// asynchronous requests
		void reqLoadChunk(const sf::Vector3i & chunkPosition);
		void reqRebuildChunk(Chunk* & chunk);
		void reqUnloadChunk(Chunk* & chunk);
		
		
		// internal (used to satisfy requests)
		//...
		
		friend class LocalChunkSystem;
		friend class ChunkPool;
		
		typedef __gnu_cxx::hash_map<const sf::Vector3i, Chunk*, HashConfiguration> ChunkMap;
		typedef __gnu_cxx::hash_set<Chunk*, HashChunkPtr> ChunkSet;
		typedef std::list<sf::Vector3i> Vec3iList;
		typedef __gnu_cxx::hash_set<sf::Vector3i, HashConfiguration> PositionSet;
		typedef std::list<Chunk*> ChunkList;
		
		// Dictionnary of blocks
		const BlockList & mList;
		
		// All chunks
		ChunkMap mLoadedChunks;
		
		// Task lists
		PositionSet mPositionChunksToLoad;
		ChunkSet mChunksToRebuild;
		ChunkSet mChunksToUnload;
		
		// Pool : (de)allocate chunk
		ChunkPool mPool;
		ChunkDataPool mDataPool;
		
		// Save to and load from disk
		ChunkPersistence & mPersistence;
		
		
		// test
		WorldGenerator mWorldGen;
		
};

#endif // CHUNKMANAGER_HPP
