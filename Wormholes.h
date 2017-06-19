#pragma once
#include "Obstacle.h"
#include "Holes.h"
class Wormholes:public Obstacle
{
	Holes *Hole1, *Hole2;
public:
	Wormholes(const char *name);
	virtual ~Wormholes(void);
};

