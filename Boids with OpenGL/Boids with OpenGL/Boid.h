#pragma once
#include <vector>
#include "Constants.h"

class Boid {
	public:
		//Construct the boid
		Boid();
		 
		void updateBoidPositions();

		float radius = 5.0;
		float theta = 0.0;
		Vector2D velocity{0, 0};
		Vector2D translatePosition{ 0, 0 };
		Vector2D firstVertex{0, 0};
		Vector2D secondVertex{0, 0};
		Vector2D thirdVertex{0, 0};

		std::vector<Boid> Boids;
		std::vector<Vector2D> vertPositions{
			firstVertex,
			secondVertex,
			thirdVertex 
		};
};


