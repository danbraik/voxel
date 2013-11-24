#include "WorldGenerator.hpp"
#include "ChunkManager.hpp"
#include <cmath>

#define SIZE Chunk::SIZE

WorldGenerator::WorldGenerator()
{
}



void WorldGenerator::generate(ChunkManager &manager, int w, int l, int h)
{
	manager.init();
	manager.update();
	
	for (int x=0;x<w;++x) {
		for (int y=0;y<l;++y) {
			BlockType type = Block::Stone;
			int z=0;
			for (z=0;z<h/3;++z) {
				manager.setBlockType(sf::Vector3i(x,y,z),type);	
				manager.update();
			}
			type = Block::Dirt;
			for (;z<2*h/3;++z) {
				manager.setBlockType(sf::Vector3i(x,y,z),type);	
			}
			type = Block::Air;
			for (;z<h;++z) {
				manager.setBlockType(sf::Vector3i(x,y,z),type);	
			}
			
			for (;z<Chunk::SIZE;++z){
				manager.setBlockType(sf::Vector3i(x,y,z), 0);	
			}
		}
	}
	
	
}

void WorldGenerator::gen(Chunk *chunk)
{
	const sf::Vector3i & pos = chunk->getPosition();
	int h = (std::sin(pos.x*SIZE)+2) * 6;
	if (h < pos.z*SIZE) // air
		return;
	
	int dirth = h*7/10.;
	
	int z;
	for (z = 0; z < SIZE && z+pos.z*SIZE < dirth;++z ) {
		for(int x=0;x<SIZE;++x)
			for (int y=0;y<SIZE;++y)
				chunk->set(sf::Vector3i(x,y,z), Block::Stone);
	}
	
	for (; z < SIZE && z+pos.z*SIZE < h;++z ) {
		for(int x=0;x<SIZE;++x)
			for (int y=0;y<SIZE;++y)
				chunk->set(sf::Vector3i(x,y,z), Block::Dirt);
	}
	
}
