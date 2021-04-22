#pragma once
#include <vector>
#include "Boid.h"
#include "Constants.h"

class Flock{
public:

	//Construct the flock
	Flock();
	std::vector<Boid> Boids;
};