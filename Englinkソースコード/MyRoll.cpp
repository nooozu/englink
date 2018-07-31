#include "MyRoll.h"

MyRoll::MyRoll()
{
	rot_value = 0;
	max_rot = -1;
	min_rot = -1;
}

MyRoll::~MyRoll()
{
}

void MyRoll::Initialize(MyVec* p, MyVec t)
{
	pos = p;
	target = t;
	length = Distance(*pos, target);

	//targetからposへのベクトルを求める
	MyVec TtoP;
	TtoP.SetPos(target.GetX() - pos->GetX(), target.GetY() - pos->GetY());

	//角度を求める
	rot = atan2(TtoP.GetY(), TtoP.GetX()) * 180 / PI;

	//-180~180 から 0~360の値に変える
	rot += 180;
}

void MyRoll::Rotation()
{
	rot += rot_value;
	rot = RoundDegree(rot);

	if ((int)rot == max_rot || (int)rot == min_rot) {
		rot_value *= -1;
	}

	float fx, fy, rad = DEG_TO_RAD(rot);
	fx = cos(rad) * length + target.GetX();
	fy = sin(rad) * length + target.GetY();
	pos->SetPos(fx, fy);
}

void MyRoll::AddRot(int i)
{
	rot += i;
	rot = RoundDegree(rot);

	if (rot < max_rot && rot > max_rot - 90) {
		rot = max_rot;
	}
	else if (rot > min_rot && rot < min_rot + 90) {
		rot = min_rot;
	}

	float fx, fy, rad = DEG_TO_RAD(rot);
	fx = cos(rad) * length + target.GetX();
	fy = sin(rad) * length + target.GetY();
	pos->SetPos(fx, fy);
}

void MyRoll::SetMaxMin(int max, int min)
{
	max_rot = max;
	min_rot = min;
}

float RoundDegree(float f)
{
	if (f >= 0.0f) {
		return fmod(f, 360.0f);
	}
	else {
		return 360.0f - fmod(-f, 360.0f);
	}

	return f;
}