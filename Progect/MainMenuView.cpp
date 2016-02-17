#include "MainMenuView.h"

MainMenuView::MainMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, ALLEGRO_FONT *setingsFont, ALLEGRO_BITMAP *settingsfon)
	:BaseView(width, height, backgroundImage, mainFont, setingsFont, settingsfon)
{

}

//void MainMenuView::ProcessEvent(ALLEGRO_EVENT* ev)              //TO DO!!!!
//{
//	// Управление, проверка события: "нужно ли его обрабатывать"
//	currentController->SetDirection(currentController->GetDirection(ev));
//}

void MainMenuView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(20, 200, 120), width / 2, 10, ALLEGRO_ALIGN_CENTER, "-=  D R E A M   C A R S =-");

	al_draw_text(setingsFont, al_map_rgb(0, 200, 205), width / 5, 150, ALLEGRO_ALIGN_CENTER, "New game");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 200, ALLEGRO_ALIGN_CENTER, "To Continue...");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 250, ALLEGRO_ALIGN_CENTER, "Settings");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 300, ALLEGRO_ALIGN_CENTER, "Rule");
	al_draw_text(setingsFont, al_map_rgb(255, 255, 255), width / 5, 350, ALLEGRO_ALIGN_CENTER, "E X I T");

}

ViewType MainMenuView::CheckForSwitchMenu(int x, int y)
{
	if (x >= 42 && x <= 198 && y >= 149 && y <= 178)
	{
		return ViewType::GameView;
	}

	if (x >=55 && x<=202 && y>=250 && y<=275)
	{
		return ViewType::SettingsMenu;
	}

	if (x >=83 && x <= 175 && y >=350 && y <= 375)
	{
		return ViewType::Exit;
	}
	return ViewType::MainMenu;
}

MainMenuView::~MainMenuView()
{

}
