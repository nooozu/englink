#include "Result.h"

Result::Result(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_RESULT_BACKGROUND);
}

void Result::Initialize()
{
	BaseScene::Initialize();

	v2s_data.Load("data/PlayLog.csv");
	v2s_data.AddCol();

	f_text = Font(70);
	f_name = Font(20);

	s = 0;
	s_name = L"";

	c_main.Initialize(SCREEN_CENTER_X, 570, 570);
	c_main.SetColor(Color(COLOR_RESULT_CIRCLE));

	cb_back.Initialize(40, 40, 20);
	cb_back.SetColor(Color(COLOR_RESULT_CIRCLE));
	cb_back.SetRippleFlag(true);

	input_flag = false;
	input_space = Rect(SCREEN_CENTER_X - 200, SCREEN_CENTER_Y + 200 - 20, 400, 40);
}

void Result::Update()
{
	if (score > s) {
		if (abs(score - s) > 10) {
			s += 10;
		}
		else {
			s++;
		}
	}

	if (input_space.mouseOver && Input::MouseL.released) {
		input_flag = true;
	}
	else if (!input_space.mouseOver && Input::MouseL.released) {
		input_flag = false;
	}

	if (input_flag) {
		Input::GetCharsHelper(s_name);
	}

	cb_back.Update();
	if (cb_back.GetButton()) {
		std::stringstream ss;
		ss << score;
		if (s_name == L"") {
			s_name = L"no name";
		}
		v2s_data.InputCell(ss.str(), v2s_data.GetRow() - 1, 0);
		v2s_data.InputCell(s_name.narrow(), v2s_data.GetRow() - 1, 1);
		v2s_data.Save("data/PlayLog.csv");
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

void Result::Draw()
{
	c_main.Draw();
	Circle(c_main.GetX(), c_main.GetY(), c_main.GetRadius() - 15).drawFrame(7, 0, Color(COLOR_RESULT_BACKGROUND));
	Line({ SCREEN_CENTER_X - 350, 250 }, { SCREEN_CENTER_X + 350, 250 }).draw(5, Color(COLOR_RESULT_BACKGROUND));

	cb_back.Draw();
	Circle(cb_back.GetX(), cb_back.GetY(), 10).drawFrame(0.5, 8, Color(COLOR_RESULT_BACKGROUND));

	f_text(L"SCORE").drawCenter({ SCREEN_CENTER_X, 150 }, Color(COLOR_RESULT_BACKGROUND));
	f_text(s, L"点").drawCenter({ SCREEN_CENTER_X, 350 }, Color(COLOR_RESULT_BACKGROUND));

	input_space.draw(Color(COLOR_RESULT_BACKGROUND));
	
	if (input_flag) {
		f_name(L"キーボードで名前を入力することが可能です").drawCenter({ SCREEN_CENTER_X, SCREEN_CENTER_Y + 150 }, Color(COLOR_RESULT_BACKGROUND));
	}
	else {
		f_name(L"この枠をクリックすると名前を入力できます").drawCenter({ SCREEN_CENTER_X, SCREEN_CENTER_Y + 150 }, Color(COLOR_RESULT_BACKGROUND));
	}
	f_name(s_name).drawCenter({ SCREEN_CENTER_X, SCREEN_CENTER_Y + 200 }, Color(COLOR_RESULT_CIRCLE));
}
