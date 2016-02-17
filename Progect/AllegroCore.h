#pragma once
#include "AllegroHeader.h"
#include "Header.h"
#include "MainMenuView.h"
#include "SettingsMenuView.h"
#include "CoreEnumeration.h"
#include "GameView.h"

class AllegroCore
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;

	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_FONT *setingsFont;
	ALLEGRO_BITMAP *settingsfon;
	ALLEGRO_BITMAP *gameViewBackground;

	BaseView* currentView;
	
	//todo
	BaseView** views; //views[viewType::MainMenu] = new MainMenu...;
	//views(...
	//init
	//curentVIew=views[(int)ViewType::MainMenu];


	int wight;
	int height;
	int fpsTimeOut;

public:
	AllegroCore();
	void Initialize(int wight, int height);
	void StartGame();
	~AllegroCore();
};

