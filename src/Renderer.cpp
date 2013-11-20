#include "Renderer.hpp"

Renderer::Renderer()
{
	glewInit();
	
	// Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(100.f, 800/600., 0.5f, 50.f);
	
	//glClearDepth(1.0);		
	//glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
	  glEnable(GL_DEPTH_TEST);
	
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat lightpos[] = {0, -0.1, 8, .01};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	
	glEnable(GL_COLOR_MATERIAL);
	 glShadeModel(GL_SMOOTH);
	 
	 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glEnable( GL_BLEND ); 
	 glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Renderer::clear()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
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

void Renderer::addVertexToMesh(float x, float y, float z, int r, int g, int b)
{
	glColor4ub(r,g,b, 255);
	glVertex3f(x, y, z);
}

void Renderer::addVertexToMesh(sf::Vector3f pos, int r, int g, int b)
{
	addVertexToMesh(pos.x,pos.y,pos.z,r,g,b);
}

void Renderer::drawMesh(MeshId &id)
{
	glCallList(id);
}
