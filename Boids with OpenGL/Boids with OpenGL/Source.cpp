#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <vector>
#include "boid.h"


//https://www.wikihow.com/Set-Up-an-OpenGL-FreeGLUT-GLEW-Template-Project-in-Visual-Studio
Boid tempBoid;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


void display(void)
{
	glClearColor(1, 1, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glColor3f(0.5, 0, 0);

	glVertex2f(tempBoid.vertPositions.at(0).x, tempBoid.vertPositions.at(0).y);
	glVertex2f(tempBoid.vertPositions.at(1).x, tempBoid.vertPositions.at(1).y);
	glVertex2f(tempBoid.vertPositions.at(2).x, tempBoid.vertPositions.at(2).y);

	std::cout << tempBoid.vertPositions.at(0).x << " " << tempBoid.vertPositions.at(0).y << std::endl
	<< tempBoid.vertPositions.at(1).x << " " << tempBoid.vertPositions.at(1).y << std::endl
	<< tempBoid.vertPositions.at(2).x << " " << tempBoid.vertPositions.at(2).y << std::endl;

	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}