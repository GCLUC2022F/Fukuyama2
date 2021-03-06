#ifndef CPLAYER_H
#define CPLAYER_H
#include "CRectangle.h"
#include "CTexture.h"
#define INIT_PLAYERW 100
#define INIT_PLAYERH 250
#define INIT_JUMPCOUNT 40
#define PLAYER_LIFE 4
class CPlayer : public CRectangle {
public:
	static int PLife;		//体力
	static int PWeapon;		//0なら素手,1なら軽武器,2なら重武器

	static int Gender;		//1,3,5なら男,2,4,6なら女

	static int Playerx;
	static int Playery;
	//37
	
	CPlayer();
	void Update();
	void DrawShadow();
	void Render();
	void Collision(CRectangle *i, CRectangle *y);

private:
	bool MoveFlg;
	bool JumpFlg;
	bool AttackFlg;

	int StayMotion;
	int MoveMotion;
	int AttackMotion;
	int JumpMotion;

	int mFx, mFy;
	int FireCount;
	//36
};

#endif
