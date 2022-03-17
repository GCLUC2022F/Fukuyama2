#ifndef CITEM_H
#define CITEM_H
#include "CRectangle.h"

class CItem : public CRectangle {



	CItem();
	void Update();
	void Collision();
	void Render();

};





#endif // !CITEM_H



