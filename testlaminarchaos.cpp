#define TIXML_USE_STL

#ifdef _WIN32
#include <windows.h> 
#endif

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;

//#include <GL/gl.h> 
//#include <GL/glu.h> 
#include <GL/glut.h> 

#include "TextureLoader.h"
#include "MD2Mesh.h"

static int win;
int iWindowHeight, iWindowWidth;

int TextureIds[1];

int LoadGLTextures()											// Load Bitmaps And Convert To Textures
{
	Tartan::LoadTextureFile( TextureIds[0], "USMC.pcx" );
	return true;												// Return The Status
}

LaminarChaos::MD2Mesh mymesh;

void LoadMeshes()
{
	cout << "loading meshes..." << endl;
   mymesh.LoadMeshFile( "tris.MD2" );
   cout << "meshes loaded" << endl;
}

float zRot = 270;

void DrawWorld()
{   
	//glRotatef( zRot, 0, 1, 0 );
    zRot += 0.35;

  glTranslatef( -12,0,0 );

glScalef( 2,2,2);
glRotatef( 150, 0,0,1);
  	glBindTexture(GL_TEXTURE_2D, TextureIds[0] );
   // glutSolidTeapot( 1.0 );
    
    mymesh.Render();
}

void disp()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
 
    glLoadIdentity();

    // rotate so z axis is up, and x axis is forward
    glRotatef( 90, 0.0, 0.0, 1.0 );
    glRotatef( 90, 0.0, 1.0, 0.0 );

    glRotatef( 0, 0, 1, 0 );
    glRotatef( 0, 0, 0, 1 );

    glTranslatef( 15, 0, 0 );

   glPushMatrix();
  // SetColor( 1,1,1);
   DrawWorld();
   glPopMatrix();
   
//   GLfloat position[] = { -20.5f, 20.0f, 30.0f, 1.0f };
//   glLightfv(GL_LIGHT0, GL_POSITION, position);

    glutSwapBuffers(); 
}

void MainLoop()
{
         glutPostRedisplay();
}

int main(int argc, char **argv){
	 cout << "main() " << endl;
	
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
   iWindowWidth = glutGet( GLUT_SCREEN_WIDTH );
   iWindowHeight = glutGet( GLUT_SCREEN_HEIGHT );
   glutInitWindowSize(iWindowWidth,iWindowHeight);
   glutInitWindowPosition(0,0); 
   glShadeModel(GL_SMOOTH);
   glEnable(GL_TEXTURE_2D);
 
   win = glutCreateWindow("blah");
   
   glClearColor(0.0,0.0,0.0,0.0);

   glEnable(GL_DEPTH_TEST); 
//  glEnable (GL_CULL_FACE);
   
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   GLfloat ambientLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
   GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
   GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
   GLfloat position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
   
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
   glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   if (!LoadGLTextures())										// Jump To Texture Loading Routine ( NEW )
	{
		printf( "failed to load textures\n" );//
		exit(1);
	}

   LoadMeshes();

	glEnable(GL_TEXTURE_2D);									// Enable Texture Mapping ( NEW )

    glLoadIdentity();

   glMatrixMode( GL_PROJECTION ); 
   glLoadIdentity();
   GLfloat aspect = (GLfloat) iWindowWidth / iWindowHeight; 
   gluPerspective( 45.0, aspect, 0.5, 100.0 ); 

 // glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); 

   glMatrixMode( GL_MODELVIEW ); 
   glViewport (0, 0, iWindowWidth, iWindowHeight);

   glutDisplayFunc(disp);
   glutIdleFunc( MainLoop ); 

   glutMainLoop();

   return 0;
}


