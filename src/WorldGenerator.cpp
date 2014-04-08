#include <cmath>
#include "WorldGenerator.hpp"
#include "Chunk/ChunkManager.hpp"
#include "VectorTools.hpp"

#include "procedural/simplextextures.h"
#include "procedural/simplexnoise.h"

#include "Block/SimpleBlock.hpp"

using namespace std;

#define SIZE Chunk::SIZE

WorldGenerator::WorldGenerator(ChunkManager & manager) : mManager(manager)
{
	
}

WorldGenerator::WorldGenerator(VoxelEngine & voxel) : mManager(voxel.getChunkManager())
{
}



void WorldGenerator::init()
{
	makeBoard(BlockCoordinate(0,0,0));
//	makeIsland(BlockCoordinate(Chunk::SIZE << 1,0,0));
//	makeIsland(BlockCoordinate(Chunk::SIZE << 2,0,0));
//	makeIsland(BlockCoordinate(Chunk::SIZE << 3,0,0));
//	makeIsland(BlockCoordinate(Chunk::SIZE << 4,0,0));
//	makeIsland(BlockCoordinate(Chunk::SIZE << 5,0,0));
}



void WorldGenerator::makeBoard(const BlockCoordinate &boardPos)
{
	BlockCoordinate blkPos;
	const int z = 0;
	
	mManager.beginGeneration();
	
	for (int x=0;x<Chunk::SIZE;++x) {
		for (int y=0;y<Chunk::SIZE;++y) {
				
			blkPos = boardPos + BlockCoordinate(x,y,z);
			
			mManager.genSetBlock(blkPos, *(new SimpleBlock()));
		}
	}
	
	mManager.endGeneration();
}




