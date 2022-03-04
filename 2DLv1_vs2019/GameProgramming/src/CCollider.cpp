#include "CCollider.h"
#include "CCollisionManager.h"


CCollider::CCollider(CRectangle* parent, float radius) {
	mpParent = parent;		//e
	mRadius = radius;		//”¼Œa

	CCollisionManager::Get()->Add(this);
}

CRectangle* CCollider::Parent() {
	return mpParent;
}


CCollider::~CCollider() {
	CCollisionManager::Get()->Remove(this);
}
