#include "MyCircle.h"

MyCircle::MyCircle()
{
}

MyCircle::~MyCircle()
{
}

void MyCircle::Initialize(float fx, float fy, float fr)
{
	x = fx, y = fy, radius = fr;
	font = Font(radius / 3);
	font_color = Color(COLOR_DEFAULT_FONT);
	text = "";
}

void MyCircle::Draw()
{
	Circle(x, y, radius).draw(main_color);
	font(Widen(text)).drawCenter(x, y, font_color);
}

void MyCircle::SetFontAll(std::string s, float size, Color c)
{
	text = s;
	font = Font(size);
	font_color = c;
}

bool CircleHitCheck(MyCircle a, MyCircle b)
{
	float ab_x, ab_y, tr;
	ab_x = b.x - a.x;
	ab_y = b.y - a.y;
	tr = a.radius + b.radius;

	if (POW2(ab_x) + POW2(ab_y) < POW2(tr)) {
		return true;
	}
	else {
		return false;
	}
}