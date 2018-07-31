#pragma once
#include "BaseScene.h"
#include "MyCircleButton.h"
#include "MyRoll.h"
#include "SoundManager.h"

class Menu : public BaseScene {
private:
	bool IsPlay;

	MyCircle c_main;
	Circle c_main_frame;

	MyCircleButton cb_play, cb_config, cb_ranking, cb_practice, cb_exam, cb_back;

	MyRoll roll[5];

	SoundManager sound_mgr;

public :
    Menu(ISceneChanger* changer);
    void Initialize() override;
    void Update() override;
    void Draw() override;
};
