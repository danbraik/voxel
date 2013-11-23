#include <cstdlib>
#include <cstring>

#include <iostream>
#include <vector>

#include "Block.hpp"
#include "Chunk.hpp"
#include "ChunkManager.hpp"
#include "LocalChunkSystem.hpp"

bool Chunk::isStrictelyInside(const sf::Vector3i & blockPosition)
{
	return blockPosition.x > 0 && blockPosition.y > 0 && blockPosition.z > 0 &&
			blockPosition.x < SIZE_1 && blockPosition.y < SIZE_1 && blockPosition.z < SIZE_1;
}



Chunk::Chunk() :  mPosition(), mMesh(), mArray()
{
}

void Chunk::init() {
	
	for(int x=0;x<SIZE;++x)
		for(int y=0;y<SIZE;++y)
			for(int z=0;z<SIZE;++z)
				mArray[x][y][z] = Block::Air;
	
//	int h = random()%(SIZE-4)+2;
	
//	if (h < 0) h = 0;
//	if (h > SIZE) h = SIZE;
	
//	for (int z=0;z<h;++z) {
//	for (int x=0;x < SIZE; ++x) {
//		for (int y=0;y < SIZE;++y){
//			set(sf::Vector3i(x,y,z), Block::Stone);
//		}
//	}
//	}
	
//	if (h+1 < SIZE) {
//		for (int x=0;x < SIZE; ++x) {
//			for (int y=0;y < SIZE;++y){
//				if (std::rand() % 5 == 0)
//					set(sf::Vector3i(x,y,h), Block::Dirt);
//				else
//					set(sf::Vector3i(x,y,h), Block::Air);
//			}
//		}
		
//		for (int z=h+1;z<SIZE;++z) {
//		for (int x=0;x < SIZE; ++x) {
//			for (int y=0;y < SIZE;++y){
//				set(sf::Vector3i(x,y,z), Block::Air);
//			}
//		}
//		}
//	}
}

const sf::Vector3i &Chunk::getPosition() const
{
	return mPosition;
}

void Chunk::setPosition(const sf::Vector3i &position)
{
	mPosition = position;
}

void Chunk::rebuild(const ChunkManager &manager)
{
	std::vector<MeshFloat> data;
	// 6144 is reserved by vector
	// average 4000 floats
	data.reserve(SIZE*SIZE*SIZE*12);
	int vertexCount = 0;
	
	const sf::Vector3f ux(Block::SIZE,0,0);
	const sf::Vector3f uy(0,Block::SIZE,0);
	const sf::Vector3f uz(0,0,Block::SIZE);
	
	const LocalChunkSystem local(manager, this);
	
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




void Chunk::computeOneBlock(std::vector<MeshFloat> &data, 
							int & vertexCount, 
							const LocalChunkSystem &manager,
							int x, int y, int z
			, const sf::Vector3f & ux, const sf::Vector3f& uy, const sf::Vector3f& uz) {
	
	BlockType type = get(sf::Vector3i(x,y,z));
	
	const Block & block = manager.getBlock(type);
		
	if (block.isFilled()) {
		sf::Vector3f pos(x*Block::SIZE, y*Block::SIZE, z*Block::SIZE);
		
//		std::cout << "block r("<<block.r()<<") g("<<block.g()<<") "<<std::endl;
		
		if (!manager.getRelativeBlock(sf::Vector3i(x,y-1,z)).isFilled()){
		// front
			
			addVertexToMesh(data, vertexCount, -uy,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, -uy,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+ux+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -uy,  pos+uz,block.r(), block.g(),block.b());
			
		}
		if (!manager.getRelativeBlock( sf::Vector3i(x+1,y,z)).isFilled()){	
			// right
			
			addVertexToMesh(data, vertexCount, ux,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, ux,  pos+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uy+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, ux,  pos+ux+uz,block.r(), block.g(),block.b());
		}
		if (!manager.getRelativeBlock( sf::Vector3i(x,y+1,z)).isFilled()){
			// behind
			
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+uy+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uy,  pos+ux+uy+uz,block.r(), block.g(),block.b());
		}
		if (!manager.getRelativeBlock( sf::Vector3i(x-1,y,z)).isFilled()){
			// left
			
			addVertexToMesh(data, vertexCount, -ux,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uz,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, -ux,  pos+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, -ux,  pos+uy+uz,block.r(), block.g(),block.b());
		}
		if (!manager.getRelativeBlock( sf::Vector3i(x,y,z+1)).isFilled()){
			// top
			
			addVertexToMesh(data, vertexCount, uz,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux+uy,block.r(), block.g(),block.b());
			
			addVertexToMesh(data, vertexCount, uz,  pos+uz,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+ux+uy,block.r(), block.g(),block.b());
			addVertexToMesh(data, vertexCount, uz,  pos+uz+uy,block.r(), block.g(),block.b());
		}
		if (!manager.getRelativeBlock( sf::Vector3i(x,y,z-1)).isFilled()){
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

void Chunk::draw() const
{
	mMesh.draw();
}



