#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H

#include "CTask.h"

class CTaskManager {
public:
	virtual ~CTaskManager();

	static CTaskManager* Get();

	void Add(CTask* addTask);

	void Update();
	void Render();

	void Remove(CTask* task);

	void Delete();

protected:
	CTaskManager();
	CTask mHead;
	CTask mTail;

private:
	static CTaskManager* mpInstance;
};


#endif // !CTASKMANAGER_H
