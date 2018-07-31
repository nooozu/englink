#pragma once
#define _USE_MATH_DEFINES
#include <Siv3D.hpp>
#include <cmath>

class MyParticle
{
private:
	bool life;

	float x, y, radius;
	float dx, dy;
	float alpha;
	Color color;

public:
	MyParticle();
	~MyParticle();
	void Initialize(float, float, float);
	void Update();
	void Draw();
	void SetColor(Color c) { color = c; }
	bool GetFlag() { return life; }
};

