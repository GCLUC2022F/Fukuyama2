#ifndef CTASK_H
#define CTASK_H
class CTaskManager;

class CTask {
	friend CTaskManager;
public:
	CTask()
		:mpNext(nullptr), mpPrev(nullptr), mPriority(0), mEnabled(true)
	{}

	virtual ~CTask() {}

	virtual void Update() {}
	virtual void Render() {}

protected:
	int mPriority;		//�D��x
	bool mEnabled;

private:
	CTask* mpNext;		//��
	CTask* mpPrev;		//�O
};

#endif // !CTASK_H

