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
		//�e�̕`�惁�\�b�h���Ă�
		CRectangle::Render(Stageback1, 0, 1920,1080, 0);
	}
}