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
CTexture TitleScene;
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
CTexture ZakoAtack;

//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	Texture.Load("res\\Image.tga");
	TitleScene.Load("res\\タイトルロゴ背景.png");
	Stagefloor1.Load("res\\学校床.png");
	Stageback1.Load("res\\学校背景.png");

	Shadow.Load("res\\影.png");

	PlayerBoyStay0.Load("res\\男プレイヤー.png");
	PlayerBoyStay1.Load("res\\男プレイヤー拳銃.png");
	PlayerBoyStay2.Load("res\\男プレイヤーアサルト.png");
	PlayerBoyAttack0.Load("res\\男プレイヤーパンチ.png");
	PlayerBoyAttack1.Load("res\\男プレイヤー拳銃発砲.png");
	PlayerBoyAttack2.Load("res\\男プレイヤーアサルト.png");
	PlayerBoyJump0.Load("res\\男プレイヤージャンプ.png");
	PlayerBoyJump1.Load("res\\男プレイヤー拳銃ジャンプ.png");
	PlayerBoyJump2.Load("res\\男プレイヤーアサルトジャンプ.png");
	PlayerBoyMove0.Load("res\\男プレイヤー歩き.png");
	PlayerBoyMove1.Load("res\\男プレイヤー拳銃歩き.png");
	PlayerBoyMove2.Load("res\\男プレイヤーアサルト歩き.png");

	PlayerGirlJump0.Load("res\\女プレイヤージャンプ1.png");
	Item1.Load("res\\アイテム現代.png");
	ZakoEnemy.Load("res\\雑魚１-１.png");
	ZakoAtack.Load("res\\雑魚１-２.png");
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
