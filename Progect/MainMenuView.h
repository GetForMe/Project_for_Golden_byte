#pragma once
#include "BaseView.h"

class MainMenuView : public BaseView
{
public:
	MainMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont);
	virtual void Update();
	~MainMenuView();
};

