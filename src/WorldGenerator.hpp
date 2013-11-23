#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

class ChunkManager;

class WorldGenerator
{
	public:
		WorldGenerator();
		
		void generate(ChunkManager & manager, int w, int l, int h);
};

#endif // WORLDGENERATOR_HPP
