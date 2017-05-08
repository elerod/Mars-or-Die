#pragma once
#include "glut.h"
#include "Planet.h"
#include "Sphere.h"

class World
{

	Sphere sun;
	Planet earth, mars, moon;
	float x_eye, y_eye, z_eye;

public:

	World();
	~World();

	void Initialize();
	void Draw();
	void Timer();
};

