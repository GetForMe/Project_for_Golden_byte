#include "MainMenuView.h"

MainMenuView::MainMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont)
	:BaseView(width, height, backgroundImage, mainFont)
{

}

void MainMenuView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(0, 0, 255), width / 2, 10, ALLEGRO_ALIGN_CENTER, "-= C R A Z Y   T E N N I S =-");
//	al_draw_text(mainFont, al_map_rgb(255, 0, 0), width / 2, 200, ALLEGRO_ALIGN_CENTER, "MainMenu");

	al_draw_text(mainFont, al_map_rgb(255, 0, 0), width / 2, 200, ALLEGRO_ALIGN_CENTER, "Settings");
	al_draw_text(mainFont, al_map_rgb(255, 0, 0), width / 2, 300, ALLEGRO_ALIGN_CENTER, "Difficult");

}

MainMenuView::~MainMenuView()
{

}
