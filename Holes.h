#pragma once
#include "Obstacle.h"
class Holes:public Obstacle
{
	ETSIDI::Sprite *P;
public:
	Holes(const char *name);
	virtual ~Holes();
};

