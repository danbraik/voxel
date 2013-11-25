#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

class Chunk;
class ChunkManager;

class WorldGenerator
{
	public:
		WorldGenerator();
		
		void generate(ChunkManager & manager, int w, int l, int h);
		void gen(Chunk * chunk);
		bool willBeEmpty(Chunk * chunk);
};

#endif // WORLDGENERATOR_HPP
