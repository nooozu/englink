#pragma once
#include "MyCircle.h"
#include "MyRipple.h"

class MyCircleButton : public MyCircle
{
private:
	bool button, r_flag, r_life;

	MyRipple* pRipple;
public:
	MyCircleButton();
	~MyCircleButton();
	void Update();
	void Draw();
	bool GetButton() { return button; }
	bool OnMouse();
	void SetRippleFlag(bool b) { r_flag = b; }
};