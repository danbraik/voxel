#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/System.hpp>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>



class Renderer
{
	public:
		Renderer();
		void screen(int width, int height);
		
		void clear();
		void translate(float x, float y, float z);
		void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ);
};

#endif // RENDERER_HPP
