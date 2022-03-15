#ifndef CFIELD_H
#define CFIELD_H
#define SCROLL_SPEED 2
#include "CSceneGame.h"
#include "CRectangle.h"

class CField : public CRectangle {
public:

	CField();

	void Update();

	void Render();
};

#endif // !CFIELD_H
