#pragma once
#include <vector>
#include "MyParticle.h"
#include "MyRipple.h"

class Emitter
{
private:
	std::vector<MyParticle> p_array;
	std::vector<MyRipple> r_array;

public:
	Emitter();
	~Emitter();
	
	void CreateParticle(float, float, int, Color);
	void CreateRipple(float fx, float fy, float fr);

	void Update();
	void Draw();
};

