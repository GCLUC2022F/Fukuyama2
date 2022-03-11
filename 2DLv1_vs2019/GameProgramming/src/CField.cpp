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
		CRectangle::Render(Stagefloor1, 300, 1890,1070, 0);
	}
}