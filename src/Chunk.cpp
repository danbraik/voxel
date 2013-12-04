#include <cstdlib>
#include <cstring>

#include <iostream>
#include <vector>

#include "Block.hpp"
#include "Chunk.hpp"
#include "ChunkManager.hpp"
#include "LocalChunkSystem.hpp"

//#define DEBUG_GRAPH

bool Chunk::isStrictelyInside(const sf::Vector3i & blockPosition)
{
	return blockPosition.x > 0 && blockPosition.y > 0 && blockPosition.z > 0 &&
			blockPosition.x < SIZE_1 && blockPosition.y < SIZE_1 && blockPosition.z < SIZE_1;
}



Chunk::Chunk() :  mPosition(), mIsModified(false), mIsEmpty(false), mIsValid(false)
{
}

void Chunk::reset() {
	mIsEmpty = false;
	mPosition.x=mPosition.y=mPosition.z=0x7FFFFFFF;
	mIsModified = false;
	mData = 0; // leak memory ?
}






const ChunkCoordinate & Chunk::getPosition() const
{
	return mPosition;
}

void Chunk::setPosition(const ChunkCoordinate &position)
{
	mPosition = position;
}

void Chunk::rebuild()
{
	if (hasData()) {
		const LocalChunkSystem local(*mManager, this);
		mData->rebuild(local);
	}
}

void Chunk::draw() const
{
#ifdef DEBUG_GRAPH
	glDisable(GL_LIGHTING);
	if (!hasData())
		glBegin(GL_POINTS);
	else
		glBegin(GL_LINES);
	
		if (!hasData())
			glColor3f(1,.7,7);
		else	
			glColor3f(.7,.7,1);
		glVertex3f(0,0,0);glVertex3f(Chunk::SIZE ,0,0);
		glVertex3f(0,0,0);glVertex3f(0,Chunk::SIZE,0);
		glVertex3f(0,0,0);glVertex3f(0,0,Chunk::SIZE);
		
		glVertex3f(Chunk::SIZE,Chunk::SIZE,Chunk::SIZE);glVertex3f(Chunk::SIZE,0,Chunk::SIZE);
		glVertex3f(Chunk::SIZE,Chunk::SIZE,Chunk::SIZE);glVertex3f(0,Chunk::SIZE,Chunk::SIZE);
		glVertex3f(Chunk::SIZE,Chunk::SIZE,Chunk::SIZE);glVertex3f(Chunk::SIZE,Chunk::SIZE,0);
		
		glVertex3f(Chunk::SIZE,0,0);glVertex3f(Chunk::SIZE,Chunk::SIZE,0);
		glVertex3f(Chunk::SIZE,0,0);glVertex3f(Chunk::SIZE,0,Chunk::SIZE);
		glVertex3f(Chunk::SIZE,0,Chunk::SIZE);glVertex3f(0,0,Chunk::SIZE);
		
		glVertex3f(0,Chunk::SIZE,0);glVertex3f(Chunk::SIZE,Chunk::SIZE,0);
		glVertex3f(0,Chunk::SIZE,0);glVertex3f(0,Chunk::SIZE,Chunk::SIZE);
		glVertex3f(0,Chunk::SIZE,Chunk::SIZE);glVertex3f(0,0,Chunk::SIZE);
	glEnd();
	glEnable(GL_LIGHTING);
#endif
	
	
	if (hasData())
		mData->getMesh().draw();
//		else
//			std::cerr << "Chunk.draw : chunkdata is NULL !"<<std::endl;
	
}

void Chunk::load()
{
	mData = new ChunkData;
	mData->reset();
	
	// load from file or generate
	mManager->loadChunk(this);
	
//	if (mData->upIsCompletelyEmpty()) {
//		delete mData;
//		mData = 0;
//	} else {
//		rebuild();
//	}
	
	mIsValid = true;
	
}



void Chunk::beginSet(bool playerAction)
{
	mIsModified = playerAction;
	
	if(!hasData()) {
		mData = new ChunkData();
	}
	
}


void Chunk::endSet()
{
	rebuild();
}


void Chunk::setOne(const BlockCoordinate &pos, BlockType type)
{
	beginSet(true);
	set(pos, type);
	endSet();
}


void Chunk::unload()
{
	mIsValid = false;
}
