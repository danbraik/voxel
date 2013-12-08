#include "ChunkData.hpp"
#include "LocalChunkSystem.hpp"
#include "../VectorTools.hpp"

#include <cstring>

#define MAX_DETAIL Mesh::MAX_DETAIL

ChunkData::ChunkData() : mMesh(), mArray()
{
	reset();
}

void ChunkData::reset()
{
	// set to NULL
	// or set reference to NO_BLOCK
	memset(mArray, 0, Chunk::SIZE*Chunk::SIZE*Chunk::SIZE*sizeof(Block*));
}


const Mesh & ChunkData::getMesh() const
{
	return mMesh;
}


// ** rebuild **

void ChunkData::rebuild(const LocalChunkSystem & local)
{
	MeshFloatVector data[MAX_DETAIL];
	int vertexCount[Mesh::MAX_DETAIL];
	
	// 6144 is reserved by vector
	// average 4000 floats
	for(int i = 0; i < Mesh::MAX_DETAIL; ++i) {
		data[i].reserve(SIZE*SIZE*SIZE*12 >> (i));
		vertexCount[i] = 0;
	}
	
	const sf::Vector3f ux(1,0,0);
	const sf::Vector3f uy(0,1,0);
	const sf::Vector3f uz(0,0,1);
		
	// ** DETAIL 0 **
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			for (int z=0;z<SIZE;++z) {
				computeOneBlock(data[0], vertexCount[0], local, x, y, z, ux, uy, uz);
			}
		}
	}
	// end detail 0
	
	
	
	//std::cout << "Capacity " << data.size() << " / " << SIZE*SIZE*SIZE*12 << "; capacit " << data.capacity() <<  std::endl;
	for (int i=0;i<MAX_DETAIL;++i)
// TMP : set same data for all level
// replace data[i] with data[0] and vertC[i] / vertC[0]
		mMesh.setData(data[0].data(), vertexCount[0], i);
}






inline const Block & getBlock(const LocalChunkSystem &manager, const BlockCoordinate & bc) {
	return manager.getRelativeBlock(bc);
}

inline void ChunkData::computeOneBlock(MeshFloatVector & data, 
									   int & vertexCount,
									   const LocalChunkSystem &manager,
									   int x, int y, int z, 
									   const sf::Vector3f & ux, 
									   const sf::Vector3f & uy, 
									   const sf::Vector3f & uz) {
		
	
	const Block & block = manager.getRelativeBlock(BlockCoordinate(x,y,z));
	
	if (! block.isActivated())
		return;
		
	
		// Vector3f because we use floats to build vertex
		const sf::Vector3f pos(x, y, z);
		
//		std::cout << "block r("<<block.r()<<") g("<<block.g()<<") "<<std::endl;
		
		
		const Block & f =  getBlock(manager, BlockCoordinate(x,y-1,z));
		const Block & r =  getBlock(manager, BlockCoordinate(x+1,y,z));	
		const Block & be = getBlock(manager, BlockCoordinate(x,y+1,z));
		const Block & l =  getBlock(manager, BlockCoordinate(x-1,y,z));
		const Block & t =  getBlock(manager, BlockCoordinate(x,y,z+1));
		const Block & bo = getBlock(manager, BlockCoordinate(x,y,z-1));
		
		MeshVertexVector vertices;
		
		
		block.build(vertices, pos, r,be,l,f,t,bo);
		vertexCount += vertices.size();
		
		
		for(MeshVertexVector::const_iterator it = vertices.begin();
			it != vertices.end(); ++it) {
			const MeshVertex & vertex = *it;
			
			data.push_back(vertex.x);
			data.push_back(vertex.y);
			data.push_back(vertex.z);
			data.push_back(vertex.r);
			data.push_back(vertex.g);
			data.push_back(vertex.b);
			//data.push_back(vertex.a);
			data.push_back(vertex.nx);
			data.push_back(vertex.ny);
			data.push_back(vertex.nz);
		}
	
}




//bool ChunkData::upIsCompletelyEmpty()
//{
//	for (int x = 0; x < SIZE; ++x)
//		for (int y = 0; y < SIZE; ++y)
//			for (int z = 0; z < SIZE; ++z)
//				if (mArray[x][y][z] > Block::ACTIVATED)
//					return false;
//	return true;
//}

