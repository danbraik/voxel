#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include <SFML/System.hpp>

#include "Block.hpp"
#include "ChunkData.hpp"

class LocalChunkSystem;
class ChunkManager;
class ChunkPersistence;
class Chunk3dContainer;

struct HashChunkCoordinate {
   size_t operator()(const ChunkCoordinate & v) const {
	   return v.x + 256*v.y+ 256*256*v.z;
   }
};

class Chunk
{
	friend class ChunkPersistence;
	friend class Chunk3dContainer;
		
	public:
		static const int SIZE = ChunkData::SIZE;
		static const int SIZE_1 = SIZE - 1;
		static const int SIZE_DEC = ChunkData::SIZE_DEC;
		
		static bool isStrictelyInside(const sf::Vector3i & blockPosition);
		
		Chunk();
		
		void reset();//test
		
		const ChunkCoordinate & getPosition() const;
		
		void rebuild();
		void draw() const;
		
		void load();
		void unload();
		
		// player action = is the player has modified the block
		// or maybe it is the world generator (with player = false)
		void beginSet(bool playerAction = false);
		void set(const BlockCoordinate & bpos, BlockType type);
		void endSet();
		
		BlockType get(const BlockCoordinate & pos) const;
		
		// usually used after player action
		void setOne(const BlockCoordinate & pos, BlockType type);
		
		bool isFilled();
	private:
		
		bool mIsValid;
		
		void setPosition(const ChunkCoordinate &position);
		void setGlobal(Chunk3dContainer * container,
					   ChunkManager * manager) {
			mContainer = container;
			mManager = manager;
		}
		
		
		bool hasData() const {
			return mData != 0;
		}
		ChunkData * getData() {
			return mData;
		}
		
		void setModified(bool s){
			mIsModified = s;
		}
		bool isModified(){return mIsModified;}
		 
		ChunkCoordinate mPosition;
		ChunkData * mData;
		
		
		bool mIsModified;
		bool mIsEmpty;
		
		Chunk3dContainer * mContainer;
		ChunkManager * mManager;
		
		
};



inline BlockType Chunk::get(const BlockCoordinate &pos) const
{
	if(hasData())
		return mData->get(pos);
	//std::cerr << "Chunk.Get : ChunkData is NULL !"<<std::endl;
	return Block::AIR;
}



inline void Chunk::set(const BlockCoordinate & pos, BlockType type)
{

	mData->set(pos, type);
	if (type > Block::ACTIVATED)
		mIsEmpty = false;
	
	//	std::cerr << "Chunk.set : ChunkData is NULL !"<<std::endl;
}






#endif // CHUNK_HPP
