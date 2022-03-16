#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
extern CTexture Shadow;
extern CTexture Playergirljump1;
int CPlayer::Gender = 1;
bool JumpFlg = false;
int Jumpcount = INIT_JUMPCOUNT;
int Jumph = 0;
int Jumpmotion = 1;
int Playerx = 0;
int Playery = 0;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {
	y = z + Jumph;

	Jumpmotion = (INIT_JUMPCOUNT - Jumpcount) / 4;
	if (Jumpmotion > 10) {
		Jumpmotion = 10;
	}

	//static���\�b�h�͂ǂ�����ł��Ăׂ�
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
		if (Jumpcount >= 0) {
			Jumph += Jumpcount - (INIT_JUMPCOUNT / 2);
			Jumpcount -= 1;
			if (Jumpcount < 0) {
				Jumpcount = INIT_JUMPCOUNT;		
				JumpFlg = false;
			}
		}
	}
	//�U���Ŏg���\�� ''���͂Ƃ肠����J
	if (CKey::Once('J')) {

	}
	
	//37
	//�X�y�[�X�L�[�Œe����
	//0���傫���Ƃ�1���Z����
	if (FireCount > 0) {
		FireCount--;
	}
	//FireCont��0�ŁA���A�X�y�[�X�L�[�Œe����
	else if( CKey::Once(' ')) {
		CBullet* Bullet = new CBullet();
		//���ˈʒu�̐ݒ�
		Bullet->x = x;
		Bullet->y = y;
		//�ړ��̒l��ݒ�
		Bullet->mFx = mFx * 5;
		Bullet->mFy = mFy * 5;
		//�L���ɂ���
		Bullet->mEnabled = true;
		//�v���C���[�̒e��ݒ�
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
					CRectangle::Render(Playergirljump1, 228 - 48 + 400 * (Jumpmotion % 5), 228 + 48 + 400 * (Jumpmotion % 5), 204 + 106 + 300 * (Jumpmotion / 5), 204 - 106 + 300 * (Jumpmotion / 5));
				}
				else {
					CRectangle::Render(Playergirljump1, 228 - 48, 228 + 48, 204 + 116, 204 - 106);
				}

			}
			else {
				if (JumpFlg == true) {
					CRectangle::Render(Playergirljump1, 228 + 48 + 400 * (Jumpmotion % 5), 228 - 48 + 400 * (Jumpmotion % 5), 204 + 106 + 300 * (Jumpmotion / 5), 204 - 106 + 300 * (Jumpmotion / 5));
				}
				else {
					CRectangle::Render(Playergirljump1, 228 + 48, 228 - 48, 204 + 106, 204 - 106);
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
			//abs(x) x�̐�Βl�����߂�
			//�ړ��ʂ����Ȃ����������ړ�������
			if (abs(mx) < abs(my)) {
				//Rect��x�����ړ�����
				x += mx;
			}
			else {
				//Rect��y�����ړ�����
				z += my;
			}
		}
	}
}
