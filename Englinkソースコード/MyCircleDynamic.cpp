#include "MyCircleDynamic.h"

MyCircleDynamic::MyCircleDynamic()
{
}

MyCircleDynamic::~MyCircleDynamic()
{
}

void MyCircleDynamic::Initialize(float fx, float fy, float fr)
{
	MyCircle::Initialize(fx, fy, fr);
	change_state = e_none;
	change_value = 0;
	max_size = min_size = radius;
}

void MyCircleDynamic::Update()
{
	switch (change_state) {
	case e_max:
		radius += change_value;
		//Å‘å’l‚ğã‰ñ‚Á‚Ä‚¢‚é‚©
		if (radius > max_size) {
			radius = max_size;
			change_state = e_min;
		}
		break;
	case e_min:
		radius -= change_value;
		//Å¬’l‚ğ‰º‰ñ‚Á‚Ä‚¢‚é‚©
		if (radius < min_size) {
			radius = min_size;
			change_state = e_max;
		}
		break;
	};
}

void MyCircleDynamic::SetMaxMin(float max, float min)
{
	change_state = e_max;
	max_size = max;
	min_size = min;
}
