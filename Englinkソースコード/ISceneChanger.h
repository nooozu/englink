#pragma once

typedef enum {
    eScene_Menu,    //メニュー画面
    eScene_Game,    //ゲーム画面
	eScene_Result,  //リザルト画面
    eScene_Config,  //設定画面
	eScene_Ranking, //ランキング画面
	eScene_Title,   //タイトル画面

    eScene_None,    //無し
} eScene ;

class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void ChangeScene(eScene NextScene) = 0;
};
