#ifndef CBACK_H
#define CBACK_H
#include "CSceneGame.h"
#include "CRectangle.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

class CBack : public CRectangle {
public:

	CBack();

	void Update();

	void Render();
};

#endif // !CFIELD_H
