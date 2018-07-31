#pragma once
#include "MyVec.h"

class MyRoll
{
private:
	float length, rot, rot_value;
	MyVec* pos;
	MyVec  target;

public:
	int max_rot, min_rot;

	MyRoll();
	~MyRoll();
	void Initialize(MyVec* p, MyVec t);
	void Rotation();

	void AddRot(int i);
	void SetRotValue(float f) { rot_value = f; }
	void SetMaxMin(int, int);

	float GetRot() { return rot; }
	float GetLength() { return length; }
};

float RoundDegree(float f);