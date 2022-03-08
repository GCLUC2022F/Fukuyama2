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
CTexture Playerboy;
CTexture Playergirljump1;
//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	//
	Texture.Load("res\\Image.tga");
	Playergirljump1.Load("res\\Girljump1.png");
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
