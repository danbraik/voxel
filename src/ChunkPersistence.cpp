#include "ChunkPersistence.hpp"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include "Chunk.hpp"

//#define DEBUG
//#define DEBUG_LOAD_1

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

bool ChunkPersistence::isIndexed(const ChunkCoordinate & chunkPosition, ChunkPersistenceCache &cache)
{
	cache.mIsValid = false;
	
	for(PositionVector::iterator it = mChunkPositions.begin();
		it != mChunkPositions.end();
		++it) {
		if (*it == chunkPosition) {
			cache.mIsValid = true;
			cache.mPos = chunkPosition;
			return true;
		}
	}
	return false;
}

bool ChunkPersistence::loadChunk(Chunk *chunk)
{
	if (chunk==0)
		return false;
	
	const sf::Vector3i & chunkPosition = chunk->getPosition();
	
#ifdef DEBUG_LOAD_1
	std::cout << "Persist : load (" << chunkPosition.x<<" "
			  <<chunkPosition.y<< " "
			 << chunkPosition.z<<")";
#endif	

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
#ifdef DEBUG			
			std::cout << " OK" << std::endl;
#endif
			loadData(chunk, oss.str());
			return true;
		}
	}
#ifdef DEBUG
	std::cout << " no"<<std::endl;
#endif
	return false;
}

bool ChunkPersistence::loadChunk(Chunk * chunk, const ChunkPersistenceCache & cache)
{
	if (chunk == 0 || !cache.mIsValid)
		return false;
	
	if (chunk->getData() == 0) {
		std::cerr << "ERR : chunk has no chunkData !"<<std::endl;
		return false;
	}
		
	
	const ChunkCoordinate & chunkPosition = cache.mPos;
	
#ifdef DEBUG_LOAD_1
	std::cout << "Persist : load (" << chunkPosition.x<<" "
			  <<chunkPosition.y<< " "
			 << chunkPosition.z<<")";
#endif	

	std::ostringstream oss;
	oss <<  mDirectory << "/" << chunkPosition.x 
		<< "." << chunkPosition.y
		<< "." << chunkPosition.z
		<< ".chunk";

	loadData(chunk, oss.str());

#ifdef DEBUG			
			std::cout << " OK" << std::endl;
#endif
	return true;
}

void ChunkPersistence::saveChunk(Chunk *chunk)
{
	if (chunk==0)
		return;
	
	if (!chunk->isModified())
		return;
	
	const sf::Vector3i & chunkPosition = chunk->getPosition();

#ifdef DEBUG	
	std::cout << "Persist : Save (" << chunkPosition.x<<" "
			  <<chunkPosition.y<< " "
			 << chunkPosition.z<<")";
#endif
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
#ifdef DEBUG
		std::cout << " New"	;
#endif
	}
#ifdef DEBUG
	std::cout << std::endl;
#endif
	std::ostringstream oss;
	oss <<  mDirectory << "/" << chunkPosition.x 
		<< "." << chunkPosition.y
		<< "." << chunkPosition.z
		<< ".chunk";
	
	std::fstream file;
	file.open((oss.str()).c_str(),std::ios_base::out | std::ios_base::binary );
	//std::cout << file.is_open()<<std::endl;
	
	file.write((char*)&(chunk->getData()->mArray),
			   Chunk::SIZE*Chunk::SIZE*Chunk::SIZE*sizeof(BlockType));
	
	file.close();
	
	chunk->setModified(false);
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
		it != mChunkPositions.end(); ++it) {
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
#ifdef DEBUG
		std::cout << "Persist : Pos "<<pos.x <<" "<<pos.y<<" "<<pos.z <<std::endl;
#endif
		mChunkPositions.push_back(pos);
	}	
	
	file.close();
	
	
}

void ChunkPersistence::loadData(Chunk *chunk, const std::string &path)
{
	std::fstream file;
	file.open((path).c_str(),std::ios_base::in | std::ios_base::binary );
	//std::cout << file.is_open()<<std::endl;
	
	file.read((char*)&(chunk->getData()->mArray), Chunk::SIZE*Chunk::SIZE*Chunk::SIZE*sizeof(BlockType));
	
	file.close();
}
