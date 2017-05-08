#include "Sphere.h"

Sphere::Sphere() {}

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
	float PI=3.14159;
	for(float x=0.0; x<=2*PI; x+=0.06)
	{
	glColor3ub(255,0,0);
	glBegin(GL_LINES);
		glVertex2f(r_elipse*sin(x), r_elipse/2 * cos(x));
		glVertex2f(r_elipse*sin(x+0.06), r_elipse/2* cos(x+0.06));
	glEnd();
}
}
