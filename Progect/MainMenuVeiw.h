#pragma once
#include "BaseView.h"

class MainMenuView : BaseView
{

public:
	MainMenuView(int wight, int height, ALLEGO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);
	virtual void Update();
	~MainMenuView();
};