#ifndef CHUNK_HPP
#define CHUNK_HPP

#include "Renderer.hpp"

#define BLOCK_SIZE 1

class Chunk
{
	
		
	public:
		static const int SIZE = 8;
		
		Chunk();
		
		void update(Renderer &renderer);
		void draw(Renderer &renderer);
		
	private:
		MeshId mMeshId;
};

#endif // CHUNK_HPP
