#include "GameView.h"
#include "Level.h"

GameView::GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon)
	:BaseView(width, height, backgroundImage, mainFont, setingsFont, settingsfon)
{
	trackX = trackY = 0;
	opponentImage = al_create_sub_bitmap("image.img",0,0,0,0);//todo

}

void GameView::Update()
{
	//------------------Track (background) Update
	al_draw_bitmap(backgroundImage, trackX, trackY, 0);
	al_draw_bitmap(backgroundImage, trackX, trackY - height, 0);
	trackY++;
	if (trackY == height)
	{
		trackY = 0;
	}

	//Enamy-Opponent Update
	al_draw_bitmap(opponentImage, 0, 0, 0);//todo
	//list<Opponents>* opponents = level->GetOpponents();//todo

}

ViewType GameView::CheckForSwitchMenu(int x, int y)
{
	return ViewType::GameView;
}

GameView::~GameView()
{

}