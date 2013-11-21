#include "Mesh.hpp"
#include <iostream>

Mesh::Mesh() : mVboId(0), mVertexCount(0)
{
}


void Mesh::setData(MeshFloat *data, int vertexCount)
{
	std::cout << "Set data" << std::endl;
	
	if (mVboId == 0) { // init
		glGenBuffers(1, &mVboId);
		std::cout << "VboId " << mVboId << std::endl;
	}
	
	GLsizei sizeData = vertexCount * 6 * sizeof(MeshFloat);
	mVertexCount = vertexCount;
	
	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	 
	//Upload vertex data to the video device
	glBufferData(GL_ARRAY_BUFFER, sizeData, data, GL_DYNAMIC_DRAW);
}

void Mesh::draw() const
{
	
	//Draw Triangle from VBO - do each time window, view point or data changes
	//Establish its 3 coordinates per vertex with zero stride in this array; necessary here
	glVertexPointer(3, GL_FLOAT, 3, static_cast<GLvoid*>(0));
	 
	glColorPointer(3, GL_FLOAT, 3, static_cast<GLvoid*>(0) + 3);
	
	//Make the new VBO active. Repeat here incase changed since initialisation
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	 
	//Establish array contains vertices (not normals, colours, texture coords etc)
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	 
	//Actually draw the triangle, giving the number of vertices provided
	glDrawArrays(GL_TRIANGLES, 0, mVertexCount);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	
	
	//Force display to be drawn now
	//glFlush();
}
