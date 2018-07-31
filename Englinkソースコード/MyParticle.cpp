#include "MyParticle.h"

MyParticle::MyParticle()
{
	x = 0, y = 0, radius = 0;
}

MyParticle::~MyParticle()
{
}

void MyParticle::Initialize(float fx, float fy, float fr)
{
	life = true;
	alpha = 255;

	x = fx, y = fy;
	radius = fr;

	float rad, rot = Random(360);
	rad = rot * M_PI / 180;

	dx = (radius / Random(2.0, 3.0)) * cos(rad);
	dy = (radius / Random(2.0, 3.0)) * sin(rad);
}

void MyParticle::Update()
{
	alpha -= 2;

	dy += 0.02;

	x += dx;
	y += dy;

	color.setAlpha(alpha);

	if (alpha < 0) {
		life = false;
	}
}

void MyParticle::Draw()
{
	if (life) {
		Circle(x, y, radius).draw(color);
	}
}