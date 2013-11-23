#ifndef CHUNKPERSISTENCE_HPP
#define CHUNKPERSISTENCE_HPP

#include <string>
#include <vector>
#include <SFML/System.hpp>

typedef std::vector<sf::Vector3i> PositionVector;

class Chunk;

class ChunkPersistence
{
	public:
		ChunkPersistence();
		
		void setDirectory(const std::string &world_path);
		
		const PositionVector & getExistingPositions();
		
		bool loadChunk(Chunk * chunk);
		
		void saveChunk(Chunk * chunk);
		
		~ChunkPersistence();
		
	private:
		void loadIndex();
		void loadData(Chunk * chunk, const std::string & path);
		
		std::string mDirectory;
		PositionVector mChunkPositions;
};

#endif // CHUNKPERSISTENCE_HPP
