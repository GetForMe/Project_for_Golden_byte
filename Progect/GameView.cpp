#include "GameView.h"

GameView::GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon)
	:BaseView(width, height, backgroundImage, mainFont, setingsFont, settingsfon)
{
	trackX = trackY = 0;
}

void GameView::Update()
{
	al_draw_bitmap(backgroundImage, trackX, trackY, 0);
	al_draw_bitmap(backgroundImage, trackX, trackY - height, 0);
	trackY++;
	if (trackY == height)
	{
		trackY = 0;
	}
}

ViewType GameView::CheckForSwitchMenu(int x, int y)
{
	return ViewType::GameView;
}

GameView::~GameView()
{

}