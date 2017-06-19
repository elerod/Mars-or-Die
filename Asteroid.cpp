#include "Asteroid.h"
#define MAX_X 300
#define MAX_Y 400
#define MAX_R 20
#define MAX_A 1

Asteroid::Asteroid(const char *name)
{
	P = new ETSIDI::Sprite(name,rand()%MAX_X,rand()%MAX_Y,rand()%MAX_R,rand()%MAX_R);
	//SetRadius(rand() % MAX_R);//Valor random de tamaño entre 0 y 20
	//SetPos(rand() % MAX_X, rand() % MAX_Y);
	//SetAcc(rand() % MAX_A,rand()%MAX_A);
	
}


Asteroid::~Asteroid(void)
{
	delete P;
}

void Asteroid::Draw() {
	Sphere::Draw("textures/Asteroids.png");
}

