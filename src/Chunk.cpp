#include <cstdlib>
#include "Chunk.hpp"

Chunk::Chunk() : mMeshId(0)
{
}

void Chunk::update(Renderer & renderer)
{
	renderer.beginMesh(mMeshId);

	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			for (int z=0;z<SIZE;++z) {
				
				if (std::rand() % 5 == 0) {
					renderer.addVertexToMesh(x*BLOCK_SIZE,
											 y*BLOCK_SIZE,
											 z*BLOCK_SIZE,1,1,1);
					renderer.addVertexToMesh((x+1)*BLOCK_SIZE,
											 y*BLOCK_SIZE,
											 z*BLOCK_SIZE,1,0,1);
					renderer.addVertexToMesh(x*BLOCK_SIZE,
											 (y)*BLOCK_SIZE,
											 (z+1)*BLOCK_SIZE,0,1,0);
				}
			}
		}
	}	
	
	
	renderer.endMesh();
}

void Chunk::draw(Renderer & renderer)
{
	renderer.drawMesh(mMeshId);
}
