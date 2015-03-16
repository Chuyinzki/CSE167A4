#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include "Window.h"
#include "Matrix4.h"
#include "main.h"
#include "MatrixTransform.h"
#include "Geode.h"
#include "Sphere.h"
#include "Cube.h"
#include "Robot.h"
#include "RobotTest.h"

using namespace std;

namespace Globals
{
	Group world;
};

int Window::width  = 512;   // set window width in pixels here
int Window::height = 512;   // set window height in pixels here
double colour[3] = { 0.0, 0.0, 0.0 };
int type = 0;
Camera camera;
Robot robot;
bool Window::bounding = false;
int howManyRobots = 30;
int sidezy = 0;
int inzy = -5;
int upity = 0;
bool a = false;
bool c = false;
int frame = 0, time, timebase = 0;


//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback()
{
	robot.update(35);
	robot.render();

	displayCallback();         // call display routine to show the cube
}


//----------------------------------------------------------------------------
// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
  //cerr << "Window::reshapeCallback called" << endl;
  width = w;
  height = h;
  glViewport(0, 0, w, h);  // set new viewport size
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, double(width)/(double)height, 1.0, 1000.0); // set perspective projection viewing frustum
  glTranslatef(sidezy, upity, inzy);    // move camera back 20 units so that it looks at the origin (or else it's in the origin)
  glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
  if (!a){ robot.draw(camera.getMatrix()); }
  else{
	  for (int i = 0; i < howManyRobots; i++){
		  for (int j = 0; j < howManyRobots; j++){
			  Matrix4 temp;
			  temp.makeTranslate(i * 5, 0, j * 5);
			  robot.draw(temp);
		  }
	  }
  }

  if (bounding){

  }
  else{

  }

  frame++;
  time = glutGet(GLUT_ELAPSED_TIME);
  if (time - timebase > 1000) {
	  cout << "FPS: " << frame*1000.0 / (time - timebase) << endl;
	  timebase = time;
	  frame = 0;
  }

  //final = clock() - init;
  //if (final) cout << "Frames per Second = " << (double)(1 / final) << "!!!" << endl;

  glFlush();  
  glutSwapBuffers();
}

void Window::keyboardCallback(unsigned char key, int x, int y) {
	//std::cout << "key " << key << std::endl;
	//Esc key
	if (key == 27) exit(0);
	
	//bounding Spheres
	if (key == 'b') {
		bounding = !bounding;
		cout << "Bounding: " << bounding << endl;
	}

	//culling
	if (key == 'c') {
		c = !c;
		cout << "Culling: " << c << endl;
	}

	//p for army key
	if (key == 'p') a = !a;

	//w key
	if (key == 'w') inzy++;

	//s key
	if (key == 's') inzy--;

	//a key
	if (key == 'a') sidezy++;

	//d key
	if (key == 'd') sidezy--;

	//i key
	if (key == 'i') upity--;

	//k key
	if (key == 'k') upity++;

	Window::reshapeCallback(Window::width, Window::height);

}

void Window::keyboardCallbackSpecial(int key, int x, int y) {

}

int main(int argc, char *argv[])
{
	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float shininess[] = { 100.0 };
	float position[] = { 0.0, 10.0, 1.0, 0.0 };	// lightsource position

	glutInit(&argc, argv);      	      	      // initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   // open an OpenGL context with double buffering, RGB colors, and depth buffering
	glutInitWindowSize(Window::width, Window::height);      // set initial window size
	glutCreateWindow("OpenGL Cube");    	      // open window and set window title

	glEnable(GL_DEPTH_TEST);            	      // enable depth buffering
	glClear(GL_DEPTH_BUFFER_BIT);       	      // clear depth buffer
	glClearColor(0.0, 0.0, 0.0, 0.0);   	      // set clear color to black
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // set polygon drawing mode to fill front and back of each polygon
	glDisable(GL_CULL_FACE);		// disable backface culling to render both sides of polygons
	glShadeModel(GL_SMOOTH);             	      // set shading to smooth
	glMatrixMode(GL_PROJECTION);

	// Generate material properties:
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Generate light source:
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Install callback functions:
	glutDisplayFunc(Window::displayCallback);
	glutReshapeFunc(Window::reshapeCallback);
	glutIdleFunc(Window::idleCallback);
	glutKeyboardFunc(Window::keyboardCallback);
	glutSpecialFunc(Window::keyboardCallbackSpecial);


	camera = Camera(Vector3(0, 1, 5), Vector3(0, 0, 0), Vector3(0, 5, 0));

	// Initialize cube matrix:

	glutMainLoop();
	return 0;
}

