#ifndef CBACK_H
#define CBACK_H
#include "CSceneGame.h"
#include "CRectangle.h"

class CBack : public CRectangle {
public:

	CBack();

	void Update();

	void Render();
};

#endif // !CFIELD_H
