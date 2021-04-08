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
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();  /*clear the matrix */
			/*viewing transformation*/
	gluLookAt(0.0, 0.0, 250.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f); // x is green
	glVertex3i(250, 0, 0);
	glVertex3i(-250, 0, 0);
	glColor3f(0.0f, 1.0f, 1.0f); // y is blue
	glVertex3i(0, 250, 0);
	glVertex3i(0, -250, 0);
	glEnd();


	glBegin(GL_TRIANGLES);

	glColor3f(0.5, 0.5, 0);
	glTranslatef(tempBoid.translatePosition.x, tempBoid.translatePosition.y, 0.0);
	glRotatef(tempBoid.theta, 1.0, 0.0, 0.0);
	glVertex2f(tempBoid.vertPositions.at(0).x, tempBoid.vertPositions.at(0).y);
	glVertex2f(tempBoid.vertPositions.at(1).x, tempBoid.vertPositions.at(1).y);
	glVertex2f(tempBoid.vertPositions.at(2).x, tempBoid.vertPositions.at(2).y);

	std::cout << tempBoid.vertPositions.at(0).x << " " << tempBoid.vertPositions.at(0).y << std::endl
	<< tempBoid.vertPositions.at(1).x << " " << tempBoid.vertPositions.at(1).y << std::endl
	<< tempBoid.vertPositions.at(2).x << " " << tempBoid.vertPositions.at(2).y << std::endl 
	<< tempBoid.theta << " " << tempBoid.velocity.x << " " << tempBoid.velocity.y << std::endl
	<< tempBoid.translatePosition.x << " " << tempBoid.translatePosition.y << std::endl;

	glEnd();
	glFlush();
	tempBoid.updateBoidPosition();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 250.0);
	glMatrixMode(GL_MODELVIEW);
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
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}