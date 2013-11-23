#include "WorldGenerator.hpp"
#include "ChunkManager.hpp"

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
