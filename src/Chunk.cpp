#include <cstdlib>
#include "Chunk.hpp"

Chunk::Chunk() : mMeshId(0)
{
}

void Chunk::init(int h)
{
	if (h < 0) h = 0;
	if (h > SIZE) h = SIZE;
	
	for (int z=0;z<h;++z) {
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			set(sf::Vector3i(x,y,z), Block::Stone);
		}
	}
	}
	
	if (h+1 < SIZE) {
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			if (std::rand() % 5 == 0)
				set(sf::Vector3i(x,y,h), Block::Dirt);
			else
				set(sf::Vector3i(x,y,h), Block::Air);
		}
	}
	
	for (int z=h+1;z<SIZE;++z) {
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			set(sf::Vector3i(x,y,z), Block::Air);
		}
	}
	}
	}
}

void Chunk::update(Renderer & renderer, BlockList & list)
{
	renderer.beginMesh(mMeshId);

	BlockType type;
	sf::Vector3f ux(Block::SIZE,0,0);
	sf::Vector3f uy(0,Block::SIZE,0);
	sf::Vector3f uz(0,0,Block::SIZE);
	
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			for (int z=0;z<SIZE;++z) {
				
				type = get(sf::Vector3i(x,y,z));
				Block block = list.get(type);
				
				if (type==Block::NONE)
					return;
				
				if (block.filled) {
					sf::Vector3f pos(x*Block::SIZE, y*Block::SIZE, z*Block::SIZE);
					
					if (!list.get(get(sf::Vector3i(x,y-1,z))).filled){
					// front
						renderer.addVertexToMesh(pos,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uz,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz,block.r, block.g,block.b);
					}
					if (!list.get(get(sf::Vector3i(x+1,y,z))).filled){	
						// right
						renderer.addVertexToMesh(pos+ux,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uy+uz,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos+ux,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uy+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uz,block.r, block.g,block.b);
					}
					if (!list.get(get(sf::Vector3i(x,y+1,z))).filled){
						// behind
						renderer.addVertexToMesh(pos+ux+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy+uz,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos+ux+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux+uy+uz,block.r, block.g,block.b);
					}
					if (!list.get(get(sf::Vector3i(x-1,y,z))).filled){
						// left
						renderer.addVertexToMesh(pos+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy+uz,block.r, block.g,block.b);
					}
					if (!list.get(get(sf::Vector3i(x,y,z+1))).filled){
						// top
						renderer.addVertexToMesh(pos+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz+ux,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz+ux+uy,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos+uz,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz+ux+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uz+uy,block.r, block.g,block.b);
					}
					if (!list.get(get(sf::Vector3i(x,y,z-1))).filled){
						// bottom
						renderer.addVertexToMesh(pos,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy+ux,block.r, block.g,block.b);
						
						renderer.addVertexToMesh(pos,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+uy+ux,block.r, block.g,block.b);
						renderer.addVertexToMesh(pos+ux,block.r, block.g,block.b);
					}
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

inline BlockType Chunk::get(sf::Vector3i pos)
{
	if (   pos.x >= 0 && pos.x < SIZE 
		&& pos.y >= 0 && pos.y < SIZE
		&& pos.z >= 0 && pos.z < SIZE)
		return mArray[pos.x][pos.y][pos.z];
	return Block::NONE;
}

inline void Chunk::set(sf::Vector3i pos, BlockType type)
{
	if (pos.x >=0&&pos.x<SIZE&&pos.y>=0&&pos.y<SIZE&&pos.z>=0&&pos.z<SIZE)
		mArray[pos.x][pos.y][pos.z] = type;
}
