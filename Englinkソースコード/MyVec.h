#pragma once
#include <Siv3D.hpp>
#include <cmath>
#include "MyDefine.h"

class MyVec
{
protected:
	float x, y;

public:
	MyVec();
	MyVec(float fx, float fy) { x = fx, y = fy; }
	~MyVec();
	void SetPos(float fx, float fy) { x = fx, y = fy; }
	float GetX() { return x; }
	float GetY() { return y; }

	friend void Rotate(MyVec& a, const MyVec b, int deg);
};

float Distance(float x1, float y1, float x2, float y2);
float Distance(MyVec a, MyVec b);
void Rotate(MyVec& a, const MyVec b, int deg);