#include "CCollisionManager.h"
#include "CTaskManager.h"
#include "CCollider.h"

CCollisionManager* CCollisionManager::mpInstance = 0;
CCollisionManager* CCollisionManager::Get() {
	if (mpInstance == 0) {
		mpInstance = new CCollisionManager();
	}
	return mpInstance;
}

void CCollisionManager::Collision() {
	CRectangle* task = (CRectangle*)mHead.mpNext;
	while (task->mpNext) {
		CRectangle* next = (CRectangle*)task->mpNext;
		while (next->mpNext) {
			if (task->mpParent)
				task->mpParent->Collision(next, task);
			if (next->mpParent)
				next->mpParent->Collision(next, task);
			next = (CRectangle*)next->mpNext;
		}
		task = (CRectangle*)task->mpNext;
	}
}
