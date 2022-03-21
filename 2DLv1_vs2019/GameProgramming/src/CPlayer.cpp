#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern CTexture Shadow;

extern CTexture PlayerBoyStay0;
extern CTexture PlayerBoyStay1;
extern CTexture PlayerBoyStay2;
extern CTexture PlayerBoyAttack0;
extern CTexture PlayerBoyAttack1;
extern CTexture PlayerBoyAttack2;
extern CTexture PlayerBoyJump0;
extern CTexture PlayerBoyJump1;
extern CTexture PlayerBoyJump2;
extern CTexture PlayerBoyMove0;
extern CTexture PlayerBoyMove1;
extern CTexture PlayerBoyMove2;

extern CTexture PlayerGirlJump0;
int CPlayer::PLife = PLAYER_LIFE;
int CPlayer::PWeapon = 0;
int CPlayer::Gender = 1;	//基本の性別は男
int CPlayer::Playerx = 0;
int CPlayer::Playery = 0;
int Counter = 0;
int MoveCount = 0;
int JumpCount = INIT_JUMPCOUNT;
int Jumph = 0;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	MoveFlg = false;
	JumpFlg = false;
	AttackFlg = false;

	mTag = EPLAYER;
	StayMotion = 1;
	MoveMotion = 1;
	AttackMotion = 1;
	JumpMotion = 1;
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

	MoveCount += 1;
	if (MoveCount > 119) {
		MoveCount = 0;
	}

	JumpMotion = (INIT_JUMPCOUNT - JumpCount) / 4;
	if (JumpMotion > 10) {
		JumpMotion = 10;
	}

	//staticメソッドはどこからでも呼べる
	if (CKey::Push('A')) {
		x -= 3;
		mFx = -1;
		mFy = 0;
		if (x - w < -960) {
			x = -960 + w;
		}
	}
	if (CKey::Push('D')) {
		x += 3;
		mFx = 1;
		mFy = 0;
		if (x + w > 960) {
			x = 960 - w;
		}
	}
	if (CKey::Push('W')) {
		z += 3;
		mFy = 1;
		if (z + h > 250) {
			z = 250 - h;
		}
	}
	if (CKey::Push('S')) {
		z -= 3;
		mFy = -1;
		if (z - h < -540) {
			z = -540 + h;
		}
	}

	if ((CKey::Push('W') || CKey::Push('A') || CKey::Push('S') || CKey::Push('D')) &&
		!(CKey::Push('W') && CKey::Push('A') && CKey::Push('S') && CKey::Push('D')) &&
		!(CKey::Push('W') && CKey::Push('S') && !CKey::Push('A') && !CKey::Push('D')) &&
		!(!CKey::Push('W') && !CKey::Push('S') && CKey::Push('A') && CKey::Push('D'))) {
		MoveFlg = true;
	}
	else {
		MoveFlg = false;
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
		CPlayer::DrawShadow();
		if (Gender == 1) {
			if (mFx >= 0) {
				if (JumpFlg == true) {
					//正ジャンプ
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyJump0,
						260 - 85 + 500 * (JumpMotion % 5), 260 + 85 + 500 * (JumpMotion % 5),
						260 + 200 + 500 * (JumpMotion / 5), 260 - 200 + 500 * (JumpMotion / 5)) :	//260 260 100 210 500 500
						PWeapon == 1 ? CRectangle::Render(PlayerBoyJump1,
							270 - 120 + 500 * (JumpMotion % 5), 270 + 120 + 500 * (JumpMotion % 5),
							270 + 200 + 500 * (JumpMotion / 5), 270 - 200 + 500 * (JumpMotion / 5)) :	//280 270 130 200 500 500
						PWeapon == 2 ? CRectangle::Render(PlayerBoyJump2,
							280 - 140 + 500 * (JumpMotion % 5), 280 + 140 + 500 * (JumpMotion % 5),
							280 + 240 + 500 * (JumpMotion / 5), 280 - 240 + 500 * (JumpMotion / 5)) :	//280 280 140 240
						mEnabled = false);
				}
				else if (CKey::Push('J')) {
					//正攻撃
					(PWeapon == 0 ? mEnabled = false :
						PWeapon == 1 ? mEnabled = false :
						PWeapon == 2 ? mEnabled = false :
						mEnabled = false);

				}
				else if (MoveFlg == true) {
					//正移動
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyMove0,
						290 - 95 + 500 * ((MoveCount % 60) / 12), 290 + 105 + 500 * ((MoveCount % 60) / 12),
						250 + 200 + 500 * (MoveCount / 60), 250 - 200 + 500 * (MoveCount / 60)) :
						PWeapon == 1 ? CRectangle::Render(PlayerBoyMove1,
							270 - 150 + 500 * ((MoveCount % 60) / 12), 270 + 150 + 500 * ((MoveCount % 60) / 12),
							270 + 210 + 500 * (MoveCount / 60), 270 - 210 + 500 * (MoveCount / 60)) :	//280 270 140 210
						PWeapon == 2 ? CRectangle::Render(PlayerBoyMove2,
							110 - 40 + 500 * ((MoveCount % 60) / 15), 110 + 40 + 500 * ((MoveCount % 60) / 15),
							105 + 70 + 500 * (MoveCount / 60), 105 - 70 + 500 * (MoveCount / 60)) :	//110 105 40 65 8
						mEnabled = false);

				}
				else {
					//正待機
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyStay0,
						265 - 85 + 500 * ((MoveCount % 60) / 12), 265 + 105 + 500 * ((MoveCount % 60) / 12),
						310 + 200 + 500 * (MoveCount / 60), 310 -200 + 500 * (MoveCount / 60)) :
						PWeapon == 1 ? CRectangle::Render(PlayerBoyStay1,
							270 - 150 + 500 * ((MoveCount % 60) / 12), 270 + 150 + 500 * ((MoveCount % 60) / 12),
							270 + 210 + 500 * (MoveCount / 60), 270 - 210 + 500 * (MoveCount / 60)) :
						PWeapon == 2 ? CRectangle::Render(PlayerBoyStay2,
							150 - 60 + 500 * ((MoveCount % 60) / 20), 150 + 60 + 500 * ((MoveCount % 60) / 20),
							140 + 90 + 500 * (MoveCount / 60), 140 - 90 + 500 * (MoveCount / 60)) ://150 140 60 90 6
						mEnabled = false);
				}
			}
			else {
				if (JumpFlg == true) {
					//逆ジャンプ
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyJump0,
						260 + 85 + 500 * (JumpMotion % 5), 260 - 85 + 500 * (JumpMotion % 5),
						260 + 200 + 500 * (JumpMotion / 5), 260 - 200 + 500 * (JumpMotion / 5)) :	//260 260 100 210 400 500
						PWeapon == 1 ? CRectangle::Render(PlayerBoyJump1,
							270 + 120 + 500 * (JumpMotion % 5), 270 - 120 + 500 * (JumpMotion % 5),
							270 + 200 + 500 * (JumpMotion / 5), 270 - 200 + 500 * (JumpMotion / 5)) :	//280 270 130 200 500 500
						PWeapon == 2 ? CRectangle::Render(PlayerBoyJump2,
							280 + 140 + 500 * (JumpMotion % 5), 280 - 140 + 500 * (JumpMotion % 5),
							280 + 240 + 500 * (JumpMotion / 5), 280 - 240 + 500 * (JumpMotion / 5)) :	//280 280 140 240
						mEnabled = false);
				}
				else if (CKey::Push('J')) {
					//逆攻撃
					(PWeapon == 0 ? mEnabled = false :
						PWeapon == 1 ? mEnabled = false :
						PWeapon == 2 ? mEnabled = false :
						mEnabled = false);

				}
				else if (MoveFlg == true) {
					//逆移動
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyMove0,
						 290 + 105 + 500 * ((MoveCount % 60) / 12),290 - 95 + 500 * ((MoveCount % 60) / 12),
						250 + 200 + 500 * (MoveCount / 60), 250 - 200 + 500 * (MoveCount / 60)) :
						PWeapon == 1 ? CRectangle::Render(PlayerBoyMove1,
							270 + 150 + 500 * ((MoveCount % 60) / 12), 270 - 150 + 500 * ((MoveCount % 60) / 12),
							270 + 210 + 500 * (MoveCount / 60), 270 - 210 + 500 * (MoveCount / 60)) :	//280 270 140 210
						PWeapon == 2 ? CRectangle::Render(PlayerBoyMove2,
							110 + 40 + 500 * ((MoveCount % 60) / 12), 110 - 40 + 500 * ((MoveCount % 60) / 12),
							105 + 70 + 500 * (MoveCount / 60), 105 - 70 + 500 * (MoveCount / 60)) :	//110 105 40 65 8
						mEnabled = false);

				}
				else {
					//逆待機
					(PWeapon == 0 ? CRectangle::Render(PlayerBoyStay0,
						265 + 105 + 500 * ((MoveCount % 60) / 12), 265 - 85 + 500 * ((MoveCount % 60) / 12),
						310 + 200 + 500 * (MoveCount / 60), 310 - 200 + 500 * (MoveCount / 60)) :
						PWeapon == 1 ? CRectangle::Render(PlayerBoyStay1,
							270 + 150 + 500 * ((MoveCount % 60) / 12), 270 - 150 + 500 * ((MoveCount % 60) / 12),
							270 + 210 + 500 * (MoveCount / 60), 270 - 210 + 500 * (MoveCount / 60)) :
						PWeapon == 2 ? CRectangle::Render(PlayerBoyStay2,
							150 + 60 + 500 * ((MoveCount % 60) / 12), 150 - 60 + 500 * ((MoveCount % 60) / 12),
							140 + 90 + 500 * (MoveCount / 60), 140 - 90 + 500 * (MoveCount / 60)) ://150 140 60 90 6
						mEnabled = false);
				}
			}
		}
		else if (Gender == 2) {
			if (mFx >= 0) {
				if (JumpFlg == true) {
					CRectangle::Render(PlayerGirlJump0, 228 - 48 + 400 * (JumpMotion % 5), 228 + 48 + 400 * (JumpMotion % 5), 209 + 111 + 300 * (JumpMotion / 5), 209 - 111 + 300 * (JumpMotion / 5));
				}
				else {
					CRectangle::Render(PlayerGirlJump0, 228 - 48, 228 + 48, 209 + 111, 209 - 111);
				}
			}
			else {
				if (JumpFlg == true) {
					CRectangle::Render(PlayerGirlJump0, 228 + 48 + 400 * (JumpMotion % 5), 228 - 48 + 400 * (JumpMotion % 5), 209 + 111 + 300 * (JumpMotion / 5), 209 - 111 + 300 * (JumpMotion / 5));
				}
				else {
					CRectangle::Render(PlayerGirlJump0, 228 + 48, 228 - 48, 209 + 111, 209 - 111);
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
