
#include "WorldGenerator.hpp"
#include "ChunkManager.hpp"

#include "procedural/simplextextures.h"
#include "procedural/simplexnoise.h"


#define SIZE Chunk::SIZE

WorldGenerator::WorldGenerator(ChunkManager & manager) : mManager(manager)
{
	
}

void WorldGenerator::init()
{
	BlockCoordinate islandPos(5,4,2);
	BlockCoordinate blkPos;
	
	mManager.beginGeneration();
	
	for (int x=0;x<20;++x) {
		for (int y=0;y<20;++y) {
			for (int z=0;z<20;++z) {
				
				blkPos = islandPos + BlockCoordinate(x,y,z);
				
				float v = octave_noise_3d(1,.5,.9,x/16.0,y/16.0,z/16.0);
				if (v < -.2)
					mManager.genSetBlockType(blkPos, Block::Stone);
				else if (v < 0) {
					if (z > 15)
						mManager.genSetBlockType(blkPos, Block::Dirt);
					else
						mManager.genSetBlockType(blkPos, Block::Stone);
				}
				
			}
		}
	}
	
	mManager.endGeneration();
	
}



