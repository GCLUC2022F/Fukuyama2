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
		//�e�̕`�惁�\�b�h���Ă�
		CRectangle::Render(Stagefloor1, 0, 1920,1080, 0);
	}
}