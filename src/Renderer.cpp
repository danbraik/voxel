#include "Renderer.hpp"

Renderer::Renderer()
{
	glewInit();
	
	// Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(90.f, 800/600., 0.5f, 5000.f);
	
	glClearDepth(1.0);		
	//glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  

	
		glEnable( GL_LIGHTING );
	
		// Set up a material
		GLfloat ambient_mtrl[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		GLfloat diffuse_mtrl[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv( GL_FRONT, GL_AMBIENT, ambient_mtrl ); 
		glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse_mtrl );
	
	    // Set light 0 to be a pure white directional light
	    GLfloat diffuse_light0[]  = { 1.0f, 1.0f,  1.0f, 1.0f };
	    GLfloat specular_light0[] = { .0f, .0f,  .0f, 1.0f };
	    GLfloat position_light0[] = { -5.0f, 5.0f, 10.0f, 0.0f };
	    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse_light0 );
	    glLightfv( GL_LIGHT0, GL_SPECULAR, specular_light0 );
	    glLightfv( GL_LIGHT0, GL_POSITION, position_light0 );
	    glEnable( GL_LIGHT0 );
	
	    // Enable some dim, grey ambient lighting so objects that are not lit 
	    // by the other lights are not completely black.
		GLfloat ambient_lightModel[] = { 0.5f, 0.5f, 0.6f, 1.f };
		glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambient_lightModel );
	
	   
	   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE) ;
	   glEnable ( GL_COLOR_MATERIAL ) ;
	
	// glShadeModel(GL_SMOOTH);
	 glShadeModel(GL_FLAT);
	
	
	 
	 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	 glEnable( GL_BLEND ); 
	 glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Renderer::screen(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(90.f, static_cast<float>(width)/height, 0.5f, 5000.f);
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

