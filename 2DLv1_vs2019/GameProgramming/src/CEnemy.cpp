#include "CEnemy.h"
#include "CTexture.h"
#include "CKey.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
//CBullet CEnemy::EBullet[20];

CEnemy::CEnemy()
: mFx(0.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMY;
	w = 50;
	h = 50;
	
	Enemyz = 0;
	EnemyFlg = true;
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
			CBullet* EBullet = new CBullet();
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
		
	}
	
	x += mFx;
	y += mFy;
	

      Enemyz = pow(CPlayer::Playerx - Enemyx, 2) + pow(CPlayer::Playery - Enemyy, 2);
		Enemyz = sqrt(Enemyz);
		if (Enemyz >700) {
			EnemyFlg = false;
		}
        if (Enemyz < 350) {
			EnemyFlg = true;
		}
		if(EnemyFlg==true){
			mFx = 1;
		}
		if (EnemyFlg==false) {
			mFx = -1;
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
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16); //Enemy1, 102 - 350, 102 + 350, 290 + 100, 290 - 100
	}
	
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
