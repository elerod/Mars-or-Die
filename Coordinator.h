#pragma once
#include "World.h"
#include "Phase2.h"
#include "Skeleton.h"
#include "Interaction.h"
class Coordinator
{
	Skeleton *world[50];
	//World world;
	enum State{HOME, FIRST_PHASE, FIRST_PHASE_DONE,SECOND_PHASE,GAME_OVER};
	State state;
	int Phase1;
	//Phase2 world2;

public:

	void Draw();
	void Timer();
	void Key(unsigned char key, int x_t, int y_t);

	Coordinator();
	virtual ~Coordinator();

};

