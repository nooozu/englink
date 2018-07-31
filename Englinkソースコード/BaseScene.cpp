#include "BaseScene.h"

int BaseScene::score = 0;
GameMode BaseScene::game_mode = None;

BaseScene::BaseScene(ISceneChanger* changer)
{
    mSceneChanger = changer;
}

void BaseScene::Initialize()
{
	Graphics::SetBackground(background_color);
}