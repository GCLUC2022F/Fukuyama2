#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H

#include "CTask.h"

class CTaskManager {
public:
	virtual ~CTaskManager();

	CTaskManager();

	static CTaskManager* Get();

	void Add(CTask* addTask);

	void Update();
	void Render();

	void Remove(CTask* task);

	void Delete();

protected:
	CTask mHead;
	CTask mTail;

private:
	static CTaskManager* mpInstance;
};
extern CTaskManager TaskManager;

#endif // !CTASKMANAGER_H
