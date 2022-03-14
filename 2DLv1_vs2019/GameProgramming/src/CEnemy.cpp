#include "CEnemy.h"
#include "CTexture.h"
#include "CKey.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
//CBullet CEnemy::EBullet[20];
int CPlayer::Playerx = 0;
int CPlayer::Playery = 0;

CEnemy::CEnemy()
: mFx(0.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMY;
	w = 25;
	h = 25;
	Enemyx = 0;
    Enemyy = 0;
	Enemyz = 0;
}

void CEnemy::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//37s
		//弾を4発四方へ発射する
		for (int i = 0; i < 4; i++) {
			CBullet *EBullet = new CBullet();
			//座標設定
			EBullet->x = x;
			EBullet->y = y;
			//移動量設定
			EBullet->mFx = (i - 2) % 2 * 2;
			EBullet->mFy = (i - 1) % 2 * 2;
			//有効にする
			EBullet->mEnabled = true;
			EBullet->mTag = EENEMYBULLET;
		}
		mFireCount = 600;
		//37e
		/* 37
		//敵弾数分繰り返し
		for (int i = 0; i < 20; i++) {
			//無効な弾なら発射する
			if (!EBullet[i].mEnabled) {
				//座標設定
				EBullet[i].x = x;
				EBullet[i].y = y;
				//移動量設定
				EBullet[i].mFx = 2;
				EBullet[i].mFy = 0;
				//有効にする
				EBullet[i].mEnabled = true;
				EBullet[i].mTag = EENEMYBULLET;
				//発射間隔を60フレームにする
				break;
			}
			mFireCount = 60;
		}
		//敵弾数分繰り返し
		for (int i = 0; i < 20; i++) {
			//無効な弾なら発射する
			if (!EBullet[i].mEnabled) {
				//座標設定
				EBullet[i].x = x;
				EBullet[i].y = y;
				//移動量設定
				EBullet[i].mFx = -2;
				EBullet[i].mFy = 0;
				//有効にする
				EBullet[i].mEnabled = true;
				EBullet[i].mTag = EENEMYBULLET;
				//発射間隔を60フレームにする
				break;
			}
			mFireCount = 60;
		}
		//敵弾数分繰り返し
		for (int i = 0; i < 20; i++) {
			//無効な弾なら発射する
			if (!EBullet[i].mEnabled) {
				//座標設定
				EBullet[i].x = x;
				EBullet[i].y = y;
				//移動量設定
				EBullet[i].mFx = 0;
				EBullet[i].mFy = 2;
				//有効にする
				EBullet[i].mEnabled = true;
				EBullet[i].mTag = EENEMYBULLET;
				//発射間隔を60フレームにする
				break;
			}
			mFireCount = 60;
		}
		//敵弾数分繰り返し
		for (int i = 0; i < 20; i++) {
			//無効な弾なら発射する
			if (!EBullet[i].mEnabled) {
				//座標設定
				EBullet[i].x = x;
				EBullet[i].y = y;
				//移動量設定
				EBullet[i].mFx = 0;
				EBullet[i].mFy = -2;
				//有効にする
				EBullet[i].mEnabled = true;
				EBullet[i].mTag = EENEMYBULLET;
				//発射間隔を60フレームにする
				break;
			}
			mFireCount = 60;
		}
		*/
	}
	if (CKey::Push('W')) {
		Enemyy++;
	}
	if (CKey::Push('S')) {
		Enemyy--;
	}
	if (CKey::Push('A')) {
		Enemyx--;
	}
	if (CKey::Push('D')) {
		Enemyx++;
	}
	x += mFx;
	y += mFy;

	if (Enemyy > 0) {  
		//mFy--;
		//Enemyy--;
	}
	if (Enemyy < 0) {
        //mFy++;
		//Enemyy++;	
    }

		Enemyz = sqrtf(((CPlayer::Playerx-Enemyx)^2)+((CPlayer::Playery - Enemyy)^2));
		if (Enemyz < 0) {
		     mFx=1;
	    }

		if (Enemyz > 0) {
		mFx=-1;
	    }
	
	

	
	
}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemy::Collision(const CRectangle &r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//衝突していれば反転
			mFx *= -1;
			mFy *= -1;
			break;
		case EPLAYERBULLET:
			//プレイヤーの弾に当たると、無効にする
			mEnabled = false;
			break;
		case EPLAYER:
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemy::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
	
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
