#include <vector>
#include <random>
#include "Boid.h"

Boid::Boid() {
	//Assigns random velocity
	std::uniform_int_distribution<float> randomVelocity(-10, 10);
	for (int i = 0; i < velocity.size(); i++) {
		velocity.at(i) = randomVelocity(randEngine);
	}

	//Assigns random position for first vertex
	std::uniform_int_distribution<float> randomPosition(0, screenWidth - 25);
	float x = randomPosition(randEngine);
	float y = randomPosition(randEngine);
	vertPositions.at(0) = glVertex2f(x, y);

	//Calculates positon for other two verticies
	// x = (y + 4) / 2, y = 2x - 4
	// x = (y - 8) / -2, y = -2x + 8
	if (velocity.at(0) >= 0 && velocity.at(1) >= 0) { // Both x and y velocities are positive or both 0
		vertPositions.at(1) = glVertex2f((y + 4) / 2, (2 * x) - 4);
		vertPositions.at(2) = glVertex2f((y - 8) / -2, (-2 * x) + 8);
	} else if(velocity.at(0) >= 0 && velocity.at(1) < 0 || velocity.at(0) > 0 && velocity.at(1) <= 0) { // X velocity is positive/0 and y velocity is negative or X velocity is positive and y velocity is negative/0
		vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
		vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	} else if (velocity.at(0) <= 0 && velocity.at(1) > 0 || velocity.at(0) < 0 && velocity.at(1) >= 0) { // X velocity is negative/0 and y velocity is positive or X velocity is negative and y velocity is positive/0
		vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
		vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	} else { // Both x and y velocities are negative
		vertPositions.at(1) = glVertex2f(x - 10.0, y - 5);
		vertPositions.at(2) = glVertex2f(x - 10.0, y + 5);
	}

}