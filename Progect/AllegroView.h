#pragma once
#include"AllegroHeader.h"
#include"CoreEnumeration.h"
#include "level.h"
#include"Header.h"
#include "Movable.h"

class AllegroView
{
	ALLEGRO_DISPLAY *display; //дисплей
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_COLOR backgroundColor;

	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_BITMAP *mainAtlas;
	

	int wight;
	int height;

	int fpsTimeOut;
	Direction GetDirection(ALLEGRO_EVENT& ev);
	void ShowShip(Movable* ship);

public:
	AllegroView();

	void Initialize(int wight, int height, int r, int g, int b);
	void StartGame(Level &level);

	~AllegroView();
};