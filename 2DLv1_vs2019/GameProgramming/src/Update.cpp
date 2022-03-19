#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// �e�N�X�`���N���X�̃C���N���[�h
#include "CTexture.h"
CTexture Texture; //�}�b�v�̉摜
CTexture Stageback1;
CTexture Stagefloor1;
CTexture Shadow;

CTexture PlayerBoyStay0;
CTexture PlayerBoyStay1;
CTexture PlayerBoyStay2;
CTexture PlayerBoyAttack0;
CTexture PlayerBoyAttack1;
CTexture PlayerBoyAttack2;
CTexture PlayerBoyJump0;
CTexture PlayerBoyJump1;
CTexture PlayerBoyJump2;
CTexture PlayerBoyMove0;
CTexture PlayerBoyMove1;
CTexture PlayerBoyMove2;

CTexture PlayerGirlJump0;
CTexture Item1;

CTexture ZakoEnemy;
//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;

//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	Texture.Load("res\\Image.tga");
	Stagefloor1.Load("res\\�w�Z��.png");
	Stageback1.Load("res\\�w�Z�w�i.png");
	Shadow.Load("res\\�e.png");
	PlayerGirlJump0.Load("res\\���v���C���[�W�����v1.png");
	Item1.Load("res\\�A�C�e������.png");
	ZakoEnemy.Load("res\\�G���P-�P.png");
	//�����摜�̓ǂݍ���
	CText::mFont.Load("res\\font.png");
	//�V�[���}�l�[�W���̏�����
	SceneManager.Init();
}
//Update�֐�
//�v���O�����̎��s���A�J��Ԃ��Ă΂��֐�
void Update() {
	//�V�[���}�l�[�W���̍X�V
	SceneManager.Update();
}
