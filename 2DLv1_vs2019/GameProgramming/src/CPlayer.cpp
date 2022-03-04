#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
bool Jump = false;
int jumpCount = INIT_JUMPCOUNT;
int Jumph = 0;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {
	y = my + Jumph;

	//staticメソッドはどこからでも呼べる
	if (CKey::Push('A')) {
		x -= 3;
		mFx = -1;
		mFy = 0;
		if (x - w < -400) {
			x = -400 + w;
		}
	}
	if (CKey::Push('D')) {
		x += 3;
		mFx = 1;
		mFy = 0;
		if (x + w > 400) {
			x = 400 - w;
		}
	}
	if (CKey::Push('W')) {
		my += 3;
		mFx = 0;
		mFy = 1;
		if (my + h > 300) {
			my = 300 - h;
		}
	}
	if (CKey::Push('S')) {
		my -= 3;
		mFx = 0;
		mFy = -1;
		if (my - h < -300) {
			my = -300 + h;
		}
	}

	if (CKey::Once(' ')) {
		if (Jump == false) {
			jumpCount = INIT_JUMPCOUNT;
			Jump = true;
		}	
	}

	if (Jump == true) {
		h = 60;
		if (jumpCount >= 0) {
			Jumph += jumpCount - (INIT_JUMPCOUNT / 2);
			jumpCount -= 1;
			if (jumpCount < 0) {
				h = INIT_PLAYERH;
				Jump = false;
			}
		}
	}
	//攻撃で使う予定 ''内はとりあえずJ
	if (CKey::Once('J')) {

	}
	
	//37
	//スペースキーで弾発射
	//0より大きいとき1減算する
	if (FireCount > 0) {
		FireCount--;
	}
	//FireContが0で、かつ、スペースキーで弾発射
	else if( CKey::Once(' ')) {
		CBullet* Bullet = new CBullet();
		//発射位置の設定
		Bullet->x = x;
		Bullet->y = y;
		//移動の値を設定
		Bullet->mFx = mFx * 5;
		Bullet->mFy = mFy * 5;
		//有効にする
		Bullet->mEnabled = true;
		//プレイヤーの弾を設定
		Bullet->mTag = CRectangle::EPLAYERBULLET;
		FireCount = 10;
	}
	//37
}

void CPlayer::Render() {
	CRectangle::Render();//Texture, 146 - 16, 146 + 16, 146 + 16, 146 - 16);
}

//36
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
	if (ry->mTag == EBLOCK) {
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) xの絶対値を求める
			//移動量が少ない方向だけ移動させる
			if (abs(mx) < abs(my)) {
				//Rectをxだけ移動する
				x += mx;
			}
			else {
				//Rectをyだけ移動する
				y += my;
			}
		}
	}
}
