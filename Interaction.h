#pragma once
#include "Obstacle.h"
#include "Ship.h"
#include "ETSIDI.h"

class Interaction
{
	
public:
	Interaction();
	~Interaction();
	static bool ColisionExplosion(class Obstacle *as,class Ship &sh);
	static bool ColisionFuel(class Obstacle *fuel, class Ship &sh);
	//static bool ColisionShot(class Obstacle *as, class Shot &st)

};

