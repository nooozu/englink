#pragma once
#include "ISceneChanger.h"
#include "BaseScene.h"
#include "SoundManager.h"

class SceneMgr : public ISceneChanger, Task {

private:
    BaseScene* mScene;
    eScene mNextScene;

	SoundManager sound_mgr;

public:
    SceneMgr();
    void Initialize() override;
    void Finalize() override;
    void Update() override;
    void Draw() override;

    void ChangeScene(eScene NextScene) override;
};