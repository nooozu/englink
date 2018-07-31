#include "Menu.h"

Menu::Menu(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_MENU_BACKGROUND);
}

void Menu::Initialize()
{
	BaseScene::Initialize();

	sound_mgr.Load(L"sound/circle.mp3");

	IsPlay = false;
	game_mode = None;

	//íÜêSâ~
	c_main.Initialize(SCREEN_CENTER_X, SCREEN_CENTER_Y, 170);
	c_main.SetColor(Color(COLOR_MENU_CIRCLE));
	c_main.SetFontAll("Englink", 50, Color(COLOR_MENU_FONT));

	cb_back.Initialize(SCREEN_CENTER_X, SCREEN_CENTER_Y, 170);
	cb_back.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_back.SetFontAll("ñﬂÇÈ", 40, Color(COLOR_MENU_FONT));
	cb_back.SetRippleFlag(true);

	//íÜêSâ~ÇÃòg
	c_main_frame = Circle(c_main.GetX(), c_main.GetY(), 240);

	//É{É^Éì
	cb_play.Initialize(SCREEN_CENTER_X + 240, SCREEN_CENTER_Y, 70);
	cb_play.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_play.SetFontAll("énÇﬂÇÈ", 20, Color(COLOR_MENU_FONT));
	cb_play.SetRippleFlag(true);

	cb_config.Initialize(SCREEN_CENTER_X - 240, SCREEN_CENTER_Y, 70);
	cb_config.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_config.SetFontAll("ê›íË", 20, Color(COLOR_MENU_FONT));
	cb_config.SetRippleFlag(true);

	cb_ranking.Initialize(SCREEN_CENTER_X, SCREEN_CENTER_Y - 240, 70);
	cb_ranking.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_ranking.SetFontAll("ÉâÉìÉLÉìÉO", 15, Color(COLOR_MENU_FONT));
	cb_ranking.SetRippleFlag(true);

	cb_practice.Initialize(SCREEN_CENTER_X + 240, SCREEN_CENTER_Y, 70);
	cb_practice.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_practice.SetFontAll("ó˚èK", 20, Color(COLOR_MENU_FONT));
	cb_practice.SetRippleFlag(true);

	cb_exam.Initialize(SCREEN_CENTER_X - 240, SCREEN_CENTER_Y, 70);
	cb_exam.SetColor(Color(COLOR_MENU_CIRCLE));
	cb_exam.SetFontAll("ééå±", 20, Color(COLOR_MENU_FONT));
	cb_exam.SetRippleFlag(true);

	roll[0].Initialize(&cb_play, c_main);
	roll[1].Initialize(&cb_config, c_main);
	roll[2].Initialize(&cb_ranking, c_main);
	roll[3].Initialize(&cb_practice, c_main);
	roll[4].Initialize(&cb_exam, c_main);

	roll[0].SetMaxMin(330, 30);
	roll[1].SetMaxMin(210, 150);
	roll[2].SetMaxMin(300, 240);
	roll[3].SetMaxMin(290, 70);
	roll[4].SetMaxMin(250, 110);

	for (int i = 0; i < 5; i++) {
		roll[i].SetRotValue(Random(0.2, 0.5));
	}
}

void Menu::Update()
{
	emitter.Update();

	for (int i = 0; i < 5; i++) {
		roll[i].Rotation();
	}

	if (IsPlay) {
		cb_back.Update();
		cb_exam.Update();
		cb_practice.Update();
		if (cb_practice.GetButton()) {
			game_mode = Practice;
			mSceneChanger->ChangeScene(eScene_Game);
		}
		if (cb_exam.GetButton()) {
			game_mode = Exam;
			mSceneChanger->ChangeScene(eScene_Game);
		}

		if (cb_back.GetButton()) {
			IsPlay = false;
			sound_mgr.Play(0);
			emitter.CreateParticle(cb_practice.GetX(), cb_practice.GetY(), 20, Color(COLOR_MENU_CIRCLE));
			emitter.CreateParticle(cb_exam.GetX(), cb_exam.GetY(), 20, Color(COLOR_MENU_CIRCLE));
		}
	}
	else {
		cb_play.Update();
		cb_config.Update();
		cb_ranking.Update();

		if (cb_play.GetButton()) {
			IsPlay = true;
			sound_mgr.Play(0);
			emitter.CreateParticle(cb_config.GetX(), cb_config.GetY(), 20, Color(COLOR_MENU_CIRCLE));
			emitter.CreateParticle(cb_ranking.GetX(), cb_ranking.GetY(), 20, Color(COLOR_MENU_CIRCLE));
		}
		if (cb_config.GetButton()) {
			mSceneChanger->ChangeScene(eScene_Config);
		}
		if (cb_ranking.GetButton()) {
			mSceneChanger->ChangeScene(eScene_Ranking);
		}
	}
}

void Menu::Draw()
{
	c_main_frame.drawFrame(2, 2, Color(COLOR_MENU_CIRCLE));

	emitter.Draw();

	if (IsPlay) {
		cb_back.Draw();
		cb_exam.Draw();
		cb_practice.Draw();
	}
	else {
		c_main.Draw();

		cb_play.Draw();
		cb_config.Draw();
		cb_ranking.Draw();
	}
}
