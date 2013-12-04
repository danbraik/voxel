#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include "ChunkManager.hpp"


class WorldGenerator
{
	public:
		WorldGenerator(ChunkManager & manager);
		
		void init();
		
		void makeIsland(const BlockCoordinate & islandPosition);
		
		
	private:
		
		ChunkManager & mManager;
};

#endif // WORLDGENERATOR_HPP
