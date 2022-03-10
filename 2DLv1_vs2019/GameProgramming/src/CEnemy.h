#ifndef CENEMY_H
#define CENEMY_H
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include <math.h>


class CEnemy : public CRectangle {
public:
	float mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	float mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int Enemyx;
	int Enemyy;
	int Enemyz;
	int Enemyza;
	int Enemyzb;
//	bool mEnabled;	//�L���t���O

//37	CBullet EBullet[20];
	int mFireCount;

	CEnemy();

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
};

#endif
