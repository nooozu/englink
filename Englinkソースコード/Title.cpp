#include "Title.h"

Title::Title(ISceneChanger* changer) : BaseScene(changer)
{
	background_color = Color(COLOR_TITLE_BACKGROUND);
}

void Title::Initialize()
{
	BaseScene::Initialize();

	frame = 0;

	texture = Texture(L"pic/title01_normal.jpg");

	cb_start.Initialize(350, 450, 30);
	cb_start.SetColor(Color(COLOR_TITLE_BUTTON));
}

void Title::Update()
{
	emitter.Update();
	if (frame > 60) {
		emitter.CreateRipple(cb_start.GetX(), cb_start.GetY(), cb_start.GetRadius());
		frame = 0;
	}

	cb_start.Update();
	if(cb_start.GetButton()){
		mSceneChanger->ChangeScene(eScene_Menu);
	}

	frame++;
}

void Title::Draw()
{
	texture.draw();
	emitter.Draw();
	cb_start.Draw();
	Circle(cb_start.GetX(), cb_start.GetY(), 20).drawFrame(5, 7, Color(COLOR_TITLE_BACKGROUND));
}
