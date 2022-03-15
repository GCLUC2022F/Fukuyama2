#include "CTaskManager.h"

CTaskManager::CTaskManager() {
	mHead.mpNext = &mTail;
	mTail.mpPrev = &mHead;
}

CTaskManager::~CTaskManager() {
}

CTaskManager* CTaskManager::mpInstance = 0;

CTaskManager* CTaskManager::Get()
{
	if (mpInstance == 0) {
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}

void CTaskManager::Add(CTask* addTask) {
	CTask* task = &mTail;
	addTask->mpNext = task;
	addTask->mpPrev = task->mpPrev;
	addTask->mpPrev->mpNext = addTask;
	task->mpPrev = addTask;
}

void CTaskManager::Update() {
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		task->Update();
		task = task->mpNext;
	}
}

void CTaskManager::DrawShadow() {
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		task->DrawShadow();
		task = task->mpNext;
	}
}

void CTaskManager::Render() {
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		task->Render();
		task = task->mpNext;
	}
}

void CTaskManager::Collision() {
	CRectangle* task = (CRectangle*)mHead.mpNext;
	while (task->mpNext) {
		CRectangle* next = (CRectangle*)task->mpNext;
		while (next->mpNext) {
				task->Collision(task, next);
				next->Collision(next, task);
			next = (CRectangle*)next->mpNext;
		}
		task = (CRectangle*)task->mpNext;
	}
}

void CTaskManager::Remove(CTask* task) {
	task->mpPrev->mpNext = task->mpNext;
	task->mpNext->mpPrev = task->mpPrev;
}

void CTaskManager::Delete() {
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		CTask* del = task;
		task = task->mpNext;
		if (del->mEnabled == false) {
			delete del;
		}
	}
}
