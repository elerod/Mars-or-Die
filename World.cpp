#include "World.h"


World::World()	{}

World::~World()	{}

void World::Initialize() {

	x_eye = 0.0;
	y_eye = 7.5;
	z_eye = 30;

	sun.SetColor(1.0, 1.0, 0);
	sun.SetRadius(3);

	earth.SetPos(3.0, 3.0);
	earth.SetRadius(1);
	earth.SetColor(0.0, 0.0, 1.0);
}

void World::Draw() {
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, y_eye, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	sun.Draw();
	earth.Draw();
}

void World::Timer() {
	
	//sun.RiseRadius(0.05);

}