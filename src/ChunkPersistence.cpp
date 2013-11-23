#include "ChunkPersistence.hpp"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include "Chunk.hpp"

ChunkPersistence::ChunkPersistence() : mChunkPositions()
{
}

void ChunkPersistence::	setDirectory(const std::string &world_path)
{
	mDirectory = world_path;
	
	loadIndex();
}

const PositionVector &ChunkPersistence::getExistingPositions()
{
	return mChunkPositions;
}

bool ChunkPersistence::loadChunk(Chunk *chunk)
{
	if (chunk==0)
		return false;
	
	const sf::Vector3i & chunkPosition = chunk->getPosition();
	
	std::cout << "Persist : load (" << chunkPosition.x<<" "
			  <<chunkPosition.y<< " "
			 << chunkPosition.z<<")";
	
	// optimize : change container to find faster
	for(PositionVector::iterator it = mChunkPositions.begin();
		it != mChunkPositions.end();
		++it) {
		if (*it == chunkPosition) {
			std::ostringstream oss;
			oss <<  mDirectory << "/" << chunkPosition.x 
				<< "." << chunkPosition.y
				<< "." << chunkPosition.z
				<< ".chunk";
			
			std::cout << " OK" << std::endl;
			loadData(chunk, oss.str());
			return true;
		}
	}
	std::cout << " no"<<std::endl;
	return false;
}

void ChunkPersistence::saveChunk(Chunk *chunk)
{
	if (chunk==0)
		return;
	
	const sf::Vector3i & chunkPosition = chunk->getPosition();
	
	std::cout << "Persist : Save (" << chunkPosition.x<<" "
			  <<chunkPosition.y<< " "
			 << chunkPosition.z<<")";
	
	// change container to avoid double item
	bool found = false;
	for(PositionVector::iterator it = mChunkPositions.begin();
		it != mChunkPositions.end();
		++it) {
		if (*it==chunkPosition) {
			found=true;
			break;
		}
	}
	if (!found) {
		mChunkPositions.push_back(chunkPosition);
		std::cout << " New"	;
	}
	std::cout << std::endl;
	
	std::ostringstream oss;
	oss <<  mDirectory << "/" << chunkPosition.x 
		<< "." << chunkPosition.y
		<< "." << chunkPosition.z
		<< ".chunk";
	
	std::fstream file;
	file.open((oss.str()).c_str(),std::ios_base::out | std::ios_base::binary );
	//std::cout << file.is_open()<<std::endl;
	
	file.write((char*)&(chunk->mArray),
			   Chunk::SIZE*Chunk::SIZE*Chunk::SIZE*sizeof(BlockType));
	
	file.close();
	
}

ChunkPersistence::~ChunkPersistence()
{
	// save index
	sf::Int32 nbChunks = mChunkPositions.size();
	
	std::fstream file;

	file.open((mDirectory+"/index.idx").c_str(),
			  std::ios_base::out | std::ios_base::binary );

	file.write((char*)&nbChunks,sizeof(sf::Int32));
	
	for(PositionVector::iterator it = mChunkPositions.begin();
		it != mChunkPositions.end();
		++it) {
		
		file.write((char*)&(*it),3*sizeof(int));
		
	}
	
	
	
	file.close();
	
	std::cout << "Persist : Index saved, " << mChunkPositions.size() << " chunks."<<std::endl;
}

void ChunkPersistence::loadIndex()
{
	sf::Int32 nbChunks = 3;
	
	
	std::fstream file;

	//	file.open((mDirectory+"/index.idx").c_str(),std::ios_base::out | std::ios_base::binary );

//	file.write((char*)&nbChunks,sizeof(int));
//	int x=0;
//	for (int i = 0; i < nbChunks; ++i) {
//		file.write((char*)&x,sizeof(int));		
//		++x;
//		file.write((char*)&x,sizeof(int));		
//		++x;
//		file.write((char*)&x,sizeof(int));		
//		++x;		
//	}	
	
//	file.close();
	
	nbChunks=0;
	
	//std::ifstream file;
	file.open((mDirectory+"/index.idx").c_str(),std::ios_base::in | std::ios_base::binary );
	//std::cout << file.is_open()<<std::endl;
	
	file.read((char*)&nbChunks, sizeof(int));
	
	std::cout << "Persist : "<< nbChunks << " chunks in index"<<std::endl;
	mChunkPositions.reserve(nbChunks);
	
	sf::Vector3i pos;
	for (int i = 0; i < nbChunks; ++i) {
		file.read((char*)&pos, sizeof(int)*3);
		std::cout << "Persist : Pos "<<pos.x <<" "<<pos.y<<" "<<pos.z <<std::endl;
		mChunkPositions.push_back(pos);
	}	
	
	file.close();
	
	
}

void ChunkPersistence::loadData(Chunk *chunk, const std::string &path)
{
	std::fstream file;
	file.open((path).c_str(),std::ios_base::in | std::ios_base::binary );
	//std::cout << file.is_open()<<std::endl;
	
	file.read((char*)&(chunk->mArray), Chunk::SIZE*Chunk::SIZE*Chunk::SIZE*sizeof(BlockType));
	
	file.close();
}
