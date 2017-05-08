#pragma once
#include "Sphere.h"
class Planet : public Sphere{

	float spin;
	Vector2D vel, ac_n, ac_t;

public:

	Planet();
	~Planet();

};

