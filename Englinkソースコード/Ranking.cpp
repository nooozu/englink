#include "Ranking.h"

Ranking::Ranking(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_RANKING_BACKGROUND);
}

void Ranking::Initialize()
{
	BaseScene::Initialize();

	ranking_data.Load("data/PlayLog.csv");

	for (int i = 0; i < 3; i++) {
		i_score[i] = stoi(ranking_data.GetCell(i, 0));
		s_name[i] = ranking_data.GetCell(i, 1);
	}

	text = Font(20);

	c_main.Initialize(SCREEN_WIDTH + 50, SCREEN_CENTER_Y + 150, 510);
	c_main.SetColor(Color(COLOR_RANKING_CIRCLE1));

	cb_back.Initialize(40, 40, 20);
	cb_back.SetColor(Color(COLOR_RANKING_CIRCLE1));
	cb_back.SetRippleFlag(true);

	cd[0].Initialize(SCREEN_CENTER_X + 300, SCREEN_CENTER_Y + 80, 40);
	cd[0].SetColor(Color(COLOR_RANKING_BACKGROUND));
	cd[0].SetMaxMin(48, 22);
	cd[0].SetChangeValue(0.1);

	cd[1].Initialize(SCREEN_WIDTH - 50, 100, 10);
	cd[1].SetColor(Color(COLOR_RANKING_CIRCLE2));
	cd[1].SetMaxMin(23, 8);
	cd[1].SetChangeValue(0.2);

	cd[2].Initialize(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 150, 25);
	cd[2].SetColor(Color(COLOR_RANKING_CIRCLE3));
	cd[2].SetMaxMin(28, 10);
	cd[2].SetChangeValue(0.15);

	f_name = Font(20);

	//PlayLogデータから配列に格納
	vec_score.resize(ranking_data.GetRow());
	vec_name.resize(ranking_data.GetRow());
	for (int i = 0; i < ranking_data.GetRow(); i++) {
		vec_score[i] = stoi(ranking_data.GetCell(i, 0));
		vec_name[i] = Widen(ranking_data.GetCell(i, 1));
	}

	//scoreのソート
	for (int i = 0; i < vec_score.size(); i++) {
		for (int j = i + 1; j < vec_score.size(); j++) {
			if (vec_score[i] < vec_score[j]) {
				//score入れ替え
				int tmp = vec_score[i];
				vec_score[i] = vec_score[j];
				vec_score[j] = tmp;
				//名前の入れ替え
				String s_tmp = vec_name[i];
				vec_name[i] = vec_name[j];
				vec_name[j] = s_tmp;
			}
		}
	}
}

void Ranking::Update()
{
	cb_back.Update();
	
	cd[0].Update();
	cd[1].Update();
	cd[2].Update();

	if (cb_back.GetButton()) {
		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

void Ranking::Draw()
{
	c_main.Draw();
	text(L"ランキング").drawCenter({ SCREEN_WIDTH - 130, SCREEN_CENTER_Y - 30 }, Color(COLOR_RANKING_FONT));

	Line({ SCREEN_CENTER_X - 100, 150 }, { SCREEN_WIDTH, 150 }).draw(12, Color(COLOR_RANKING_CIRCLE1));
	Line({ SCREEN_CENTER_X - 350, SCREEN_CENTER_Y + 50 }, { SCREEN_WIDTH, SCREEN_CENTER_Y + 50 }).draw(12, Color(COLOR_RANKING_CIRCLE1));
	Line({ SCREEN_CENTER_X - 250, SCREEN_HEIGHT - 80 }, { SCREEN_WIDTH, SCREEN_HEIGHT - 80 }).draw(12, Color(COLOR_RANKING_CIRCLE1));

	f_name(L"1.", vec_name[0], L"  : Score ", vec_score[0]).draw(SCREEN_CENTER_X - 100, 150 - 50, Color(COLOR_RANKING_CIRCLE1));
	f_name(L"2.", vec_name[1], L"  : Score ", vec_score[1]).draw(SCREEN_CENTER_X - 350, SCREEN_CENTER_Y + 50 - 50, Color(COLOR_RANKING_CIRCLE1));
	f_name(L"3.", vec_name[2], L"  : Score ", vec_score[2]).draw(SCREEN_CENTER_X - 250, SCREEN_HEIGHT - 80 - 50, Color(COLOR_RANKING_CIRCLE1));

	cd[0].Draw();
	cd[1].Draw();
	cd[2].Draw();

	cb_back.Draw();
	Circle(cb_back.GetX(), cb_back.GetY(), 10).drawFrame(0.5, 8, Color(COLOR_RANKING_BACKGROUND));
}
