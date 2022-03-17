#include "CItem.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CField.h"

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

	}
}
