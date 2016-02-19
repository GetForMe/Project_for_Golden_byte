#pragma once
#include "BaseView.h"

class GameView : public BaseView
{
	int trackX, trackY;
	ALLEGRO_BITMAP *opponentImage;
	//void processEvent(AEev);

public:
	GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon);
	virtual void Update();
	ViewType CheckForSwitchMenu(int x, int y);
	~GameView();


};