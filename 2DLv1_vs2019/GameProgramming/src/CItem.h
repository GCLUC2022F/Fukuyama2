#ifndef CITEM_H
#define CITEM_H
#include "CRectangle.h"

class CItem : public CRectangle {
	int Droprato;	//0����99,0~79����,80~85����1,86~89����2,90~93��1,94~97��2,98~99�t����

	CItem();
	void Collision(CRectangle *i,CRectangle *y);

private:
	int Itemno;		//1~5
	void Update();
	void Render();

};





#endif // !CITEM_H



