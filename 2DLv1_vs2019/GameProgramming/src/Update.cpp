#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// テクスチャクラスのインクルード
#include "CTexture.h"
CTexture Texture; //マップの画像
CTexture Stageback1;
CTexture Stagefloor1;
CTexture Shadow;

CTexture PlayerGirlJump1;
CTexture Item1;
//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	Texture.Load("res\\Image.tga");
	Stagefloor1.Load("res\\学校床.png");
	Stageback1.Load("res\\学校背景.png");
	Shadow.Load("res\\影.png");
	PlayerGirlJump1.Load("res\\女プレイヤージャンプ1.png");
	Item1.Load("res\\アイテム現代.png");
	//文字画像の読み込み
	CText::mFont.Load("res\\font.tga");
	//シーンマネージャの初期化
	SceneManager.Init();
}
//Update関数
//プログラムの実行中、繰り返し呼ばれる関数
void Update() {
	//シーンマネージャの更新
	SceneManager.Update();
}
