#include "ChunkData.hpp"
#include "LocalChunkSystem.hpp"

#include <cstring>

ChunkData::ChunkData() : mMesh(), mArray()
{
	reset();
}

void ChunkData::reset()
{
	// Block::AIR must be 0
	// because memset doesnot copy
	// very well other values
	memset(mArray, Block::AIR, Chunk::SIZE*Chunk::SIZE*Chunk::SIZE);
}

void ChunkData::rebuild(const LocalChunkSystem & local)
{
	std::vector<MeshFloat> data;
	// 6144 is reserved by vector
	// average 4000 floats
	data.reserve(SIZE*SIZE*SIZE*12);
	int vertexCount = 0;
	
	const sf::Vector3f ux(1,0,0);
	const sf::Vector3f uy(0,1,0);
	const sf::Vector3f uz(0,0,1);
		
	for (int x=0;x < SIZE; ++x) {
		for (int y=0;y < SIZE;++y){
			for (int z=0;z<SIZE;++z) {
				computeOneBlock(data, vertexCount, local, x, y, z, ux, uy, uz);
			}
		}
	}
	
	//std::cout << "Capacity " << data.size() << " / " << SIZE*SIZE*SIZE*12 << "; capacit " << data.capacity() <<  std::endl;
	mMesh.setData(data.data(), vertexCount);
}

const Mesh & ChunkData::getMesh() const
{
	return mMesh;
}





void addVertexToMesh(std::vector<MeshFloat> & data, 
					 int & vertexCount,
					 const sf::Vector3f & n,
					 const sf::Vector3f & pos,
					 
					 float r, float g, float b) {
	data.push_back(pos.x);
	data.push_back(pos.y);
	data.push_back(pos.z);
	data.push_back(r);
	data.push_back(g);
	data.push_back(b);
	data.push_back(n.x);
	data.push_back(n.y);
	data.push_back(n.z);
	
	//std::cout << "block r("<<r<<") g("<<g<<") b("<<b<<")"<<std::endl;
	
	vertexCount++;
}

inline bool testBlock(const LocalChunkSystem &manager, const BlockCoordinate & bc) {
	return  ! manager.getRelativeBlock(bc).isFilled();
}


inline void ChunkData::computeOneBlock(MeshFloatVector &data, 
							int & vertexCount, 
							const LocalChunkSystem &manager,
							int x, int y, int z
			, const sf::Vector3f & ux, const sf::Vector3f& uy, const sf::Vector3f& uz) {
	
	BlockType type = get(sf::Vector3i(x,y,z));
	
	const Block & block = manager.getBlock(type);
		
	if (block.isFilled()) {
		const sf::Vector3f pos(x, y, z);
		
//		std::cout << "block r("<<block.r()<<") g("<<block.g()<<") "<<std::endl;
		
		if (testBlock(manager, BlockCoordinate(x,y-1,z))){
		// front
			
			addVertexToMesh(data, vertexCount, -uy,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, -uy,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+uz,block.r(), block.g(),block.b());
			
		}
		if (testBlock(manager,  sf::Vector3i(x+1,y,z))){	
			// right
			
			addVertexToMesh(data, vertexCount, ux,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, ux,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uz,block.r(), block.g(),block.b());
		}
		if (testBlock(manager,  sf::Vector3i(x,y+1,z))){
			// behind
			
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy+uz,block.r(), block.g(),block.b());
		}
		if (testBlock(manager,  sf::Vector3i(x-1,y,z))){
			// left
			
			addVertexToMesh(data, vertexCount, -ux,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, -ux,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uy+uz,block.r(), block.g(),block.b());
		}
		if (testBlock(manager,  sf::Vector3i(x,y,z+1))){
			// top
			
			addVertexToMesh(data, vertexCount, uz,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux+uy,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, uz,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+uy,block.r(), block.g(),block.b());
		}
		if (testBlock(manager,  sf::Vector3i(x,y,z-1))){
			// bottom
			
			addVertexToMesh(data, vertexCount, -uz,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uz,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uz,  pos+uy+ux,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, -uz,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uz,  pos+uy+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uz,  pos+ux,block.r(), block.g(),block.b());
		}
	}
}


bool ChunkData::upIsCompletelyEmpty()
{
	for (int x = 0; x < SIZE; ++x)
		for (int y = 0; y < SIZE; ++y)
			for (int z = 0; z < SIZE; ++z)
				if (mArray[x][y][z] > Block::ACTIVATED)
					return false;
	return true;
}

