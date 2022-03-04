#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CTaskManager.h"
#include "CText.h"
// テクスチャクラスのインクルード
#include "CTexture.h"
#include "CMap.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame : public CScene {
public:

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGame();

};

#endif
