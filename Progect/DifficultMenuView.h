#pragma once
#include "BaseView.h"
class DifficultMenuView:public BaseView
{
public:
	DifficultMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon);
	virtual void Update();
	~DifficultMenuView();
};

