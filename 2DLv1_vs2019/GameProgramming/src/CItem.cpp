#include "CItem.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CField.h"
extern CTexture Item1;

CItem::CItem() {
	mTag = EITEM;
	Itemno = 0;
	mEnabled = false;
	w = INIT_PLAYERH / 10;
	h = INIT_PLAYERH / 10;
	(Droprato > 79 && Droprato <= 85 ? Itemno = 1 :
		Droprato > 85 && Droprato <= 89 ? Itemno = 2 :
		Droprato > 89 && Droprato <= 93 ? Itemno = 3 :
		Droprato > 93 && Droprato <= 97 ? Itemno = 4 :
		Droprato > 97 && Droprato <= 99 ? Itemno = 5 :
		mEnabled = false);
}


void CItem::Update()
{
	if (mEnabled) {
		x -= SCROLL_SPEED;
	}
	if (x < -960 || CPlayer::PLife < 1) {
		mEnabled = false;
	}
}

void CItem::Collision(CRectangle* i, CRectangle* y)
{
	if (i->mTag == EITEM && i->mEnabled == true) {
		if (y->mTag == EPLAYER && y->mEnabled == true) {
			int mx, my;
			if (CRectangle::Collision(y, &mx, &my)) {
				(Itemno == 1 ? CPlayer::PWeapon = 1 :
					Itemno == 2 ? CPlayer::PWeapon = 2 :
					Itemno == 3 ? CPlayer::PLife += PLAYER_LIFE / 4 :
					Itemno == 4 ? CPlayer::PLife += PLAYER_LIFE / 2 :
					Itemno == 5 ? CPlayer::PLife += PLAYER_LIFE :
					mEnabled = false);
				i->mEnabled = false;
			}
		}

	}
}

void CItem::Render()
{
	if (mEnabled) {
		(Itemno == 1 ? CRectangle::Render(Item1, 265 - 170, 265 + 170, 300 + 117, 300 - 117) :
			Itemno == 2 ? CRectangle::Render(Item1, 810 - 205, 810 + 205, 260 + 70, 260 - 70) :
			Itemno == 3 ? CRectangle::Render(Item1, 250 - 155, 250 + 155, 735 + 145, 735 - 145) :
			Itemno == 4 ? CRectangle::Render(Item1, 780 - 180, 780 + 180, 755 + 155, 755 - 155) :
			Itemno == 5 ? CRectangle::Render(Item1, 1317 - 193, 1317 + 193, 720 + 120, 720 - 120) :
			mEnabled = false);
	}
}
