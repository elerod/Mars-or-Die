#pragma once
#include "Vector2D.h"
#include "glut.h"

class Sphere
{
protected:

	Vector2D position;
	float radius;
	float red, green, blue;
	float r_elipse

public:
		
	Sphere();
	~Sphere();

	void Draw();
	void SetColor(float r, float g, float b);
	void SetRadius(float r);
	void RiseRadius(float r);
	void SetPos(float x, float y);
};

