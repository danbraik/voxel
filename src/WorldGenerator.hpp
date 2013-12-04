#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include "ChunkManager.hpp"


class WorldGenerator
{
	public:
		WorldGenerator(ChunkManager & manager);
		
		void init();
		
		
		
	private:
		
		ChunkManager & mManager;
};

#endif // WORLDGENERATOR_HPP
