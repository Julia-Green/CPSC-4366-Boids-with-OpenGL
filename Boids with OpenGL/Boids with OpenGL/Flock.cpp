#include <iostream>
#include <math.h> 
#include <random>
#include <vector>

#include "Flock.h"
#include "Boid.h"

Flock::Flock() {
	
	std::uniform_int_distribution<int> randomNum(1, 30);
	int numBoids = randomNum(randEngine);
	for (int i = 0; i < numBoids; i++) {
		Boid temp;
		Boids.push_back(temp);
	}
}