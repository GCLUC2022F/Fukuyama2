#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CPlayer.h"
#include "CBack.h"
#include "CField.h"
#include <stdio.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

//残り時間（30秒）
int Time = 30 * 60;


void CSceneGame::Init() {
	//シーンの設定
	mScene = EGAME;
//37
	CBack *Back = new CBack();
	Back->x = 0;
	Back->y = 0;
	Back->w = WINDOW_WIDTH / 2;
	Back->h = WINDOW_HEIGHT / 2;
	Back->mEnabled = true;

	for (int f = 0; f < 2; f++) {
	CField *Floor1 = new CField();
	Floor1->x = WINDOW_WIDTH * f;
	Floor1->y = 0;
	Floor1->w = WINDOW_WIDTH / 2;
	Floor1->h = WINDOW_HEIGHT / 2;
	Floor1->mEnabled = true;
	}


	//クラスのメンバ変数への代入
//37
	CPlayer *Player = new CPlayer();
	Player->x = -350;
	Player->z = -100;
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
		{ 0, 0, 0, 0, 0, 0, 4, 0 },
	};
//37	MapSize = 0;	//0を代入する
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 8; i++) {
			//mapの要素が1の時、四角形配置
			if (map[j][i] == 1) {
				//37
				CMap *Map = new CMap();
				//四角形に値を設定
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
				//右へ移動
				Enemy->mFx = -1;
				Enemy->mFy = 0;
			}
			else if (map[j][i] == 3) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->z = j * -100 + 250;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = -1;
				Enemy->mFy = -1;
			}
			else if (map[j][i] == 4) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->z = j * -100 + 250;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = 1;
				Enemy->mFy = 0;
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

	//文字列の描画
	//CText::DrawString("Time", 150, 250, 16, 16);
	//if (Time > 0) {
	//	Time--;
	//}
	//整数を文字列に変換する
	char buf[10];//9文字までOK
//	sprintf(buf, "%d", Time / 60);
//	CText::DrawString(buf, 300, 250, 16, 16);
//
//	sprintf(buf, "%d", Remain);
//	CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);
//
}


//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame::~CSceneGame() {
	CTaskManager::Get()->Delete();
}
