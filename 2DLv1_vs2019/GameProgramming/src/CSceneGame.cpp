#include "CSceneGame.h"
#include "CTaskManager.h"
#include "CPlayer.h"
#include "CBack.h"
#include "CField.h"
#include <stdio.h>

//残り時間（30秒）
int Time = 30 * 60;
int Remain = 3;


void CSceneGame::Init() {
	//シーンの設定
	mScene = EGAME;
//37
	CBack *Back = new CBack();
	Back->x = 0;
	Back->y = 0;
	Back->w = 960;
	Back->h = 540;
	Back->mEnabled = true;

	CField *Floor = new CField();
	Floor->x = 0;
	Floor->y = 0;
	Floor->w = 960;
	Floor->h = 540;
	Floor->mEnabled = true;

	//クラスのメンバ変数への代入
//37
	CPlayer *Player = new CPlayer();
	Player->x = -150;
	Player->y = -100;
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
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 50;
				Map->h = 50;
				//37
			}
			else if (map[j][i] == 2) {
				CEnemy *Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = -1;
				Enemy->mFy = 0;
				Enemy->Enemyx = i * -100 - 350;
				Enemy->Enemyy = j * -100 + 250;
			}
			else if (map[j][i] == 3) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->y = j * -100 + 250;
				//右へ移動
				Enemy->mFx = -1;
				Enemy->mFy = -1;
				Enemy->Enemyx = i * -100 - 350;
				Enemy->Enemyy = j * -100 + 250;
			}
			else if (map[j][i] == 4) {
				CEnemy* Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;
				Enemy->y = j * -100 + 250;
				//右へ移動
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
	CTaskManager::Get()->Collision();

	CText::DrawChar('S', -350, 250, 16, 16);
	CText::DrawChar('c', -350 + 32, 250, 16, 16);
	CText::DrawChar('o', -350 + 32 * 2, 250, 16, 16);
	CText::DrawChar('r', -350 + 32 * 3, 250, 16, 16);
	CText::DrawChar('e', -350 + 32 * 4, 250, 16, 16);

	CText::DrawChar('P', 150, -250, 16, 16);
	CText::DrawChar('l', 150 + 32, -250, 16, 16);
	CText::DrawChar('a', 150 + 32 * 2, -250, 16, 16);
	CText::DrawChar('y', 150 + 32 * 3, -250, 16, 16);
	CText::DrawChar('e', 150 + 32 * 4, -250, 16, 16);
	CText::DrawChar('r', 150 + 32 * 5, -250, 16, 16);

	//文字列の描画
	CText::DrawString("Time", 150, 250, 16, 16);
	if (Time > 0) {
		Time--;
	}
	//整数を文字列に変換する
	char buf[10];//9文字までOK
	sprintf(buf, "%d", Time / 60);
	CText::DrawString(buf, 300, 250, 16, 16);

	sprintf(buf, "%d", Remain);
	CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);

}


//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame::~CSceneGame() {
	CTaskManager::Get()->Delete();
}
