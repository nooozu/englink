#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "MyCircleButton.h"

class Title : public BaseScene {
private:
	Texture texture;
	MyCircleButton cb_start;

	int frame;
public:
	Title::Title(ISceneChanger* changer);
	void Initialize() override;
	void Update() override;
	void Draw() override;
};
