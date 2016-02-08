#pragma once
#include "AllegroHeader.h"

class BaseView
{
protected:
	int width;
	int height;
	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_FONT *setingsFont;
public:
	BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont);
	virtual void Update() = 0;
};

