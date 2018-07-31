#pragma once
#include "MyCircle.h"

typedef enum {
	e_none,
	e_max,
	e_min,
} ChangeState;

class MyCircleDynamic : public MyCircle
{
private:
	ChangeState change_state;
	float change_value;
	float max_size, min_size;
public:
	MyCircleDynamic();
	~MyCircleDynamic();
	void Initialize(float, float, float);
	void Update();
	void SetChangeState(ChangeState c) { change_state = c; }
	void SetChangeValue(float f) { change_value = f; }
	void SetMaxMin(float, float);
};

