#include "BaseView.h"

BaseView::BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont)
{
	this->width = width;
	this->height = height;
	this->backgroundImage = backgroundImage;
	this->mainFont = mainFont;
}