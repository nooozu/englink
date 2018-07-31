#include "ArcGauge.h"
#include "MyDefine.h"

ArcGauge::ArcGauge()
{
	x = 0, y = 0;
	radius = 0;
	width = 0;
}

ArcGauge::~ArcGauge()
{
}

void ArcGauge::Initialize(float tx, float ty, float tr, float tw)
{
	x = tx, y = ty;
	radius = tr;
	width = tw;

	flag = false;
	angle = -60;
	
	cb_point.Initialize(x + radius, y, 10);
	cb_point.SetColor(Color(COLOR_DEFAULT_CIRCLE));
	roll.Initialize(&cb_point, MyVec(x, y));
}

void ArcGauge::Update()
{
	cb_point.Update();

	if (Input::MouseL.pressed) {
		if (cb_point.OnMouse()) {
			flag = true;
		}
	}
	if (Input::MouseL.released) {
		flag = false;
	}
	
	if (flag) {
		if (Mouse::Pos().y > mouse.y) {
			roll.AddRot(3);
		}
		if (Mouse::Pos().y < mouse.y) {
			roll.AddRot(-3);
		}
		mouse = Mouse::Pos();
	}

	if (roll.GetRot() >= roll.max_rot) {
		volume = 360 - roll.GetRot() + roll.min_rot;
	}
	if (roll.GetRot() <= roll.min_rot) {
		volume = roll.min_rot - roll.GetRot();
	}
}

void ArcGauge::Draw()
{
	Circle(x, y, radius).drawArc(roll.max_rot - 180, PI, width / 2, width / 2, Color(215, 196, 187));
	cb_point.Draw();
}

void ArcGauge::SetLimit(int max, int min)
{
	roll.max_rot = RoundDegree(max);
	roll.min_rot = RoundDegree(min);
}