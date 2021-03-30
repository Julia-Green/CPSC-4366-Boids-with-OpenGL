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
	vertPositions.at(0) = glVertex2f(randomPosition(randEngine), randomPosition(randEngine));

	//Calculates positon for other two verticies
	if (velocity.at(0) >= 0 && velocity.at(1) >= 0) {
		vertPositions.at(0) = glVertex2f(randomPosition(randEngine), randomPosition(randEngine));
	
	} else if(velocity.at(0) >= 0 && velocity.at(1) < 0 || velocity.at(0) > 0 && velocity.at(1) <= 0) {
		
	} else if (velocity.at(0) <= 0 && velocity.at(1) > 0 || velocity.at(0) < 0 && velocity.at(1) >= 0) {
		
	} else {
			
	}

}