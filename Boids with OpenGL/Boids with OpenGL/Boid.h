#pragma once
#include <vector>
#include "Constants.h"

class Boid {
	public:

		//Construct the boid
		Boid() {};

		std::vector<float> velocity{0, 0};
		std::vector<glVertex2f> vertPositions{
			glVertex2f(0.0, 0.0), //First Vertex 
			glVertex2f(0.0, 0.0), //Second Vertex
			glVertex2f(0.0, 0.0) //Third Vertex
		};
};

};
