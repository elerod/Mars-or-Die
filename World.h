#pragma once
#include "glut.h"
#include "Ship.h"
#include "Obstacle.h"
#include "Asteroid.h"
#include "Interaction.h"
#include "Animation.h"
#include "Alien.h"
#include "Fuel.h"
#include "Vector2.h"
#define MAX 1000

class World
{
	float x_eye, y_eye, z_eye;
	Ship *spacecraft;
	Obstacle *Obstacle[MAX];
	Animation animation;
	int points;
	long time;
	int elim;
public:
	World();
	~World();
	void Draw();
	void Initialize();
	void SpecialKey(int key);
	void Move(float t);
	void Key(unsigned char key);
};

