#pragma once
#include "Ship.h"
#include "Obstacle.h"
#include "Asteroid.h"
#include "UFO.h"
#include "Fuel.h"
#include "Wormholes.h"
#include "Vector2D.h"
#include "Skeleton.h"
#define MAX 500

class Phase2:public Skeleton
{
	Obstacle* List[MAX];
	float x_eye, y_eye, z_eye;
	Ship *ship;
public:
	Phase2(){}
	virtual ~Phase2();
	void Initialize();
	void Draw(int n);
	virtual int Timer();
	virtual void Key(unsigned char key, int x_t, int y_t);
};

