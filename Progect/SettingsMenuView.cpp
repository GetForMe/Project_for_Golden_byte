#include "SettingsMenuView.h"



SettingsMenuView::SettingsMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon)
	:BaseView(width, height, backgroundImage, mainFont, setingsFont, settingsfon)
{
	
}

void SettingsMenuView::Update() 
{
	al_draw_bitmap(settingsfon, 0, 0, 0);
	al_draw_text(setingsFont, al_map_rgb(0, 0, 255), width / 5, 150, ALLEGRO_ALIGN_CENTER, "Music");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 200, ALLEGRO_ALIGN_CENTER, "Language");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 250, ALLEGRO_ALIGN_CENTER, "Complication");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 300, ALLEGRO_ALIGN_CENTER, "Back");
}

ViewType SettingsMenuView::CheckForSwitchMenu(int x, int y)
{
	if (x >=87 && x <=172 && y >=300 && y <=326)
	{
	return ViewType::MainMenu; // Если мышка попадает на кнопку Back (надо написать проверку)// Написакть проверку на  return в MainMenu!!!!!
	}
	return ViewType::SettingsMenu;
}									



SettingsMenuView::~SettingsMenuView()
{
}
