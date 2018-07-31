#pragma once

typedef enum {
    eScene_Menu,    //���j���[���
    eScene_Game,    //�Q�[�����
	eScene_Result,  //���U���g���
    eScene_Config,  //�ݒ���
	eScene_Ranking, //�����L���O���
	eScene_Title,   //�^�C�g�����

    eScene_None,    //����
} eScene ;

class ISceneChanger {
public:
    virtual ~ISceneChanger() = 0;
    virtual void ChangeScene(eScene NextScene) = 0;
};
