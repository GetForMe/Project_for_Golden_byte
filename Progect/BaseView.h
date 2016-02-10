#pragma once
#include "AllegroHeader.h"
#include"CoreEnumeration.h"

class BaseView
{
protected:
	int width;
	int height;
	ALLEGRO_BITMAP *backgroundImage; // Картинка заднего фона 
	ALLEGRO_FONT *mainFont;          // Стиль текста 
	ALLEGRO_FONT *setingsFont;       // Стиль текста 
	ALLEGRO_BITMAP *settingsfon;     // Картинка заднего фона 
public:
	BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon);
	virtual void Update() = 0;
	virtual ViewType CheckForSwitchMenu(int x, int y) = 0;
};

