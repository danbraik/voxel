#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include <SFML/System.hpp>

#include "Block.hpp"
#include "ChunkData.hpp"

class LocalChunkSystem;
class ChunkManager;
class ChunkPersistence;

class Chunk
{
	friend class ChunkPersistence;
		
	public:
		static const int SIZE = ChunkData::SIZE;
		static const int SIZE_1 = SIZE - 1;
		static const int SIZE_DEC = ChunkData::SIZE_DEC;
		
		static bool isStrictelyInside(const sf::Vector3i & blockPosition);
		
		Chunk();
		
		void reset();//test
		
		const sf::Vector3i & getPosition() const;
		void setPosition(const sf::Vector3i & position);
		
		void rebuild(const ChunkManager & manager);
		void draw() const;
		
		
		ChunkData * getData();
		// can set data to null
		void setData(ChunkData * data);
		inline void invalidData();
		
		
		BlockType get(const BlockCoordinate & pos) const;
		void set(const sf::Vector3i & pos, BlockType type);
		
		void setModified(bool modified = true);
		bool isModified();
		
		void setCompletelyEmpty(bool empty = true);
		bool isCompletelyEmpty();
		
	private:
		
		sf::Vector3i mPosition;
		ChunkData * mData;
		
		
		bool mIsModified;
		
		bool mIsCompletelyEmpty;	
};



inline BlockType Chunk::get(const BlockCoordinate &pos) const
{
	// or test mIsCompletlyEmpty
	if(mData != 0)
		return mData->get(pos);
	std::cerr << "Chunk.Get : ChunkData is NULL !"<<std::endl;
	return Block::AIR;
}

inline void Chunk::set(const sf::Vector3i & pos, BlockType type)
{
	if(mData != 0)
		mData->set(pos, type);
	else
		std::cerr << "Chunk.set : ChunkData is NULL !"<<std::endl;
}

void Chunk::invalidData()
{
	setData(0);
}



#endif // CHUNK_HPP
