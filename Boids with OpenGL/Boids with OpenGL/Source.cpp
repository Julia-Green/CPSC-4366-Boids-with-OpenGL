#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <vector>
#include "Boid.h"
#include "Constants.h"
#include "Flock.h"

// Empty Flock
Flock newFlock;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity(); 
	gluLookAt(0.0, 0.0, 250.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Draw Boids
	for (auto boid : newFlock.Boids) {
		glPushMatrix();
			glBegin(GL_TRIANGLES);
			glColor3f(0.5, 0.5, 0);	
			glVertex2f(boid.vertPositions.at(0).x, boid.vertPositions.at(0).y);
			glVertex2f(boid.vertPositions.at(1).x, boid.vertPositions.at(1).y);
			glVertex2f(boid.vertPositions.at(2).x, boid.vertPositions.at(2).y);
			glEnd();
			glFlush();
		glPopMatrix();
	}
	
	// Updates position for each boid in the flock's Boids vector
	// Must be outside the loop above so it functions correctly
	for (int i = 0; i < newFlock.Boids.size(); i++) {
		newFlock.Boids.at(i).updateBoidPositions();
	}
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
	Flock temp;
	newFlock = temp;
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