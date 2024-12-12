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
	makeIsland(BlockCoordinate(Chunk::SIZE, 0,0));
    makeIsland(BlockCoordinate(Chunk::SIZE, Chunk::SIZE,0));
    
    makeIsland(BlockCoordinate(Chunk::SIZE*3, Chunk::SIZE,0));
    makeIsland(BlockCoordinate(Chunk::SIZE*4, 0,0));
    
    makeIsland(BlockCoordinate(Chunk::SIZE*3, Chunk::SIZE*4,0));
    makeIsland(BlockCoordinate(Chunk::SIZE*2, Chunk::SIZE*6,0));
    
    for (int x=0;x<4;++x) {
		for (int y=0;y<4;++y) {
            makeIsland(BlockCoordinate(Chunk::SIZE*x, Chunk::SIZE*y,0));
        }
    }
    
	// makeIsland(BlockCoordinate(Chunk::SIZE << 2,0,0));
	// makeIsland(BlockCoordinate(Chunk::SIZE << 3,0,0));
	// makeIsland(BlockCoordinate(Chunk::SIZE << 4,0,0));
	// makeIsland(BlockCoordinate(Chunk::SIZE << 5,0,0));
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



void WorldGenerator::makeIsland(const BlockCoordinate &boardPos)
{
	BlockCoordinate blkPos;
		
	mManager.beginGeneration();
	
    //mManager.genSetBlock(boardPos + BlockCoordinate(0,0,0), *(new SimpleBlock(1,0,0)));
    //mManager.genSetBlock(boardPos + BlockCoordinate(0,Chunk::SIZE-1,0), *(new SimpleBlock(1,0.5,0)));
    
	for (int x=0;x<Chunk::SIZE;++x) {
		for (int y=0;y<Chunk::SIZE;++y) {
            for (int z=0;z<Chunk::SIZE;++z) {
				
			    blkPos = boardPos + BlockCoordinate(x,y,z);
                
                float r,g,b, v;
                float scale = 0.052 , scalec = 1;
                 v = octave_noise_3d(2, 0.01, scale, 
                    (blkPos.x )/scalec, 
                    (blkPos.y )/scalec, 
                    (blkPos.z )/scalec
                    );
                
                // v = octave_noise_3d(5,.15,.80,x/16.0,y/16.0,z/16.0);
                
                // if (v < -0.5)
                //      continue;
                
                // if (v < -.2)
                //     r=g=b=0.5;
                // else if (v < 0) {
                //     if (z > 15) {
                //         r=b=0;
                //         g=1;
                //     }
                //     else
                //         r=g=b=0.5;
                //     }

                
                if (v < 0.5)
                    continue;
                
                
                if (v < 0.6 && (z > 16)) {
                    r=b=0;
                    g=1;
                } else {
                    r=g=b=0.5;
                    
                }
                
			    mManager.genSetBlock(blkPos, *(new SimpleBlock(
                    r, g, b
                )));
            }
		}
	}
	
	mManager.endGeneration();
}



