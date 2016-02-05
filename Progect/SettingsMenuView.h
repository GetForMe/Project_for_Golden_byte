#pragma once
#include "BaseView.h"

class SettingsMenuView :public BaseView
{

public:
	SettingsMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);
	virtual void Update();
	~SettingsMenuView();
};

