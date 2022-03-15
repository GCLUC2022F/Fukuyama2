#include "CField.h"
#include "CTexture.h"
extern CTexture Stagefloor1;

CField::CField() {

	mTag = EFIELD;
}

void CField::Update() {
	x -= SCROLL_SPEED;
	if (x == -1920) {
		x = 1920;
	}
}

void CField::Render() {
	if (mEnabled) {
		//親の描画メソッドを呼ぶ
		CRectangle::Render(Stagefloor1, 0, 1920,1080, 0);
	}
}