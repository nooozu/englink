#include "Config.h"
#include "Game.h"
#include "Result.h"
#include "Menu.h"
#include "Ranking.h"
#include "Title.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() : mNextScene(eScene_None)
{
    mScene = (BaseScene*) new Title(this);
}

void SceneMgr::Initialize()
{
    mScene->Initialize();

	sound_mgr.Load(L"sound/BGM_start.mp3");
	sound_mgr.Load(L"sound/play_BGM.mp3");
	sound_mgr.Load(L"sound/button.mp3");
	sound_mgr.Load(L"sound/circle.mp3");

	sound_mgr.PlayLoop(0);
}

void SceneMgr::Finalize()
{
    mScene->Finalize();
}

void SceneMgr::Update()
{
    if (mNextScene != eScene_None) {
        mScene->Finalize();
        delete mScene;
        switch (mNextScene) {
        case eScene_Menu:
			sound_mgr.Play(2);
			sound_mgr.Stop(1);
			sound_mgr.Stop(0);
			sound_mgr.PlayLoop(0);
            mScene = (BaseScene*) new Menu(this);
            break;
        case eScene_Game:
			sound_mgr.Play(3);
			sound_mgr.Stop(0);
			sound_mgr.PlayLoop(1);
            mScene = (BaseScene*) new Game(this);
            break;
		case eScene_Result:
			sound_mgr.Stop(1);
			sound_mgr.PlayLoop(0);
			mScene = (BaseScene*) new Result(this);
			break;
        case eScene_Config:
			sound_mgr.Play(3);
            mScene = (BaseScene*) new Config(this);
            break;
		case eScene_Ranking:
			sound_mgr.Play(3);
			mScene = (BaseScene*) new Ranking(this);
			break;
		case eScene_Title:
			mScene = (BaseScene*) new Title(this);
			break;
        }
        mNextScene = eScene_None;
        mScene->Initialize();
    }

    mScene->Update();
}

void SceneMgr::Draw()
{
    mScene->Draw();
}

void SceneMgr::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;
}
