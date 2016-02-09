#include "AllegroCore.h"



AllegroCore::AllegroCore()
{
	display = nullptr;
	timer = nullptr;
	eventQueue = nullptr;
	backgroundImage = nullptr;
	fpsTimeOut = 60;

	views = new BaseView*[3];
}

void AllegroCore::Initialize(int wight, int height) {

	if (!al_init()) {
		throw "Allegro initialize error!";
	}
	al_init_image_addon();
	//al_install_mouse(); // Подключение мыши!Ё!

	this->wight = wight;
	this->height = height;

	display = al_create_display(wight, height);
	

	if (display == nullptr) {
		throw "Display creating error!";
	}

	if (!al_install_keyboard()) {
		throw "Instal keyboard error!";
	}

	if (!al_install_mouse()) {
		throw "Instal mouse error!";
	}
	timer = al_create_timer(1.0 / fpsTimeOut);
	if (timer == nullptr) {
		throw "Timer creation error!";
	}
	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr) {
		throw "Event creation error!";
	}

	if (!al_init_font_addon()) {
		throw "Font init  error!";
	}

	if (!al_init_ttf_addon()) {
		throw "TTF init  error!";
	}

	backgroundImage = al_load_bitmap("Resources/Images/Menu.jpg");
	mainFont = al_load_font("Resources/Fonts/RosewoodStd-Regular.otf", 50, 0);
	setingsFont = al_load_font("Resources/Fonts/RosewoodStd-Regular.otf", 35, 0);

	if (backgroundImage == nullptr) {
		throw "Load image error!";
	}

	al_set_target_bitmap(al_get_backbuffer(display));

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());


	views[(int)ViewType::MainMenu] = new MainMenuView(wight, height, backgroundImage, mainFont, setingsFont);
	//views[(int)ViewType::SettingsMenu] = new SettingsMenuView(wight, height, backgroundImage, mainFont, setingsFont);

	currentView = views[(int)ViewType::MainMenu];

}

void AllegroCore::StartGame() 
{

	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	
	while (true) {
		al_wait_for_event(eventQueue, &ev);

		//currentView->processEvent(ev);         // TO DO!!!!

		//al_get_mouse_state(&state);

		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue)) 
		{				
			currentView->Update();

			al_flip_display();
		}

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
		//	printf("Mouse position (%d, %d)\n", state.x, state.y);
		cout<<" x:"<< ev.mouse.x << " y:" << ev.mouse.y;

			ViewType menu =	currentView->CheckForSwitchMenu(ev.mouse.x, ev.mouse.y);
			currentView = views[(int)menu];
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	}
}


AllegroCore::~AllegroCore()
{
	if (display != nullptr) {
		al_destroy_display(display);
	}
	if (timer != nullptr) {
		al_destroy_timer(timer);
	}
	if (eventQueue != nullptr) {
		al_destroy_event_queue(eventQueue);
	}
}
