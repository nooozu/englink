#include "Config.h"

Config::Config(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_CONFIG_BACKGROUND);
}

void Config::Initialize()
{
	BaseScene::Initialize();

	cb_back.Initialize(40, 40, 20);
	cb_back.SetColor(Color(COLOR_CONFIG_CIRCLE));
	cb_back.SetRippleFlag(true);

	c_se.Initialize(SCREEN_CENTER_X, SCREEN_CENTER_Y, 70);
	c_se.SetColor(Color(COLOR_CONFIG_CIRCLE));
	c_se.SetFontAll("SE", 20, Color(COLOR_CONFIG_FONT));

	c_bgm.Initialize(SCREEN_CENTER_X - 320, SCREEN_CENTER_Y, 70);
	c_bgm.SetColor(Color(COLOR_CONFIG_CIRCLE));
	c_bgm.SetFontAll("BGM", 20, Color(COLOR_CONFIG_FONT));

	c_master.Initialize(SCREEN_CENTER_X + 320, SCREEN_CENTER_Y, 70);
	c_master.SetColor(Color(COLOR_CONFIG_CIRCLE));
	c_master.SetFontAll("‘S‘Ì", 20, Color(COLOR_CONFIG_FONT));

	ag_se.Initialize(c_se.GetX(), c_se.GetY(), c_se.GetRadius() * 1.5, 3);
	ag_se.SetLimit(300, 120);
	ag_bgm.Initialize(c_bgm.GetX(), c_bgm.GetY(), c_bgm.GetRadius() * 1.5, 3);
	ag_bgm.SetLimit(300, 120);
	ag_master.Initialize(c_master.GetX(), c_master.GetY(), c_master.GetRadius() * 1.5, 3);
	ag_master.SetLimit(300, 120);
}

void Config::Update()
{
	cb_back.Update();

	ag_se.Update();
	ag_bgm.Update();
	ag_master.Update();

	if (cb_back.GetButton()) {
		//‰¹—Ê‚ÌÝ’è
		sound_mgr.SetMasterVolume(ag_master.GetVolume());
		sound_mgr.SetBGMVolume(ag_bgm.GetVolume());
		sound_mgr.SetSEVolume(ag_se.GetVolume());

		mSceneChanger->ChangeScene(eScene_Menu);
	}
}

void Config::Draw()
{
	cb_back.Draw();
	Circle(cb_back.GetX(), cb_back.GetY(), 10).drawFrame(0.5, 8, Color(COLOR_CONFIG_BACKGROUND));

	c_se.Draw();
	c_bgm.Draw();
	c_master.Draw();

	ag_se.Draw();
	ag_bgm.Draw();
	ag_master.Draw();

}
