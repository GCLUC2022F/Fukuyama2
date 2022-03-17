#ifndef CPLAYER_H
#define CPLAYER_H
#include "CRectangle.h"
#include "CTexture.h"
#define INIT_PLAYERW 100
#define INIT_PLAYERH 250
#define INIT_JUMPCOUNT 40
class CPlayer : public CRectangle {
public:
	static int Gender;	//1,3,5Ç»ÇÁíj,2,4,6Ç»ÇÁèó

	static int Playerx;
	static int Playery;
	//37
	
	CPlayer();
	void Update();
	void DrawShadow();
	void Render();
	void Collision(CRectangle *i, CRectangle *y);

private:
	int mFx, mFy;
	int FireCount;
	//36
};

#endif
