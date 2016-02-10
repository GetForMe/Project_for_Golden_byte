#pragma once
#include "BaseView.h"


class SettingsMenuView :public BaseView
{

public:
	SettingsMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon);
	virtual void Update();
	ViewType CheckForSwitchMenu(int x, int y);
	~SettingsMenuView();
};

