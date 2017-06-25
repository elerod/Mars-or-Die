#include "Interaction.h"



Interaction::Interaction()
{
	
}


Interaction::~Interaction()
{
}

bool Interaction::ColisionExplosion(Obstacle *as,Ship &sh) {
	if (sh.ship->collides(*(as->image))) {
		return true;
	}
	return false;
}
bool Interaction::ColisionFuel(class Obstacle *fuel, class Ship &sh) {
	if (sh.ship->collides(*(fuel->image))) {
		return true;
	}
	return false;
}

/*bool Interaction::ColisionShot(class Obstacle *as, class Shot &st) {
	Vector2 aux = st.getPos() - (*(as->image).getPos());
	if (sqrt(aux.x*aux.x + aux.y + aux.y) < 20)
		return true;
	else return false;
}*/