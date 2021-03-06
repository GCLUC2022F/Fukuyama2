#include "CEnemy.h"
#include "CTexture.h"
#include "CKey.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern CTexture ZakoEnemy;
extern CTexture ZakoAtack;
//CBullet CEnemy::EBullet[20];

CEnemy::CEnemy()
: mFx(0.0f), mFy(0.0f), mFireCount(60),EnemytextuerCount(100),AtackCount(60)
{
	//37
	//mEnabled =true;
	mTag = EENEMY;
	x = 350;
	y = 100;
	w = 100;
	h = 75;
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
	

      Enemyz = pow(CPlayer::Playerx - x, 2) + pow(CPlayer::Playery - y, 2);
		Enemyz = sqrt(Enemyz);
		if (Enemyz >700) {
			EnemyFlg = false;
		}
        if (Enemyz < 250) {
			EnemyFlg = true;
		}
		if(EnemyFlg==true){
			mFx = 1;
		}
		if (EnemyFlg==false) {
			mFx = -3;
		}
		if (AtackCount > 0) {
				AtackCount--;
			}
			if (AtackCount == 0) {
				AtackCount = 60;
			}

if (EnemytextuerCount > 0) {
		EnemytextuerCount--;
	}
if (EnemytextuerCount == 0) {
	EnemytextuerCount = 100;
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
			mEnabled = true;	
			break;
		}
		return true;
	
	}
	return false;
}

void CEnemy::Render() {

	    if (EnemyFlg==true) {
		   if (EnemytextuerCount >= 90) {
		    	CRectangle::Render(ZakoEnemy, 123, 123 + 515, 577, 292);
		   }
		   if (EnemytextuerCount >= 80 && EnemytextuerCount <= 90) {
			    CRectangle::Render(ZakoEnemy, 826, 1345, 581, 287);
		   }
		   if (EnemytextuerCount >= 70 && EnemytextuerCount <= 80) {
			    CRectangle::Render(ZakoEnemy, 1550, 2070, 581, 287);
		   }
		   if (EnemytextuerCount >= 60 && EnemytextuerCount <= 70) {
			    CRectangle::Render(ZakoEnemy, 2275, 2793, 581, 287);
		   }
		   if (EnemytextuerCount >= 50 && EnemytextuerCount <= 60) {
			    CRectangle::Render(ZakoEnemy, 3000, 3515, 581, 287);
		   }
		   if (EnemytextuerCount >= 40 && EnemytextuerCount <= 50) {
			    CRectangle::Render(ZakoEnemy, 102, 619, 1156, 875);
		   }
		   if (EnemytextuerCount >= 30 && EnemytextuerCount <= 40) {
			    CRectangle::Render(ZakoEnemy, 828, 1345, 1156, 875);
		   }
		   if (EnemytextuerCount >= 20 && EnemytextuerCount <= 30) {
			    CRectangle::Render(ZakoEnemy, 1548, 2069, 1156, 875);
		   }
		   if (EnemytextuerCount >= 10 && EnemytextuerCount <= 20) {
		    	CRectangle::Render(ZakoEnemy, 2278, 2791, 1156, 875);
		   }
		   if (EnemytextuerCount >= 0 && EnemytextuerCount <= 10) {
			    CRectangle::Render(ZakoEnemy, 3000, 3515, 1156, 875);
		   }
		   
	    }
	if (EnemyFlg == false) {
			   if (EnemytextuerCount >= 50) {
				   CRectangle::Render(ZakoAtack, 1553, 1553+515, 577, 309);
			   }
			   if (EnemytextuerCount >= 40 && EnemytextuerCount <= 50) {
				   CRectangle::Render(ZakoAtack, 2276, 2276+515, 577,309);
			   }
			   if (EnemytextuerCount >= 30 && EnemytextuerCount <= 40) {
				   CRectangle::Render(ZakoAtack, 2276, 2276 + 515, 577, 309);
			   }
			   if (EnemytextuerCount >= 20 && EnemytextuerCount <= 30) {
				   CRectangle::Render(ZakoAtack, 2970, 3517, 577, 309);
			   }
			   if (EnemytextuerCount >= 10 && EnemytextuerCount <= 20) {
				   CRectangle::Render(ZakoAtack, 103, 103+548, 1157, 884);
			   }
			   if (EnemytextuerCount >= 0 && EnemytextuerCount <= 10) {
				   CRectangle::Render(ZakoAtack,827,827+548 ,1157,884);
			   }
		   }
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
