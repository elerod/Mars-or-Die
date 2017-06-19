#include "Coordinator.h"


Coordinator::Coordinator()
{
	state = HOME;
	world[0] = new World();
	world[1] = new Phase2();
}

void Coordinator::Draw()
{
	if (state == HOME)
	{
		gluLookAt(0, 8, 20,  // posicion del ojo
			0.0, 8, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/mars_home.png").id);//Dbujo del menu de inicio del juego
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);//Hay que indicarle las longitudes del dibujo
		glTexCoord2d(0, 1); glVertex3f(-25, 20, 0);
		glTexCoord2d(1, 1); glVertex3f(25, 20, 0);
		glTexCoord2d(1, 0); glVertex3f(25, -10, 0);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 1, 1);//Las fuentes del menu de inicio, se inicializarán a color blanco
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 50);
		ETSIDI::printxy("MARS or Die", -10, 7);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
		ETSIDI::printxy("Ignacio Hermes Rodriguez & Elena Rodríguez", 0 ,0);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
		ETSIDI::printxy("Press a to start", -4, 5);

	}
	else if (state == FIRST_PHASE)
	{
		world[0]->Draw(FIRST_PHASE);//Se dibuja el mundo, en esta funcion estarán incluidos los otros draw.
	
	}
	else if (state == FIRST_PHASE_DONE) {
		gluLookAt(0, 8, 20,  // posicion del ojo
			0.0, 8, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/mars_home.png").id);//Dbujo del menu de inicio del juego
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);//Hay que indicarle las longitudes del dibujo
		glTexCoord2d(0, 1); glVertex3f(-25, 20, 0);
		glTexCoord2d(1, 1); glVertex3f(25, 20, 0);
		glTexCoord2d(1, 0); glVertex3f(25, -10, 0);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(1, 1, 1);//Las fuentes del menu de inicio, se inicializarán a color blanco
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 50);
		ETSIDI::printxy("MARS or Die", -10, 7);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fonts/nasalization-rg.ttf", 12);
		ETSIDI::printxy("Press a to start", -4, 5);
	}
	else if (state == SECOND_PHASE) {
		world[1]->Draw(SECOND_PHASE);
	}
}

void Coordinator::Key(unsigned char key, int x_t, int y_t)
{
	if (state == HOME)
	{
		if (key == 'a')//Tecla que se pulsa para empezar el juego
		{
			state = FIRST_PHASE;
			world[0]->Initialize();
		}
	}
	if (state == FIRST_PHASE)//Para lanzar la nave
	world[0]->Key(key, x_t, y_t);
	if (state == FIRST_PHASE_DONE)
	{
		if (key == 'a')
		{
			state = SECOND_PHASE;
			world[1]->Initialize();
		}
	}
}

void Coordinator::Timer()
{
	if (state == FIRST_PHASE)
	Phase1=world[0]->Timer();
	if (Phase1 == 1) state = FIRST_PHASE_DONE;
}

Coordinator::~Coordinator()
{

}
