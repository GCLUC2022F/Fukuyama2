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
//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	Texture.Load("res\\Image.tga");
	Stagefloor1.Load("res\\学校床.png");
	Stageback1.Load("res\\学校背景.png");

	Shadow.Load("res\\影.png");

	//PlayerBoyStay0.Load("res\\.png");
	//PlayerBoyStay1.Load("res\\.png");
	//PlayerBoyStay2.Load("res\\.png");
	//PlayerBoyAttack0.Load("res\\.png");
	//PlayerBoyAttack1.Load("res\\.png");
	//PlayerBoyAttack2.Load("res\\.png");
	//PlayerBoyJump0.Load("res\\.png");
	//PlayerBoyJump1.Load("res\\.png");
	//PlayerBoyJump2.Load("res\\.png");
	//PlayerBoyMove0.Load("res\\.png");
	//PlayerBoyMove1.Load("res\\.png");
	//PlayerBoyMove2.Load("res\\.png");

	PlayerGirlJump0.Load("res\\女プレイヤージャンプ1.png");
	Item1.Load("res\\アイテム現代.png");
	ZakoEnemy.Load("res\\雑魚１-１.png");
	//文字画像の読み込み
	CText::mFont.Load("res\\Cfont.png");
	//シーンマネージャの初期化
	SceneManager.Init();
}
//Update関数
//プログラムの実行中、繰り返し呼ばれる関数
void Update() {
	//シーンマネージャの更新
	SceneManager.Update();
}
