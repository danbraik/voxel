#ifndef CHUNKDATA_HPP
#define CHUNKDATA_HPP

#include <vector>

#include "../Render/Mesh.hpp"
#include "../Block/Block.hpp"
#include "../Block/BlockList.hpp"

typedef std::vector<MeshFloat> MeshFloatVector;

class ChunkManager;
class LocalChunkSystem;
class ChunkPersistence;

class ChunkData
{
	friend class ChunkPersistence;
		
	public:
		// must be a power of 2
		static const int SIZE = 32;
		static const int SIZE_DEC = 5;
	
		ChunkData();
		
		// Filled with NoBlock
		void reset();
		
		// Recompute mesh
		void rebuild(const LocalChunkSystem & lcs);
		const Mesh & getMesh() const;
		
		Block & get(const BlockCoordinate & pos);
		const Block & get(const BlockCoordinate & pos) const;
		
		void set(const BlockCoordinate & pos, Block & block);
		
	private:
		void computeOneBlock(MeshFloatVector & data, 
							 int & vertexCount, 
							 const LocalChunkSystem & manager,
							 int x, int y, int z, 
							 const sf::Vector3f &ux,
							 const sf::Vector3f &uy, 
							 const sf::Vector3f &uz);
		
		Mesh mMesh;
		Block * mArray[SIZE][SIZE][SIZE]; 
};



inline Block & ChunkData::get(const BlockCoordinate &pos)
{
	if (   pos.x >= 0 && pos.x < SIZE 
		&& pos.y >= 0 && pos.y < SIZE
		&& pos.z >= 0 && pos.z < SIZE) {
	
		// test null ptr
		if (mArray[pos.x][pos.y][pos.z] != 0)
			return *mArray[pos.x][pos.y][pos.z];
		else {
//			std::cerr << "ChunkData : read NULL block at ("
//					  << pos.x<<" "<<pos.y<<" "<<pos.z<<")"<<std::endl;
			return BlockList::NO_BLOCK;
		}
	}
	
	std::cerr << "ChunkData : wanted to read block at invalid position ("
			  << pos.x<<" "<<pos.y<<" "<<pos.z<<")"<<std::endl;
				 
	return BlockList::NO_BLOCK;
}


inline const Block & ChunkData::get(const BlockCoordinate &pos) const
{
	return get(pos);
}

inline void ChunkData::set(const BlockCoordinate & pos, Block & block)
{
	if (pos.x >=0&&pos.x<SIZE&&pos.y>=0&&pos.y<SIZE&&pos.z>=0&&pos.z<SIZE)
		mArray[pos.x][pos.y][pos.z] = &block; // store address
	else
		std::cerr << "ChunkData : wanted to SET block at invalid position ("
				  << pos.x<<" "<<pos.y<<" "<<pos.z<<")"<<std::endl;
	
}



#endif // CHUNKDATA_HPP
