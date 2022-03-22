#include "CTitleBack.h"
#include "CTexture.h"
extern CTexture TitleScene;

CTitleBack::CTitleBack() {
	mTag = EFIELD;
}

void CTitleBack::Update() {

}

void CTitleBack::Render() {
	if (mEnabled) {
		//親の描画メソッドを呼ぶ
		CRectangle::Render(TitleScene, 0, 1920, 1080, 0);
	}
}