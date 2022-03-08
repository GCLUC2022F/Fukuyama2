#ifndef CPLAYER_H
#define CPLAYER_H
#include "CRectangle.h"
#include "CTexture.h"
#define INIT_PLAYERH 100;
#define INIT_PLAYERW 40;
#define INIT_JUMPCOUNT 30

class CPlayer : public CRectangle {
public:
	int mPy;
	int mFx, mFy;
	//37
	int FireCount;
	
	CPlayer();
	void Update();
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
};

#endif
