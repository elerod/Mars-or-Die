#pragma once
#include "Obstacle.h"

class Asteroid:public Obstacle
{
	ETSIDI::Sprite *P;
public:
	Asteroid(const char *name);
	virtual ~Asteroid(void);
	void Draw();
};

