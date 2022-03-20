#include "CEnemy.h"
#include "CTexture.h"
#include "CKey.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
extern CTexture ZakoEnemy;
//CBullet CEnemy::EBullet[20];

CEnemy::CEnemy()
: mFx(0.0f), mFy(0.0f), mFireCount(60),EnemytextuerCount(100)
{
	//37
//	mEnabled = true;
	mTag = EENEMY;
	x = 350;
	y = 100;
	w = 100;
	h = 75;
	Enemyz = 0;
	EnemyFlg = true;
}

void CEnemy::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//37s
		//�e��4���l���֔��˂���
		for (int i = 0; i < 4; i++) {
			CBullet* EBullet = new CBullet();
			//���W�ݒ�
			EBullet->x = x;
			EBullet->y = y;
			//�ړ��ʐݒ�
			EBullet->mFx = (i - 2) % 2 * 2;
			EBullet->mFy = (i - 1) % 2 * 2;
			//�L���ɂ���
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
		

if (EnemytextuerCount > 0) {
		EnemytextuerCount--;
	}
if (EnemytextuerCount == 0) {
	EnemytextuerCount = 100;
   }

}

/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemy::Collision(const CRectangle &r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//�Փ˂��Ă���Δ��]
			mFx *= -1;
			mFy *= -1;
			break;
		case EPLAYERBULLET:
			//�v���C���[�̒e�ɓ�����ƁA�����ɂ���
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

		if(EnemytextuerCount >= 90 ){
			CRectangle::Render(ZakoEnemy, 123, 123+515, 577, 292);
		}	
		if (EnemytextuerCount>=80 && EnemytextuerCount <= 90) {
			CRectangle::Render(ZakoEnemy, 826, 1345, 581, 287);
		}
		if (EnemytextuerCount>=70 && EnemytextuerCount <= 80) {
			CRectangle::Render(ZakoEnemy, 1550, 2070, 581, 287);
		}
		if (EnemytextuerCount >= 60 && EnemytextuerCount <= 70) {
			CRectangle::Render(ZakoEnemy, 2275, 2793, 581, 287);
		}
		if (EnemytextuerCount >= 50 && EnemytextuerCount <= 60) {
			CRectangle::Render(ZakoEnemy,3000, 3515, 581, 287);
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
	
	
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
