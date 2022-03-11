#include "CField.h"
#include "CTexture.h"
extern CTexture Stagefloor1;

CField::CField() {

	mTag = EFIELD;
}

void CField::Update() {

}

void CField::Render() {
	if (mEnabled) {
		//親の描画メソッドを呼ぶ
		CRectangle::Render(Stagefloor1, 0, 1920,1080, 0);
	}
}