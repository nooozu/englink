#include "MyRipple.h"

MyRipple::MyRipple()
{
}

MyRipple::~MyRipple()
{
}

void MyRipple::Initialize(float fx, float fy, float fr)
{
	flag = true;
	alpha = 255;
	x = fx, y = fy, radius = fr;
}

void MyRipple::Update()
{
	alpha -= 8.0;
	radius += 0.5;
	color.setAlpha(alpha);

	if (alpha <= 0.01) {
		flag = false;
	}
}

void MyRipple::Draw()
{
	Circle(x, y, radius).drawFrame(0, 1, color);
}
