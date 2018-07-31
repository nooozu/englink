#include "MyCircleButton.h"

MyCircleButton::MyCircleButton()
{
	button = false;
	r_flag = false;
	r_life = false;
}

MyCircleButton::~MyCircleButton()
{
}

void MyCircleButton::Update()
{
	if (Input::MouseL.released && OnMouse() && !r_life) {
		if (r_flag) {
			pRipple = new MyRipple;
			pRipple->Initialize(x, y, radius);
			pRipple->SetColor(main_color);
			r_life = true;
		}
		else {
			button = true;
		}
	}
	else {
		button = false;
	}

	if (r_life) {
		pRipple->Update();
		if (!pRipple->GetFlag()) {
			button = true;
			r_life = false;
			delete pRipple;
		}
	}
}

void MyCircleButton::Draw()
{
	Circle(x, y, radius).draw(main_color);
	font(Widen(text)).drawCenter(x, y, font_color);

	if (r_life) {
		pRipple->Draw();
	}
}

bool MyCircleButton::OnMouse()
{
	if (POW2(Mouse::Pos().x - x) + POW2(Mouse::Pos().y - y) <= POW2(radius)) {
		return true;
	}
	else {
		return false;
	}
}