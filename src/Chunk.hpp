#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include <SFML/System.hpp>

#include "Renderer.hpp"
#include "Block.hpp"
#include "Mesh.hpp"

class LocalChunkSystem;
class ChunkManager;

class Chunk
{
	
		
	public:
		static const int SIZE = 8;
		static const int SIZE_1 = SIZE - 1;
		
		static bool isStrictelyInside(const sf::Vector3i & blockPosition);
		
		Chunk();
		
		void init();//test
		
		const sf::Vector3i & getPosition() const;
		void setPosition(const sf::Vector3i & position);
		
		void rebuild(const ChunkManager & manager);
		void draw() const;
		
		BlockType get(const sf::Vector3i & pos) const;
		void set(const sf::Vector3i & pos, BlockType type);
		
	private:
		void computeOneBlock(std::vector<MeshFloat> & data, 
							 int &vertexCount, 
							 const LocalChunkSystem & manager,
							 int x, int y, int z, 
							 const sf::Vector3f &ux,
							 const sf::Vector3f &uy, 
							 const sf::Vector3f &uz);
		
		sf::Vector3i mPosition;
		
		Mesh mMesh;
		
		BlockType mArray[SIZE][SIZE][SIZE]; 
};



inline BlockType Chunk::get(const sf::Vector3i &pos) const
{
	if (   pos.x >= 0 && pos.x < SIZE 
		&& pos.y >= 0 && pos.y < SIZE
		&& pos.z >= 0 && pos.z < SIZE)
		return mArray[pos.x][pos.y][pos.z];
	return Block::NONE;
}

inline void Chunk::set(const sf::Vector3i & pos, BlockType type)
{
	if (pos.x >=0&&pos.x<SIZE&&pos.y>=0&&pos.y<SIZE&&pos.z>=0&&pos.z<SIZE)
		mArray[pos.x][pos.y][pos.z] = type;
}

#endif // CHUNK_HPP
