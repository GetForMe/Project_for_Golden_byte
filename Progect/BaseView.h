#pragma once
#include "AllegroHeader.h"

class BaseView
{
protected:
	int width;
	int height;
	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT *mainFont;
public:
	BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);
	virtual void Update() = 0;
};

