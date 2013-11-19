#include "Renderer.hpp"

Renderer::Renderer()
{
	glewInit();
	
	// Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f);
}

void Renderer::clear()
{
	glClear(GL_DEPTH_BUFFER_BIT);
	// Apply some transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Renderer::translate(float x, float y, float z)
{
	glTranslatef(x, y, z);
}

void Renderer::lookAt(float eyeX, float eyeY, float eyeZ, 
					  float centerX, float centerY, float centerZ)
{
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0, 0, 1.0);
}

void Renderer::beginMesh(MeshId &id)
{
	id = glGenLists(1);
	glNewList(id, GL_COMPILE);
	glBegin(GL_TRIANGLES);
}

void Renderer::endMesh()
{
	glEnd();
	glEndList();
}

void Renderer::addVertexToMesh(float x, float y, float z, float r, float g, float b)
{
	glColor3f(r,g,b);
	glVertex3f(x, y, z);
}

void Renderer::drawMesh(MeshId &id)
{
	glCallList(id);
}
