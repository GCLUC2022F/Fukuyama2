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
	static int PLife;		//‘Ì—Í
	static int PWeapon;		//0‚È‚ç‘fè,1‚È‚çŒy•Ší,2‚È‚çd•Ší

	static int Gender;		//1,3,5‚È‚ç’j,2,4,6‚È‚ç—

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
	bool AttackFlg;
	bool JumpFlg;

	int mFx, mFy;
	int FireCount;

	int StayMotion;
	int MoveMotion;
	int AttackMotion;
	int JumpMotion;
	//36
};

#endif
