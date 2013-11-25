#include <cstdlib>
#include <cstring>

#include <iostream>
#include <vector>

#include "Block.hpp"
#include "Chunk.hpp"
#include "ChunkManager.hpp"
#include "LocalChunkSystem.hpp"

#define DEBUG_GRAPH

bool Chunk::isStrictelyInside(const sf::Vector3i & blockPosition)
{
	return blockPosition.x > 0 && blockPosition.y > 0 && blockPosition.z > 0 &&
			blockPosition.x < SIZE_1 && blockPosition.y < SIZE_1 && blockPosition.z < SIZE_1;
}



Chunk::Chunk() :  mPosition(), mIsModified(false), mIsCompletelyEmpty(false)
{
}

void Chunk::reset() {
	mIsCompletelyEmpty = false;
	mPosition.x=mPosition.y=mPosition.z=0x7FFFFFFF;
	mIsModified = false;
	mData = 0; // leak memory ?
}

ChunkData * Chunk::getData()
{
	return mData;
}

void Chunk::setData(ChunkData *data)
{
	mData = data;
}




const ChunkCoordinate & Chunk::getPosition() const
{
	return mPosition;
}

void Chunk::setPosition(const sf::Vector3i &position)
{
	mPosition = position;
}

void Chunk::rebuild(const ChunkManager &manager)
{
	if (!mIsCompletelyEmpty) {
		// assert(mData != 0)
		const LocalChunkSystem local(manager, this);
		mData->rebuild(local);
	}
}

void Chunk::draw() const
{
#ifdef DEBUG_GRAPH
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		if (mIsCompletelyEmpty)
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
	
	
	if (!mIsCompletelyEmpty) {
		// assert(mData != 0)
		if (mData != 0)
			mData->getMesh().draw();
		else
			std::cerr << "Chunk.draw : chunkdata is NULL !"<<std::endl;
	} 
}


void Chunk::setModified(bool modified)
{
	mIsModified = modified;
}

bool Chunk::isModified()
{
	return mIsModified;
}

void Chunk::setCompletelyEmpty(bool empty)
{
	mIsCompletelyEmpty = empty;
}

bool Chunk::isCompletelyEmpty()
{
	return mIsCompletelyEmpty;
}



