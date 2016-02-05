#pragma once
#include"AllegroHeader.h"
#include"CoreEnumeration.h"


class AllegroCore
{
	ALLEGRO_DISPLAY *display; //дисплей
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;



	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_BITMAP *mainFont;

	BaseView* currentView;

	int wight;
	int height;

	int fpsTimeOut;

	//Direction GetDirection(ALLEGRO_EVENT& ev);
	//void ShowShip(Movable* ship);

public:
	AllegroCore();

	void Initialize(int wight, int height);
	void Game(AllegroCore *Cars);

	~AllegroCore();
};