#ifndef CITEM_H
#define CITEM_H
#include "CRectangle.h"

class CItem : public CRectangle {
	int Droprato;	//0‚©‚ç99,0~79–³‚µ,80~85•Ší1,86~89•Ší2,90~93‰ñ•œ1,94~97‰ñ•œ2,98~99ƒtƒ‹‰ñ•œ

	CItem();
	void Collision(CRectangle *i,CRectangle *y);

private:
	int Itemno;		//1~5
	void Update();
	void Render();

};





#endif // !CITEM_H



