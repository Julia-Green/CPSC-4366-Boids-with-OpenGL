#include <iostream>
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
	std::uniform_int_distribution<int> randomPosition(-215, 215);
	float x = randomPosition(randEngine);
	float y = randomPosition(randEngine);
	translatePosition.x = x;
	translatePosition.y = y;

	// Calculates positon for other two verticies adjustments needed

	theta = atan(velocity.x / velocity.y) * 180.0 / 3.14159265359; // rotate value 

	vertPositions.at(0).x = 0;
	vertPositions.at(0).y = 0;

	vertPositions.at(1).x = -5;
	vertPositions.at(1).y = -10;

	vertPositions.at(2).x = 5;
	vertPositions.at(2).y = -10;

	float xNew, yNew;
	xNew = (vertPositions.at(0).x * cos(-theta)) - (vertPositions.at(0).y * sin(-theta));
	yNew = (vertPositions.at(0).x * sin(-theta)) + (vertPositions.at(0).y * cos(-theta));

	vertPositions.at(0).x = xNew + translatePosition.x;
	vertPositions.at(0).y = yNew + translatePosition.y;

	xNew = (vertPositions.at(1).x * cos(-theta)) - (vertPositions.at(1).y * sin(-theta));
	yNew = (vertPositions.at(1).x * sin(-theta)) + (vertPositions.at(1).y * cos(-theta));

	vertPositions.at(1).x = xNew + translatePosition.x;
	vertPositions.at(1).y = yNew + translatePosition.y;

	xNew = (vertPositions.at(2).x * cos(-theta)) - (vertPositions.at(2).y * sin(-theta));
	yNew = (vertPositions.at(2).x * sin(-theta)) + (vertPositions.at(2).y * cos(-theta));

	vertPositions.at(2).x = xNew + translatePosition.x;
	vertPositions.at(2).y = yNew + translatePosition.y;

}

void Boid::updateBoidPositions() {
	vertPositions.at(0).x += velocity.x;
	vertPositions.at(0).y += velocity.y;

	vertPositions.at(1).x += velocity.x;
	vertPositions.at(1).y += velocity.y;

	vertPositions.at(2).x += velocity.x;
	vertPositions.at(2).y += velocity.y;
}