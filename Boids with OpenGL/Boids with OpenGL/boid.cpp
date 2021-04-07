#include <math.h> 
#include <random>
#include <vector>

#include "Boid.h"

Boid::Boid() {
	//Assigns random x & y velocities
	std::uniform_real_distribution<float> randomVelocity(-10, 10);
	velocity.x = randomVelocity(randEngine);
	velocity.y = randomVelocity(randEngine);
	
	//Assigns random x & y positions for first vertex
	std::uniform_real_distribution<float> randomPosition(0, screenWidth - 25);
	float x = randomPosition(randEngine);
	float y = randomPosition(randEngine);
	vertPositions.at(0).x = x;
	vertPositions.at(0).y = y;

	//Calculates positon for other two verticies adjust me
	//theta = 15 for secondVertex https://academo.org/demos/rotation-about-point/
	//theta = -15 for thirdVertex
	vertPositions.at(1).x = x * cos(15.0) - y * sin(15.0);
	vertPositions.at(1).y = y * cos(15.0) - x * sin(15.0);

	vertPositions.at(2).x = x * cos(-15) - y * sin(-15.0);
	vertPositions.at(2).y = y * cos(-15.0) - x * sin(-15.0);

	//if (velocity.at(0) >= 0 && velocity.at(1) >= 0) { // Both x and y velocities are positive or both 0
	//	vertPositions.at(1).x = x * cos (30) - y * sin (30)
	//	vertPositions.at(2) = glVertex2f((y - 8) / -2, (-2 * x) + 8);
	//} else if(velocity.at(0) >= 0 && velocity.at(1) < 0 || velocity.at(0) > 0 && velocity.at(1) <= 0) { // X velocity is positive/0 and y velocity is negative or X velocity is positive and y velocity is negative/0
	//	vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
	//	vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	//} else if (velocity.at(0) <= 0 && velocity.at(1) > 0 || velocity.at(0) < 0 && velocity.at(1) >= 0) { // X velocity is negative/0 and y velocity is positive or X velocity is negative and y velocity is positive/0
	//	vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
	//	vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	//} else { // Both x and y velocities are negative
	//	vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
	//	vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	//}

}