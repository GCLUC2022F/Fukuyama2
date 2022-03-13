#include "CPlayer.h"
#include "CKey.h"
#include "CBullet.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
extern CTexture Playergirljump1;
bool Jump = false;
int Jumpcount = INIT_JUMPCOUNT;
int mPy = 0;
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
	y = mPy + Jumph;
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
		mPy += 3;
		mFx = 0;
		mFy = 1;
		Playery = 1;
		if (mPy + h > 250) {
			mPy = 250 - h;
		}
	}
	if (CKey::Push('S')) {
		mPy -= 3;
		mFx = 0;
		mFy = -1;
		Playery = -1;
		if (mPy - h < -540) {
			mPy = -540 + h;
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
			//y += Jumpcount - (INIT_JUMPCOUNT / 2);
			Jumph += Jumpcount - (INIT_JUMPCOUNT / 2);
			Jumpcount -= 1;
			if (Jumpcount < 0) {
				Jump = false;
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

void CPlayer::Render() {
	if (mEnabled == true) {
		if (Jump == true) {
			int Px = 400;
			int Py = 300;
			(Jumpcount >= INIT_JUMPCOUNT * 9 / 10) ? CRectangle::Render(Playergirljump1, 223 - 43, 223 + 43, 204 + 106, 204 - 106) :
				Jumpcount < INIT_JUMPCOUNT * 9 / 10 && Jumpcount >= INIT_JUMPCOUNT * 8 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 1, 223 + 43 + Px * 1, 204 + 106, 204 - 106) :
				Jumpcount < INIT_JUMPCOUNT * 8 / 10 && Jumpcount >= INIT_JUMPCOUNT * 7 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 2, 223 + 43 + Px * 2, 204 + 106, 204 - 106) :
				Jumpcount < INIT_JUMPCOUNT * 7 / 10 && Jumpcount >= INIT_JUMPCOUNT * 6 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 3, 223 + 43 + Px * 3, 204 + 106, 204 - 106) :
				Jumpcount < INIT_JUMPCOUNT * 6 / 10 && Jumpcount >= INIT_JUMPCOUNT * 5 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 4, 223 + 43 + Px * 4, 204 + 106, 204 - 106) :
				Jumpcount < INIT_JUMPCOUNT * 5 / 10 && Jumpcount >= INIT_JUMPCOUNT * 4 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43, 223 + 43, 204 + 106 + Py, 204 - 106 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 4 / 10 && Jumpcount >= INIT_JUMPCOUNT * 3 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 1, 223 + 43 + Px * 1, 204 + 106 + Py, 204 - 106 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 3 / 10 && Jumpcount >= INIT_JUMPCOUNT * 2 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 2, 223 + 43 + Px * 2, 204 + 106 + Py, 204 - 106 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 2 / 10 && Jumpcount >= INIT_JUMPCOUNT * 1 / 10 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 3, 223 + 43 + Px * 3, 204 + 106 + Py, 204 - 106 + Py) :
				Jumpcount < INIT_JUMPCOUNT * 1 / 10 && Jumpcount >= 0 ? CRectangle::Render(Playergirljump1, 223 - 43 + Px * 4, 223 + 43 + Px * 4, 204 + 106 + Py, 204 - 106 + Py) :
				mEnabled = false;
		}
		else {
			CRectangle::Render(Playergirljump1, 223 - 43, 223 + 43, 204 + 106, 204 - 106);
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
				mPy += my;
			}
		}
	}
}
