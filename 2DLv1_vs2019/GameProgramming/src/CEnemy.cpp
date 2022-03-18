#include "CEnemy.h"
#include "CTexture.h"
#include "CKey.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
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
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16); //Enemy1, 102 - 350, 102 + 350, 290 + 100, 290 - 100
	}
	
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
