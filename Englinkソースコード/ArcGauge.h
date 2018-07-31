#pragma once
#include "MyCircleButton.h"
#include "MyRoll.h"

class ArcGauge
{
private:
	float x, y, radius, width;
	int volume, angle;

	MyRoll roll;
	MyCircleButton cb_point;
	Point mouse;

	bool flag;
public:
	ArcGauge();
	~ArcGauge();
	void Initialize(float tx, float ty, float tr, float tw);
	void Update();
	void Draw();

	void SetLimit(int max, int min);

	float GetVolume() { return (float)volume / 180; }
};

