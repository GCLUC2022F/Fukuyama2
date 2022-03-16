#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CPlayer.h"
#include "CBack.h"
#include "CField.h"
#include <stdio.h>

//�c�莞�ԁi30�b�j
int Time = 30 * 60;
int Remain = 3;


void CSceneGame::Init() {
	//�V�[���̐ݒ�
	mScene = EGAME;
//37
	CBack *Back = new CBack();
	Back->x = 0;
	Back->y = 0;
	Back->w = 960;
	Back->h = 540;
	Back->mEnabled = true;

	for (int f = 0; f < 2; f++) {
	CField *Floor1 = new CField();
	Floor1->x = 1920 * f;
	Floor1->y = 0;
	Floor1->w = 960;
	Floor1->h = 540;
	Floor1->mEnabled = true;
	}


	//�N���X�̃����o�ϐ��ւ̑��
//37
	CPlayer *Player = new CPlayer();
	Player->x = -350;
	Player->z = -100;
	Player->Playerx = Player->x;
	Player->Playery = Player->y;
	Player->w = INIT_PLAYERW;
	Player->h = INIT_PLAYERH;
	Player->mEnabled = true;
	int map[6][8] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 0, 0, 0, 0, 0, 0, 3, 0 },
		{ 0, 0, 0, 0, 0, 0, 4, 0 },
		{ 0, 0, 0, 0, 0, 1, 4, 0 },
	};
//37	MapSize = 0;	//0��������
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 8; i++) {
			//map�̗v�f��1�̎��A�l�p�`�z�u
			if (map[j][i] == 1) {
				//37
				CMap *Map = new CMap();
				//�l�p�`�ɒl��ݒ�
				Map->mEnabled = true;
				Map->x = i * 240 - 900;
				Map->z = j * -180 + 495;
				Map->y = j * -180 + 495;
				Map->w = 120;
				Map->h = 90;
				//37
			}
			else if (map[j][i] == 2) {
				CEnemy *Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->z = j * -100 + 250;
				Enemy->y = j * -100 + 250;
				//�E�ֈړ�
				Enemy->mFx = -1;
				Enemy->mFy = 0;
				Enemy->Enemyx = i * -100 - 350;
				Enemy->Enemyy = j * -100 + 250;
			}
			else if (map[j][i] == 3) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->z = j * -100 + 250;
				Enemy->y = j * -100 + 250;
				//�E�ֈړ�
				Enemy->mFx = -1;
				Enemy->mFy = -1;
				Enemy->Enemyx = i * -100 - 350;
				Enemy->Enemyy = j * -100 + 250;
			}
			else if (map[j][i] == 4) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->z = j * -100 + 250;
				Enemy->y = j * -100 + 250;
				//�E�ֈړ�
				Enemy->mFx = 1;
				Enemy->mFy = 0;
				Enemy->Enemyx = i * -100 - 350;
				Enemy->Enemyy = j * -100 + 250;
			}
		}
	}
}

void CSceneGame::Update() {

	CTaskManager::Get()->Update();
	CTaskManager::Get()->Render();
	//CTaskManager::Get()->DrawShadow();
	CTaskManager::Get()->Collision();

	//CText::DrawChar('S', -350, 250, 16, 16);
	//CText::DrawChar('c', -350 + 32, 250, 16, 16);
	//CText::DrawChar('o', -350 + 32 * 2, 250, 16, 16);
	//CText::DrawChar('r', -350 + 32 * 3, 250, 16, 16);
	//CText::DrawChar('e', -350 + 32 * 4, 250, 16, 16);

	//CText::DrawChar('P', 150, -250, 16, 16);
	//CText::DrawChar('l', 150 + 32, -250, 16, 16);
	//CText::DrawChar('a', 150 + 32 * 2, -250, 16, 16);
	//CText::DrawChar('y', 150 + 32 * 3, -250, 16, 16);
	//CText::DrawChar('e', 150 + 32 * 4, -250, 16, 16);
	//CText::DrawChar('r', 150 + 32 * 5, -250, 16, 16);

	//������̕`��
	CText::DrawString("Time", 150, 250, 16, 16);
	if (Time > 0) {
		Time--;
	}
	//�����𕶎���ɕϊ�����
	char buf[10];//9�����܂�OK
	sprintf(buf, "%d", Time / 60);
	CText::DrawString(buf, 300, 250, 16, 16);

	sprintf(buf, "%d", Remain);
	CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);

}


//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//�f�X�g���N�^
CSceneGame::~CSceneGame() {
	CTaskManager::Get()->Delete();
}
