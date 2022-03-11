#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern CTexture Playergirljump1;
bool Jump = false;
int Jumpcount = INIT_JUMPCOUNT;
int Jumph = 0;
int Playerx = 0;
int Playery = 0;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {

	//staticメソッドはどこからでも呼べる
	if (CKey::Push('A')) {
		x -= 3;
		mFx = -1;
        Playerx = -1;
		mFy = 0;
		if (x - w < -960) {
			x = -960 + w;
		}
	}
	if (CKey::Push('D')) {
		x += 3;
		mFx = 1;
		Playerx = 1;
		mFy = 0;
		if (x + w > 960) {
			x = 960 - w;
		}
	}
	if (CKey::Push('W')) {
		y += 3;
		mFx = 0;
		mFy = 1;
		Playery = 1;
		if (y + h > 250 + Jumph) {
			y = 250 - h;
		}
	}
	if (CKey::Push('S')) {
		y -= 3;
		mFx = 0;
		mFy = -1;
		Playery = -1;
		if (y - h < -540) {
			y = -540 + h;
		}
	}

	if (CKey::Once(' ')) {
		if (Jump == false) {
			Jumpcount = INIT_JUMPCOUNT;		
			Jump = true;
		}
	}

	if (Jump == true) {
		if (Jumpcount >= 0) {
			y += Jumpcount - (INIT_JUMPCOUNT / 2);
			Jumph = Jumpcount - (INIT_JUMPCOUNT / 2);
			Jumpcount -= 1;
			if (Jumpcount < 0) {
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
	if (mEnabled == true) {
		if (Jump == true) {
			int Px = 406;
			int Py = 310;
			(Jumpcount >= INIT_JUMPCOUNT * 9 / 10) ? CRectangle::Render(Playergirljump1, 220 - 60, 220 + 60, 220 + 110, 220 - 130) :
				Jumpcount < INIT_JUMPCOUNT * 9 / 10 && Jumpcount >= INIT_JUMPCOUNT * 8 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 1, 220 + 60 + Px * 1, 220 + 110, 220 - 130) :
				Jumpcount < INIT_JUMPCOUNT * 8 / 10 && Jumpcount >= INIT_JUMPCOUNT * 7 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 2, 220 + 60 + Px * 2, 220 + 110, 220 - 130):
				Jumpcount < INIT_JUMPCOUNT * 7 / 10 && Jumpcount >= INIT_JUMPCOUNT * 6 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 3, 220 + 60 + Px * 3, 220 + 110, 220 - 130) :
				Jumpcount < INIT_JUMPCOUNT * 6 / 10 && Jumpcount >= INIT_JUMPCOUNT * 5 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 4, 220 + 60 + Px * 4, 220 + 110, 220 - 130) :
				Jumpcount < INIT_JUMPCOUNT * 5 / 10 && Jumpcount >= INIT_JUMPCOUNT * 4 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60, 220 + 60, 220 + 110 + Py, 220 - 130 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 4 / 10 && Jumpcount >= INIT_JUMPCOUNT * 3 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 1, 220 + 60 + Px * 1, 220 + 110 + Py, 220 - 130 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 3 / 10 && Jumpcount >= INIT_JUMPCOUNT * 2 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 2, 220 + 60 + Px * 2, 220 + 110 + Py, 220 - 130 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 2 / 10 && Jumpcount >= INIT_JUMPCOUNT * 1 / 10 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 3, 220 + 60 + Px * 3, 220 + 110 + Py, 220 - 130 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 1 / 10 && Jumpcount >= 0 ? CRectangle::Render(Playergirljump1, 220 - 60 + Px * 4, 220 + 60 + Px * 4, 220 + 110 + Py, 220 - 130 + Py) :
				mEnabled = false;
		}
		else {
			CRectangle::Render(Playergirljump1, 220 - 60, 220 + 60, 220 + 110, 220 - 130);
		}
	}
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
