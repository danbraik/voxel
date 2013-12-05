#ifndef MESH_HPP
#define MESH_HPP

#include "Renderer.hpp"

typedef GLuint MeshId;
typedef GLfloat MeshFloat;
typedef sf::Uint8 MeshDetail;

class Mesh
{	
	public:
		static const MeshDetail MAX_DETAIL = 3;
		
		
		Mesh();
		
		// data contains all vertices and colors
		// [x y z r g b], [x y z r g b]...
		void setData(MeshFloat *data, int vertexCount, MeshDetail detail = 0);
		
		void draw(MeshDetail detail = 0) const;
		
	private:
		// OpenGL id
		GLuint mVboId[MAX_DETAIL];
		GLsizei mVertexCount[MAX_DETAIL];
};

#endif // MESH_HPP
