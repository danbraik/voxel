#include "Mesh.hpp"
#include <iostream>


#define PROPS 9
#define DEBUG_GRAPH

#ifdef DEBUG_GRAPH
	#include "Chunk.hpp"
#endif

Mesh::Mesh() : mVboId(0), mVertexCount(0)
{
}


void Mesh::setData(MeshFloat *data, int vertexCount)
{
	// std::cout << "Set data" << std::endl;
	
	if (mVboId == 0) { // init
		glGenBuffers(1, &mVboId);
		// std::cout << "VboId " << mVboId << std::endl;
	}
	
	// float [x y z r g b n n n]
	GLsizei sizeDataInBytes = vertexCount * PROPS * sizeof(MeshFloat);
	// std::cout << "estimate data size " << sizeDataInBytes << std::endl;
	mVertexCount = vertexCount ;
	
	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	 
	//Upload vertex data to the video device
	glBufferData(GL_ARRAY_BUFFER, sizeDataInBytes, data, GL_DYNAMIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, -1);
}

void Mesh::draw() const
{

	
	if (mVertexCount == 0)
		return;
	
	//Make the new VBO active. Repeat here incase changed since initialisation
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	
	//Draw Triangle from VBO - do each time window, view point or data changes
	//Establish its 3 coordinates per vertex with zero stride in this array; necessary here
	
	// stride vertex
	// un point (pos+col) fait 6*sizeof(MeshFloat) octets
	// donc le vertex suivant est à 6*sizeof(MeshFloat) octets du premier
	// 
	glVertexPointer(3, GL_FLOAT, PROPS*sizeof(MeshFloat), static_cast<GLvoid*>(0));
	
	// pointeur = 3*sizeof(MeshFloat) car on est 3 unités plus loin du début du pt
	// (car les colors sont apres les positions)
	// concernant stride, de mm que vertex
	glColorPointer(3, GL_FLOAT, PROPS*sizeof(MeshFloat), 
				   static_cast<GLvoid*>(static_cast<GLvoid*>(0) + 3*sizeof(MeshFloat)));
	
	glNormalPointer(GL_FLOAT, PROPS*sizeof(MeshFloat),
					static_cast<GLvoid*>(static_cast<GLvoid*>(0) + 6*sizeof(MeshFloat)));
	
	//Establish array contains vertices (not normals, colours, texture coords etc)
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	 
	//Actually draw the triangle, giving the number of vertices provided
	glDrawArrays(GL_TRIANGLES, 0, mVertexCount);
	
	// maybe useful
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);	
	glDisableClientState(GL_NORMAL_ARRAY);	
	
	glBindBuffer(GL_ARRAY_BUFFER, -1);
	
	//Force display to be drawn now
	//glFlush();
}
