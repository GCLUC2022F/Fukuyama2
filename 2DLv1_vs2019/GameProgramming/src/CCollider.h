#ifndef CCOLLIDER_H
#define CCOLLIDER_H

#include "CRectangle.h"

class CCollisionManager;

class CCollider : public CTask {
	friend CCollisionManager;
public:
	~CCollider();

	CCollider(CRectangle* parent,float radius);

	CRectangle* Parent();

protected:
	CRectangle* mpParent;
	float mRadius;
};

#endif // !CCOLLIDER_H

