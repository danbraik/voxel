#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <SFML/System.hpp>

#include "Renderer.hpp"
#include "Block.hpp"

class ChunkManager;

class Chunk
{
	
		
	public:
		static const int SIZE = 16;
		static const float fSIZE = 16.f;
		
		Chunk();
		
		
		void init(int h);
		
		void update(Renderer &renderer, const ChunkManager & manager);
		void draw(Renderer &renderer);
		
		BlockType get(sf::Vector3i pos);
		void set(const sf::Vector3i &pos, BlockType type);
		
	private:
		void computeOneBlock(Renderer & renderer, const ChunkManager &manager, int x, int y, 
							 int z, sf::Vector3f ux, sf::Vector3f uy, sf::Vector3f uz);
		
		
		MeshId mMeshId;
		
		BlockType mArray[SIZE][SIZE][SIZE]; 
};

#endif // CHUNK_HPP
