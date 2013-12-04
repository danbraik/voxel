#include <cmath>
#include "WorldGenerator.hpp"
#include "ChunkManager.hpp"
#include "VectorTools.hpp"

#include "procedural/simplextextures.h"
#include "procedural/simplexnoise.h"

using namespace std;

#define SIZE Chunk::SIZE

WorldGenerator::WorldGenerator(ChunkManager & manager) : mManager(manager)
{
	
}

void WorldGenerator::init()
{
	
	BlockCoordinate islandPos(5,4,2);
	BlockCoordinate blkPos;
	
	mManager.beginGeneration();
	
	for (int x=0;x<50;++x) {
		for (int y=0;y<50;++y) {
			for (int z=49;z>=0;--z) {
				
				blkPos = islandPos + BlockCoordinate(x,y,z);
				
				
//				float v = octave_noise_3d(5,.15,.80,x/16.0,y/16.0,z/16.0);
//				if (v < -.2)
//					mManager.genSetBlockType(blkPos, Block::Stone);
//				else if (v < 0) {
//					if (z > 15)
//						mManager.genSetBlockType(blkPos, Block::Dirt);
//					else
//						mManager.genSetBlockType(blkPos, Block::Stone);
//				}
				
				float yf = y / 50.;
				float xf = x / 50.;
				float zf = z / 50.;
				float plateau_falloff, center_falloff, density, caves;
								
				if(zf <= 0.8){
					plateau_falloff = .80;
				}
				else if(0.8 < zf && zf < 0.9){
					plateau_falloff = zf-.3;
				}
				else{
					plateau_falloff = 0.0;
				}
		
				center_falloff = (
					pow((xf-0.5)*4., 2) +
					pow((yf-0.5)*4., 2) +
					pow((zf-1)*3.1, 2)
				);
				center_falloff =  1 / sqrt(center_falloff);
				
				//caves = pow( (xf*5, yf*5, zf*5), 3);
				density = (
					octave_noise_3d(2, .5, 1, xf, yf, zf)
					 * center_falloff 
				    * plateau_falloff
				);
				
//				if(caves<0.2){
//					density = 0;
//				}
				
				if (density > .24)
					mManager.genSetBlockType(blkPos, Block::Stone);
				else if (density > .2) {
					if (mManager.getBlockType(blkPos+VectorTools::EZ) < Block::ACTIVATED)
						mManager.genSetBlockType(blkPos, Block::Dirt);
					else
						mManager.genSetBlockType(blkPos, Block::Stone);					
				}
				
			}
		}
	}
	
	mManager.endGeneration();
	
}



