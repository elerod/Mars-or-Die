#include "Sphere.h"

Sphere::Sphere() {
	SetPos(0.0, 0.0);
}

Sphere::~Sphere() {}

void Sphere::SetPos(float x, float y) {	
	position.x = x;
	position.y = y;
}

void Sphere::SetColor(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}

void Sphere::RiseRadius(float r) {
	radius += r;
}

void Sphere::SetRadius(float r) {
	radius = r;
}

void Sphere::Draw() {

	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glColor3f(red, green, blue);
	glutSolidSphere(radius, 40, 40);
	glPopMatrix();

}