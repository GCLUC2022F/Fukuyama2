#include "CSceneTitle.h"
#include "CKey.h"
#include "CPlayer.h"
#include "CTitleBack.h"
#include "CBack.h"

extern CTexture TitleScene;

void CSceneTitle::Init() {
	//シーンの設定
	mSwitch = 1;
	mScene = ETITLE;

	CTitleBack* TBack = new CTitleBack();
	TBack->x = 0;
	TBack->y = 0;
	TBack->w = WINDOW_WIDTH / 2;
	TBack->h = WINDOW_HEIGHT / 2;
	TBack->mEnabled = true;

}

//更新処理のオーバーライド
void CSceneTitle::Update() {

	CTaskManager::Get()->Render();

	if (CKey::Once('S') && mSwitch < 2) {
		CPlayer::Gender = 2;
		mSwitch++;
	}
	
	if (CKey::Once('W') && mSwitch > 1) {
		CPlayer::Gender = 1;
		mSwitch--;
	}










	//文字列の描画
	if (mSwitch == 1) {
		CText::DrawMiddle("Player boy", 0, -120, 32, 32, 10, 0.7);
		CText::DrawMiddle("Player girl", 0, -220, 16, 16, 11, 0.7);

	}
	if (mSwitch == 2) {
		CText::DrawMiddle("Player boy", 0, -120, 16, 16, 10, 0.7);
		CText::DrawMiddle("Player girl", 0, -220, 32, 32, 11, 0.7);
	}

	CText::DrawString("TITLE", -200, 300, 50, 50);
	CText::DrawMiddle("S D select", 0, -320, 16, 16, 10, 0.7);
	CText::DrawString("Push ENTER Key",-200, -380, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = EGAME;
	}


}

//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
