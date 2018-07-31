#pragma once
#include "BaseScene.h"
#include "MyCircleButton.h"
#include "Vec2string.h"
#include "Game.h"

class Result : public BaseScene {
private:
	MyCircle c_main;
	MyCircleButton cb_back;

	Font f_text;
	int s;

	bool input_flag;
	Font f_name;
	String s_name;
	Rect input_space;

	Vec2string v2s_data;

public:
	Result(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};
