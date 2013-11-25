#ifndef CHUNKDATAPOOL_HPP
#define CHUNKDATAPOOL_HPP


#include <list>
#include <stack>
#include <vector>
#include <queue>

//#include "Chunk.hpp"
class Chunk;
class ChunkData;
class ChunkManager;


typedef std::stack<ChunkData*> ChunkDataStack;
typedef std::queue<ChunkData*> ChunkDataQueue;
typedef std::vector<ChunkData*> ChunkDataVector;



class ChunkDataPool
{
	public:
		ChunkDataPool(/*const ChunkManager & manager*/);
		
		ChunkData * getFreeChunkData();
		void giveBackChunkData(ChunkData *chunk);
		
		~ChunkDataPool();
		
	private:
		//ChunkManager & mManager;
		
		
		ChunkDataStack mFreeChunks;
		ChunkDataQueue mUsedChunks;
		ChunkDataVector mPoolChunks;
		
};

#endif // CHUNKDATAPOOL_HPP
