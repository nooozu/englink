#include "Game.h"

Game::Game(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_GAME_BACKGROUND1);
}

Game::~Game()
{
	delete wave;
	wave = NULL;
}

void Game::Initialize()
{
	BaseScene::Initialize();

	score = 0;
	wave_count = 0;
	clear_count = 0;

	count_down.Initialize(SCREEN_CENTER_X, SCREEN_CENTER_Y, 50);
	count_down.SetColor(Color(COLOR_GAME_FONT), Color(COLOR_GAME_FONT), 70, 4);

	v2s_data.Load("data/Exercise.csv");

	cb_back.Initialize(40, 40, 20);
	cb_back.SetColor(Color(COLOR_GAME_BACKGROUND2));
	cb_back.SetRippleFlag(true);

	NextWave();
}

void Game::Update()
{
	cb_back.Update();
	if (cb_back.GetButton()) {
		mSceneChanger->ChangeScene(eScene_Menu);
	}

	if (!count_down.GetFlag()) {
		count_down.Update();
	}
	else {
		wave->Update();
		if (wave->IsClear()) {
			score += wave->GetBubbleCount() * 10;
			clear_count++;
			NextWave();
		}
		time--;
		if (time <= 0) {
			NextWave();
		}
	}

	if (game_mode == Exam) {
		if (wave_count > 10) {
			mSceneChanger->ChangeScene(eScene_Result);
		}
	}
}

void Game::Draw()
{
	Rect({ FIELD_LEFT, FIELD_TOP }, { FIELD_RIGHT, FIELD_BOTTOM }).draw(Color(COLOR_GAME_BACKGROUND2));

	cb_back.Draw();
	Circle(cb_back.GetX(), cb_back.GetY(), 10).drawFrame(0.5, 8, Color(COLOR_GAME_BACKGROUND1));

	Line(0, FIELD_TOP - 10, SCREEN_WIDTH * time / max_time, FIELD_TOP - 10).draw(3, Color(COLOR_GAME_BACKGROUND2));

	if (!count_down.GetFlag()) {
		count_down.Draw();
	}
	else {
		wave->Draw();
	}
}

void Game::NextWave()
{
	int num = Random(v2s_data.GetRow() - 1);
	delete wave;
	wave = new GameWave(v2s_data.GetCell(num, 0), v2s_data.GetCell(num, 1));
	wave_count++;
	max_time = ONE_CIRCLE_TIME * wave->GetBubbleCount();
	time = max_time;
}
