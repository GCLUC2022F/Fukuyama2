#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"
#include "CTexture.h"
#include "CRectangle.h"

class CSceneTitle : public CScene {
public:
	int mSwitch;
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
