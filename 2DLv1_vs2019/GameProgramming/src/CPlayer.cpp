#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern CTexture Shadow;
extern CTexture PlayerGirlJump1;
int CPlayer::PLife = PLAYER_LIFE;
int CPlayer::PWeapon = 0;
int CPlayer::Gender = 1;
int CPlayer::Playerx = 0;
int CPlayer::Playery = 0;
bool JumpFlg = false;
int JumpCount = INIT_JUMPCOUNT;
int Jumph = 0;
int JumpMotion = 1;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {
	Playerx = x;
	Playery = z;


	y = z + Jumph;

	if (PLife < 0) {
		PLife = 0;
	}
	if (PLife > 4) {
		PLife = 4;
	}

	JumpMotion = (INIT_JUMPCOUNT - JumpCount) / 4;
	if (JumpMotion > 10) {
		JumpMotion = 10;
	}

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
		z += 3;
		mFy = 1;
		Playery = 1;
		if (z + h > 250) {
			z = 250 - h;
		}
	}
	if (CKey::Push('S')) {
		z -= 3;
		mFy = -1;
		Playery = -1;
		if (z - h < -540) {
			z = -540 + h;
		}
	}

	if (CKey::Once(' ')) {
		if (JumpFlg == false) {
			JumpFlg = true;
		}
	}

	if (JumpFlg == true) {
		if (JumpCount >= 0) {
			Jumph += JumpCount - (INIT_JUMPCOUNT / 2);
			JumpCount -= 1;
			if (JumpCount < 0) {
				JumpCount = INIT_JUMPCOUNT;		
				JumpFlg = false;
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

void CPlayer::DrawShadow() {
	if (mEnabled == true) {
		if (mFx >= 0) {
			CRectangle::DrawShadow(Shadow, 1260 - 70, 1260 + 100, 240 + 210, 240 - 210);
		}
		else {
			CRectangle::DrawShadow(Shadow, 1260 + 100, 1260 - 70, 240 + 210, 240 - 210);
		}
	}
}	

void CPlayer::Render() {
	if (mEnabled == true) {
		if (Gender == 1) {

		}
		else if (Gender == 2) {
			CPlayer::DrawShadow();
			if (mFx >= 0) {
				if (JumpFlg == true) {
					CRectangle::Render(PlayerGirlJump1, 228 - 48 + 400 * (JumpMotion % 5), 228 + 48 + 400 * (JumpMotion % 5), 204 + 116 + 300 * (JumpMotion / 5), 204 - 106 + 300 * (JumpMotion / 5));
				}
				else {
					CRectangle::Render(PlayerGirlJump1, 228 - 48, 228 + 48, 204 + 116, 204 - 106);
				}

			}
			else {
				if (JumpFlg == true) {
					CRectangle::Render(PlayerGirlJump1, 228 + 48 + 400 * (JumpMotion % 5), 228 - 48 + 400 * (JumpMotion % 5), 204 + 116 + 300 * (JumpMotion / 5), 204 - 106 + 300 * (JumpMotion / 5));
				}
				else {
					CRectangle::Render(PlayerGirlJump1, 228 + 48, 228 - 48, 204 + 116, 204 - 106);
				}
			}
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
				z += my;
			}
		}
	}
}
