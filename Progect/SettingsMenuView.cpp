#include "SettingsMenuView.h"



SettingsMenuView::SettingsMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont)
	:BaseView(width, height, backgroundImage, mainFont, setingsFont)
{
	
}

void SettingsMenuView::Update() 
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(0, 0, 255), width / 2, 10, ALLEGRO_ALIGN_CENTER, "Music");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 2, 50, ALLEGRO_ALIGN_CENTER, "Language");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 2, 50, ALLEGRO_ALIGN_CENTER, "E X I T");
}

SettingsMenuView::~SettingsMenuView()
{
}
