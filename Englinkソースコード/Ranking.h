#pragma once
#include <iostream>
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "MyCircleButton.h"
#include "MyCircleDynamic.h"
#include "Vec2string.h"

class Ranking : public BaseScene {
private:
	Font text;
	MyCircle c_main;
	MyCircleButton cb_back;
	MyCircleDynamic cd[3];
	
	Font f_name;
	Vec2string ranking_data;
	std::string s_name[3];
	int i_score[3];

	std::vector<int> vec_score;
	std::vector<String> vec_name;

public:
	Ranking::Ranking(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};
