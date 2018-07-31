#include "MyVec.h"

MyVec::MyVec()
{
}

MyVec::~MyVec()
{
}

float Distance(float x1, float y1, float x2, float y2)
{
	float difx = x2 - x1;
	float dify = y2 - y1;
	float len = sqrt(POW2(difx) + POW2(dify));
	return len;
}

float Distance(MyVec a, MyVec b)
{
	MyVec dif;
	dif.SetPos(b.GetX() - a.GetX(), b.GetY() - a.GetY());
	float len = sqrt(POW2(dif.GetX()) + POW2(dif.GetY()));
	return len;
}

void Rotate(MyVec& a, const MyVec b, int deg)
{
	float length = sqrt(POW2(a.x - b.x) + POW2(a.y - b.y));
	float rad = DEG_TO_RAD(deg);
	a.x = b.x + length * cos(rad);
	a.y = b.y + length * sin(rad);
}