#ifndef MESH_HPP
#define MESH_HPP

#include "Renderer.hpp"

typedef GLuint MeshId;
typedef GLfloat MeshFloat;

class Mesh
{
	public:
		Mesh();
		
		// data contains all vertices and colors
		// [x y z r g b], [x y z r g b]...
		void setData(MeshFloat *data, int vertexCount);
		
		void draw() const;
		
	private:
		// OpenGL id
		GLuint mVboId;
		GLsizei mVertexCount;
};

#endif // MESH_HPP
