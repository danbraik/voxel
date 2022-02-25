#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include "Chunk/ChunkManager.hpp"
#include "VoxelEngine.hpp"

class WorldGenerator
{
	public:
		WorldGenerator(ChunkManager & manager);
		WorldGenerator(VoxelEngine & manager);
		
		void init();
		
		void makeBoard(const BlockCoordinate &boardPos);
        void makeIsland(const BlockCoordinate &boardPos);
		
		
	private:
		
		ChunkManager & mManager;
};

#endif // WORLDGENERATOR_HPP
