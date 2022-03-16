#include "CSceneTitle.h"
#include "CKey.h"
#include "CPlayer.h"

void CSceneTitle::Init() {
	//�V�[���̐ݒ�
	mSwitch = 1;
	mScene = ETITLE;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneTitle::Update() {
	if (CKey::Once('S') && mSwitch < 2) {
		CPlayer::Gender = 2;
		mSwitch++;
	}
	
	if (CKey::Once('W') && mSwitch > 1) {
		CPlayer::Gender = 1;
		mSwitch--;
	}










	//������̕`��
	if (mSwitch == 1) {
		CText::DrawMiddle("Player boy", 0, 0, 32, 32, 10, 0.7);
		CText::DrawMiddle("Player girl", 0, -100, 16, 16, 11, 0.7);

	}
	if (mSwitch == 2) {
		CText::DrawMiddle("Player boy", 0, 0, 16, 16, 10, 0.7);
		CText::DrawMiddle("Player girl", 0, -100, 32, 32, 11, 0.7);
	}

	CText::DrawString("TITLE", -200, 300, 50, 50);
	CText::DrawString("Push ENTER Key",-200, -400, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
}
//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
