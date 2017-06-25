#include "World.h"
#include <fstream>
#include <iostream>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

World::World()
{
	elim = 0;
	points = 0;
	spacecraft = new Ship("textures/spacecraft.png");
	for (int i = 0;i < 50;i++) Obstacle[i] = new Asteroid("textures/Asteroid.png");
	for (int i = 50;i < 100;i++)Obstacle[i] = new Asteroid("textures/Asteroid3.png");
	for (int i = 100;i < 150;i++)Obstacle[i] = new Asteroid("textures/Asteroid2.png");
	for (int i =150;i < 380;i++)Obstacle[i] = new Asteroid("textures/Asteroid3.png");
	for(int i=380;i<400;i++) Obstacle[i] = new Alien("textures/Alien.png");
	for (int i = 400;i < 500;i++) Obstacle[i] = new Fuel("textures/Fuel.png");
}


World::~World()
{
}
void World::Initialize() {
	x_eye = 0;
	z_eye = 100;
	y_eye = 0;
	spacecraft->Initialize();
}

void World::Draw() {

	gluLookAt((spacecraft->getPos()).x, (spacecraft->getPos()).y, z_eye,  // posicion del ojo
		(spacecraft->getPos()).x, (spacecraft->getPos()).y, 0.0F,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)   
	animation.Draw();
	spacecraft->Draw();

	for (int i = 0;i < 500-elim;i++) {
		Obstacle[i]->Draw(spacecraft->getPos());

	}

	int size = sizeof(points)*4;
	char *pidStr = new char[size + 1];
	_itoa_s(points,pidStr,size+1,10);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fonts/nasalization-rg.ttf", 30);
	ETSIDI::printxy(pidStr,spacecraft->getPos().x+ 30,spacecraft->getPos().y+ 33);


}

void World::Key(unsigned char key) {
	spacecraft->Key(key);
}

void World::SpecialKey(int key) {
	spacecraft->SpecialKey(key);
}

void World::Move(float t) {

	spacecraft->Move(t);

	for (int i = 0;i < 400;i++) {
		if (Interaction::ColisionExplosion(Obstacle[i], *spacecraft)) {
			animation.SetPos(spacecraft->getPos()+5);
			animation.Move();
			spacecraft->SetVel(0, 0);
		}
		/*for (int j = 0;j < 10;j++) {
			if (Interaction::ColisionShot(Obstacle[i], *spacecraft->getShot(j))) {
				animation.SetPos((*spacecraft)->getShot(j));
				animation.Move();
				delete Obstacle[i];
				elim++;
					for (int k = i;k < 500 - elim;k++) Obstacle[k] = Obstacle[k + 1];
		}*/
	}

	for (int i = 400;i < 500-elim;i++) {
		if (Interaction::ColisionFuel(Obstacle[i], *spacecraft)) {
			points += 100;
			Obstacle[i]->~Obstacle();
			elim++;
			for (int j = i;j < 500-elim;j++) Obstacle[j] = Obstacle[j + 1];
			std::ofstream miFichero("test.txt");
			miFichero << points << std::endl;
		}
	}

	time=ETSIDI::getMillis();
	if (time > 12000) {
		points += 10;
		time = 0;
	}
}