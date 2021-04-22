#pragma once
#include <random>

const int screenWidth{ 500 };
const int screenHeight{ 500 };

//Random Engine
static std::random_device seed;
static std::default_random_engine randEngine;

//structs
struct Vector2D
{
	float x;
	float y;
};
