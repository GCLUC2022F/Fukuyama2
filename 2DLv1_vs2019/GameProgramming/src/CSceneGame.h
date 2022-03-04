#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CTaskManager.h"
#include "CText.h"
// �e�N�X�`���N���X�̃C���N���[�h
#include "CTexture.h"
#include "CMap.h"

/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGame : public CScene {
public:

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame();

};

#endif
