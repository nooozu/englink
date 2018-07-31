#pragma once
#include "MyCircleButton.h"

#define E 0.8 //�����W��

class MyCircleRebound : public MyCircleButton
{
private:
	bool active;
	//dx dy:�ړ���  m:���� 
	float dx, dy, m;

public:
	MyCircleRebound();
	~MyCircleRebound();
	void RandomMove();
	void Update();

	
	friend void Rebound(MyCircleRebound&, MyCircleRebound&);
};

void Rebound(MyCircleRebound&, MyCircleRebound&);