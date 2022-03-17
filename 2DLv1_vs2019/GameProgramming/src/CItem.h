#ifndef CITEM_H
#define CITEM_H
#include "CRectangle.h"

class CItem : public CRectangle {

	int Itemno;

	CItem();
	void Update();
	void Collision();
	void Render();

};





#endif // !CITEM_H



