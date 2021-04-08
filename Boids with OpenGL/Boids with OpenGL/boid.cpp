#include <math.h> 
#include <random>
#include <vector>

#include "Boid.h"

Boid::Boid() {
	//Assigns random x & y velocities
	std::uniform_int_distribution<int> randomVelocity(-10, 10);
	velocity.x = randomVelocity(randEngine);
	velocity.y = randomVelocity(randEngine);
	
	//Assigns random x & y positions for first vertex
	std::uniform_int_distribution<int> randomPosition(0, screenWidth - 25);
	float x = randomPosition(randEngine);
	float y = randomPosition(randEngine);
	translatePosition.x = x;
	translatePosition.y = y;

	//Calculates positon for other two verticies adjust me
	//theta = 15 for secondVertex https://academo.org/demos/rotation-about-point/
	//theta = -15 for thirdVertex https://www.texasgateway.org/resource/61-angle-rotation-and-angular-velocity https://processing.org/examples/flocking.html
	theta = heading(translatePosition.x, translatePosition.y) + radians(90); // rotate value http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-17-quaternions/#how-do-i-create-a-quaternion-in-c-
	vertPositions.at(0).x = 0;
	vertPositions.at(0).y = -radius * 2;

	vertPositions.at(1).x = -radius;
	vertPositions.at(1).y = radius * 2;

	vertPositions.at(2).x = radius;
	vertPositions.at(2).y = radius * 2;



	vertPositions.at(0).x = (vertPositions.at(0).x * cos(theta)) - (vertPositions.at(0).y * sin(theta));
	vertPositions.at(0).y = (vertPositions.at(0).y * cos(theta)) - (vertPositions.at(0).x * sin(theta));

	vertPositions.at(1).x = (vertPositions.at(1).x * cos(theta)) - (vertPositions.at(1).y * sin(theta));
	vertPositions.at(1).y = (vertPositions.at(1).y * cos(theta)) - (vertPositions.at(1).x * sin(theta));

	vertPositions.at(2).x = (vertPositions.at(2).x * cos(theta)) - (vertPositions.at(2).y * sin(theta));
	vertPositions.at(2).y = (vertPositions.at(2).y * cos(theta)) - (vertPositions.at(2).x * sin(theta));

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

float Boid::radians(float degrees) {
	return (degrees * 3.14159265359) / 180.0;
}

float Boid::heading(float x, float y) {
	return atan2(static_cast<float>(velocity.x), static_cast<float>(-velocity.y)) * 180.0 / 3.14159265359;
}

void Boid::updateBoidPosition() {
	vertPositions.at(0).x -= velocity.x;
	vertPositions.at(0).y -= velocity.y;

	vertPositions.at(1).x -= velocity.x;
	vertPositions.at(1).y -= velocity.y;

	vertPositions.at(2).x -= velocity.x;
	vertPositions.at(2).y -= velocity.y;


}