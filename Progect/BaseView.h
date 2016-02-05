#pragma once
#include "AllegroHeader.h"

class BaseView
{
protected:
	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT* mainFont;

public:
	BaseView(ALLEGO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);
	virtual void Update() = 0;
};

