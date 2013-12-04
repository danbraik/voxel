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
#include "Chunk3dContainer.hpp"

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
	friend class Chunk;
		
	public:
		
		ChunkManager(const BlockList & list, ChunkPersistence & persistence);
		
		// tests
		void init();
		void reinit();
		void deleteChunk(BlockCoordinate &absBkPos);
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
		
		
		void beginGeneration();
		void genSetBlockType(const BlockCoordinate & absoluteBlockPosition, BlockType type);
		
		void endGeneration();
		
		
		~ChunkManager();
		
		
	private:	
		
		void loadChunk(Chunk * chunk) const;
		
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
		
		void notifVisibleZone(const ChunkCoordinate & position);
		
		Chunk * getChunk(const sf::Vector3i & chunkPosition) const;
		
		
		void rebuildWithNeighbours(Chunk *chunk, const ChunkCoordinate &chunkPosition);
		void loadAndRebuildNeighbours(Chunk* chunk, const ChunkCoordinate & chunkPosition);
		void loadAndRebuildOneNeighbour(const ChunkCoordinate & chunkPosition,
										Chunk *&nearChunk);
		
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
		Chunk3dContainer mChunks;
		int mLoadedChunksGarbage;
		
		// Task lists
		PositionSet mPositionChunksToLoad;
		PositionSet mPositionChunksToCreate;
		ChunkSet mChunksToRebuild;
		ChunkSet mChunksToUnload;
		
		// other
		ChunkList mVisibleChunks;
		ChunkVector mGeneratedChunks;
		
		// Pool : (de)allocate chunk
		ChunkPool mPool;
		ChunkDataPool mDataPool;
		
		// Save to and load from disk
		ChunkPersistence & mPersistence;
		
		
		
};

#endif // CHUNKMANAGER_HPP
