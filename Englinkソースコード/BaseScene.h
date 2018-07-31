#pragma once
#include "Task.h"
#include "ISceneChanger.h"
#include "Emitter.h"

typedef enum {
	Practice,
	Exam,

	None,
} GameMode;

class BaseScene : public Task {
protected:
    ISceneChanger* mSceneChanger;
	Color background_color;

	Emitter emitter;

	static int score;
	static GameMode game_mode;

public :
    BaseScene(ISceneChanger* changer);
    virtual ~BaseScene(){}
	virtual void Initialize() override;
    virtual void Finalize() override {}
    virtual void Update() override {}
    virtual void Draw() override {}
};
