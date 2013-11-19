#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>

typedef GLuint MeshId;

class Renderer
{
	public:
		Renderer();
		void clear();
		void translate(float x, float y, float z);
		void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ);
		
		void beginMesh(MeshId & id);
		void endMesh();
		// to compute a triangle
		void addVertexToMesh(float x, float y, float z, float r, float g, float b);
		void drawMesh(MeshId & id);
};

#endif // RENDERER_HPP
