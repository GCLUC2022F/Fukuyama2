#ifndef CTASK_H
#define CTASK_H
class CTaskManager;
class CCollisionManager;

class CTask {
	friend CTaskManager;
	friend CCollisionManager;
public:
	CTask()
		:mpNext(nullptr), mpPrev(nullptr), mPriority(0), mEnabled(true)
	{}

	virtual ~CTask() {}

	virtual void Update() {}
	virtual void Render() {}

protected:
	int mPriority;		//—Dæ“x
	bool mEnabled;

private:
	CTask* mpNext;		//Ÿ
	CTask* mpPrev;		//‘O
};

#endif // !CTASK_H

