#pragma once
#include "BaseScene.h"
#include "MyCircleButton.h"
#include "ArcGauge.h"
#include "SoundManager.h"

class Config : public BaseScene {
private:
	MyCircleButton cb_back;
	MyCircle c_se, c_bgm, c_master;
	ArcGauge ag_se, ag_bgm, ag_master;

	SoundManager sound_mgr;
public:
    Config(ISceneChanger* changer);
    void Initialize() override;
    void Update() override;
    void Draw() override;
};
