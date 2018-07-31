#include "MyCircleRebound.h"

MyCircleRebound::MyCircleRebound()
{
	dx = 0, dy = 0;
	m = 1.0;
	active = true;
}

MyCircleRebound::~MyCircleRebound()
{
}

void MyCircleRebound::RandomMove()
{
	dx = Random(-2.0, 2.0), dy = Random(-2.0, 2.0);
}

void MyCircleRebound::Update()
{
	if (active) {
		x += dx;
		y += dy;

		if (x < FIELD_LEFT + radius) {
			x = FIELD_LEFT + radius;
			dx *= -1;
		}
		if (y < FIELD_TOP + radius) {
			y = FIELD_TOP + radius;
			dy *= -1;
		}

		if (x > FIELD_RIGHT - radius) {
			x = FIELD_RIGHT - radius;
			dx *= -1;
		}
		if (y > FIELD_BOTTOM - radius) {
			y = FIELD_BOTTOM - radius;
			dy *= -1;
		}
	}
	
	MyCircleButton::Update();
}

void Rebound(MyCircleRebound& a, MyCircleRebound& b)
{
	if (CircleHitCheck(a, b)) {
		
		float ab_x, ab_y;
		ab_x = b.x - a.x;
		ab_y = b.y - a.y;

		//ÇﬂÇËçûÇ›ó ÇåvéZ
		float len, dist;
		len = sqrt(POW2(ab_x) + POW2(ab_y));
		dist = (a.radius + b.radius) - len;
		if (len > 0) {
			len = 1.0 / len;
		}
		ab_x *= len;
		ab_y *= len;

		//ÇﬂÇËçûÇ›Çâè¡Ç≥ÇπÇÈ
		dist /= 2.0;
		a.x -= ab_x * dist;
		a.y -= ab_y * dist;
		b.x += ab_x * dist;
		b.y += ab_y * dist;

		//ë¨ìxÇÃåvéZ
		float ma = (b.m / (a.m + b.m)) * (1 + E) * ((b.dx - a.dx) * ab_x + (b.dy - a.dy) * ab_y);
		float mb = (a.m / (a.m + b.m))*(1 + E)* ((a.dx - b.dx)*ab_x + (a.dy - b.dy)*ab_y);

		a.dx += ma * ab_x;
		a.dy += ma * ab_y;
		b.dx += mb * ab_x;
		b.dy += mb * ab_y;
	}
}