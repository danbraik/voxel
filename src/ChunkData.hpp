#ifndef CHUNKDATA_HPP
#define CHUNKDATA_HPP

#include <vector>

#include "Mesh.hpp"
#include "Block.hpp"

typedef std::vector<MeshFloat> MeshFloatVector;

class ChunkManager;
class LocalChunkSystem;
class ChunkPersistence;

class ChunkData
{
	friend class ChunkPersistence;
		
	public:
		// must be a power of 2
		static const int SIZE = 35;
		static const int SIZE_DEC = 5;
	
		ChunkData();
		
		// Filled with AIR blocks
		void reset();
		
		// Recompute mesh
		void rebuild(const LocalChunkSystem & lcs);
		const Mesh & getMesh() const;
		
		BlockType get(const BlockCoordinate & pos) const;
		void set(const BlockCoordinate & pos, BlockType type);
		
		bool upIsCompletelyEmpty();
		
	private:
		void computeOneBlock(MeshFloatVector & data, 
							 int & vertexCount, 
							 const LocalChunkSystem & manager,
							 int x, int y, int z, 
							 const sf::Vector3f &ux,
							 const sf::Vector3f &uy, 
							 const sf::Vector3f &uz);
		
		Mesh mMesh;
		BlockType mArray[SIZE][SIZE][SIZE]; 
};



inline BlockType ChunkData::get(const BlockCoordinate &pos) const
{
	if (   pos.x >= 0 && pos.x < SIZE 
		&& pos.y >= 0 && pos.y < SIZE
		&& pos.z >= 0 && pos.z < SIZE)
		return mArray[pos.x][pos.y][pos.z];
	std::cerr << "ChunkData : wanted to read invalid block pos at ("
			  << pos.x<<" "<<pos.y<<" "<<pos.z<<")"<<std::endl;
				 
	return Block::AIR;
}

inline void ChunkData::set(const BlockCoordinate & pos, BlockType type)
{
	if (pos.x >=0&&pos.x<SIZE&&pos.y>=0&&pos.y<SIZE&&pos.z>=0&&pos.z<SIZE)
		mArray[pos.x][pos.y][pos.z] = type;
	else
		std::cerr << "ChunkData : wanted to set invalid block pos at ("
				  << pos.x<<" "<<pos.y<<" "<<pos.z<<")"<<std::endl;
	
}



#endif // CHUNKDATA_HPP
