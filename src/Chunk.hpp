#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include <SFML/System.hpp>

#include "Renderer.hpp"
#include "Block.hpp"
#include "Mesh.hpp"

class ChunkManager;

class Chunk
{
	
		
	public:
		static const int SIZE = 8;
		
		Chunk();
		
		void init();
		
		const sf::Vector3i & getPosition() const;
		void setPosition(const sf::Vector3i & position);
		
		void rebuild(const ChunkManager & manager);
		void draw() const;
		
		BlockType get(sf::Vector3i pos);
		void set(const sf::Vector3i &pos, BlockType type);
		
	private:
		void computeOneBlock(std::vector<MeshFloat> & data, int &vertexCount, const ChunkManager &manager, int x, int y
					, int z, sf::Vector3f ux, sf::Vector3f uy, sf::Vector3f uz);
		
		sf::Vector3i mPosition;
		
		Mesh mMesh;
		
		BlockType mArray[SIZE][SIZE][SIZE]; 
};

#endif // CHUNK_HPP
