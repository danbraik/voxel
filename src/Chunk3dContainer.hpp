#ifndef CHUNK3DCONTAINER_HPP
#define CHUNK3DCONTAINER_HPP



#define _GLIBCXX_PERMIT_BACKWARD_HASH 0
#include <hash_map>

#include "Chunk.hpp"
class Chunk;

class Chunk3dContainer
{
	friend class ChunkManager;
		
	public:
		Chunk3dContainer();
		
		Chunk * create(const ChunkCoordinate & position);
	
		Chunk * get(const ChunkCoordinate & position) const;
		
		bool isThere(const ChunkCoordinate & position, Chunk *& chunk) const;
		
	private:
		
		void setGlobal(ChunkManager * manager) {
			mManager = manager;
		}
				
		typedef __gnu_cxx::hash_map<const ChunkCoordinate, 
									Chunk*, 
									HashChunkCoordinate> ChunkMap;
		
		ChunkMap mAllChunks;
			
		
		ChunkManager * mManager;
		
		
};

#endif // CHUNK3DCONTAINER_HPP
