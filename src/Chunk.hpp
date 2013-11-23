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
		
		void init();
		
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

#endif // CHUNK_HPP
