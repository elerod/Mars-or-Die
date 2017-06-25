#pragma once
#include "ETSIDI.h"
#include "Vector2.h"
#include "Interaction.h"
#include "Shot.h"
#include "glut.h"
class Ship
{
	ETSIDI::SpriteSequence *up, *down;
	ETSIDI::Sprite *ship;
	Vector2 position, velocity, acc;
	float angle;
	class Shot shot[10];
	int dim;
	int move;
	long time;
public:
	Ship(const char *name);
	virtual ~Ship();
	void Move(float t);
	void Initialize();
	void SpecialKey(int key);
	void Draw();
	Vector2 getPos();
	void Key(unsigned char key);
	void SetVel(float x, float y);
	Shot* getShot(int i);
	friend class Interaction;
};

