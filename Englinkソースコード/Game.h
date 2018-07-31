#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "MyCircleButton.h"
#include "CountDown.h"
#include "Vec2string.h"
#include "GameWave.h"

#define ONE_CIRCLE_TIME (60*10)

class Game : public BaseScene {
private:
	int wave_count, clear_count, time, max_time;
	
	Vec2string v2s_data;
	CountDown count_down;
	MyCircleButton cb_back;
	GameWave* wave;

public :
    Game(ISceneChanger* changer);
	Game::~Game();
    void Initialize() override;
    void Update() override;
    void Draw() override;
	void NextWave();
};
