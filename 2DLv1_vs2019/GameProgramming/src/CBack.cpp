#include "CBack.h"
#include "CTexture.h"
extern CTexture Stageback1;

CBack::CBack() {
	mTag = EFIELD;
}

void CBack::Update() {

}

void CBack::Render() {
	if (mEnabled) {
		//親の描画メソッドを呼ぶ
		CRectangle::Render(Stageback1, 0, 1920,1080, 0);
	}
}