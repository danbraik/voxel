#ifndef CHUNKPERSISTENCE_HPP
#define CHUNKPERSISTENCE_HPP

#include <string>
#include <vector>
#include <SFML/System.hpp>

#include "Chunk.hpp"

typedef std::vector<sf::Vector3i> PositionVector;

class Chunk;

class ChunkPersistence;

class ChunkPersistenceCache {
		friend class ChunkPersistence;
	private:
		bool mIsValid;
		ChunkCoordinate mPos;
};

class ChunkPersistence
{
	public:
		ChunkPersistence();
		
		void setDirectory(const std::string &world_path);
		
		const PositionVector & getExistingPositions();
		
		bool isIndexed(const ChunkCoordinate & pos, ChunkPersistenceCache & cache);
		
		bool loadChunk(Chunk * chunk);
		bool loadChunk(Chunk * chunk, const ChunkPersistenceCache & cache);
		
		void saveChunk(Chunk * chunk);
		
		~ChunkPersistence();
		
	private:
		void loadIndex();
		void loadData(Chunk * chunk, const std::string & path);
		
		std::string mDirectory;
		PositionVector mChunkPositions;
};

#endif // CHUNKPERSISTENCE_HPP
