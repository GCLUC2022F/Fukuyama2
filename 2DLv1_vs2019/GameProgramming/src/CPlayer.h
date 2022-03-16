#ifndef CPLAYER_H
#define CPLAYER_H
#include "CRectangle.h"
#include "CTexture.h"
#define INIT_PLAYERH 250
#define INIT_PLAYERW 100
#define INIT_JUMPCOUNT 40
class CPlayer : public CRectangle {
public:
	static int Gender;	//1,3,5�Ȃ�j,2,4,6�Ȃ珗

	static int Playerx;
	static int Playery;
	int mFx, mFy;
	//37
	int FireCount;
	
	CPlayer();
	void Update();
	void DrawShadow();
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
};

#endif
