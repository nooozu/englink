#pragma once
#include <Siv3D.hpp>

class MyRipple
{
private:
	bool flag;

	float x, y, radius;
	float alpha;
	Color color;

public:
	MyRipple();
	~MyRipple();
	void Initialize(float, float, float);
	void Update();
	void Draw();
	void SetColor(Color c) { color = c; }

	bool GetFlag() { return flag; }
};

