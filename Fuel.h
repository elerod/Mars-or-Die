#pragma once
#include "Obstacle.h"
class Fuel:public Obstacle
{
	ETSIDI::Sprite *P;
public:
	Fuel(const char *name);
	~Fuel(void);
	void Draw();
};

