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

	
	
	
//	float ambLight0[4] = {.5f, .5f, .5f, 0.1f};
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambLight0);
//	float difLight0[4] = {1.f, 1.f, 1.f, 1.5f};
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, difLight0);
//	float specLight0[4] = {0.5f, 0.5f, 0.5f, 100.0f};
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specLight0);
	
//	float mat[3];
//	mat[0] = 0.24725;
//	  mat[1] = 0.1995;
//	  mat[2] = 0.0745;
//	  mat[3] = 1.0;
//	  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
//	  mat[0] = 0.75164;
//	  mat[1] = 0.60648;
//	  mat[2] = 0.22648;
//	  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
//	  mat[0] = 0.628281;
//	  mat[1] = 0.555802;
//	  mat[2] = 0.366065;
//	  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
//	  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
//	glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
	
//		GLfloat mat_specular[] = { .5, .5, .5, 1 };
	   
//	   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	   
//	   glShadeModel (GL_FLAT);
	
	   //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb);
//	   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	   
		glEnable( GL_LIGHTING );
	
		// Set up a material
		GLfloat ambient_mtrl[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		GLfloat diffuse_mtrl[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv( GL_FRONT, GL_AMBIENT, ambient_mtrl ); 
		glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse_mtrl );
	
	    // Set light 0 to be a pure white directional light
	    GLfloat diffuse_light0[]  = { 1.0f, 1.0f,  1.0f, 1.0f };
	    GLfloat specular_light0[] = { 1.0f, .0f,  1.0f, 1.0f };
	    GLfloat position_light0[] = { -5.0f, 5.0f, 10.0f, 0.0f };
	    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse_light0 );
	    glLightfv( GL_LIGHT0, GL_SPECULAR, specular_light0 );
	    glLightfv( GL_LIGHT0, GL_POSITION, position_light0 );
	    glEnable( GL_LIGHT0 );
	
	    // Enable some dim, grey ambient lighting so objects that are not lit 
	    // by the other lights are not completely black.
		GLfloat ambient_lightModel[] = { 0.7f, 0.7f, 0.7f, 1.f };
		glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambient_lightModel );
	
	   
	   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE) ;
	   glEnable ( GL_COLOR_MATERIAL ) ;
	
	// glShadeModel(GL_SMOOTH);
	 //glShadeModel(GL_FLAT);
	
	
	 
	 //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	 glEnable( GL_BLEND ); 
	 glClearColor(0.0, 0.0, 0.0, 1.0);
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

void Renderer::addNormalToMesh(const sf::Vector3f & norm)
{
	float l = norm.x*norm.x+norm.y*norm.y*norm.z*norm.z;
	l /= 2;
	glNormal3f(norm.x/l, norm.y/l, norm.z/l);
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
