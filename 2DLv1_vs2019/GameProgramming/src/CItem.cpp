#include "CItem.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CField.h"

CItem::CItem() {
	Itemno = 0;
	mEnabled = false;
	w = INIT_PLAYERH / 10;
	h = INIT_PLAYERH / 10;

}

void CItem::Update()
{
	if (mEnabled) {
		x -= SCROLL_SPEED;
	}
	if (x < -960) {
		mEnabled = false;
	}
}

void CItem::Collision()
{
	//Itemno ‚É‚æ‚Á‚Ä•Ï‚¦‚é
}

void CItem::Render()
{
	//Itemno ‚É‚æ‚Á‚Ä•Ï‚¦‚é
}
