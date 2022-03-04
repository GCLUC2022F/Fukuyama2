#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
#include "CTask.h"
#include "CTaskManager.h"
#include "CRectangle.h"

class CCollisionManager : public CTaskManager {
public:
	static CCollisionManager* Get();

	void Collision();

private:
	static CCollisionManager* mpInstance;
};

#endif // !CCOLLISIONMANAGER_H

