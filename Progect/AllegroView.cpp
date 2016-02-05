#include "AllegroView.h"

Direction AllegroView::GetDirection(ALLEGRO_EVENT& ev)
{
	switch (ev.keyboard.keycode)
	{
	case ALLEGRO_KEY_LEFT:return Direction::Left;
	case ALLEGRO_KEY_UP:return Direction::Up;
	case ALLEGRO_KEY_DOWN:return Direction::Down;
	case ALLEGRO_KEY_RIGHT:return Direction::Right;

	default: return Direction::Note; break;
	}
}

AllegroView::AllegroView()
{
	display = nullptr;
	timer = nullptr;
	eventQueue = nullptr;
	backgroundImage = nullptr;

	fpsTimeOut = 60;
}

void AllegroView::Initialize(int wight, int height, int r, int g, int b)
{
	if (!al_init())//инициализация библиотеки
	{
		throw "Allegro initialize error!";
	}

	al_init_image_addon();

	//Создание дисплея по wight, height
	this->wight = wight;
	this->height = height;

	display = al_create_display(wight, height);
	if (display == nullptr)
	{
		throw "Display creation error!";
	}

	if (!al_install_keyboard())
	{
		throw "Instal keyboard error!";
	}

	//Создание таймера
	timer = al_create_timer(1.0 / fpsTimeOut);
	if (timer == nullptr)
	{
		throw "Timer creation error!";
	}

	//Создание очереди собитий
	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr)
	{
		throw "Event creation error!";
	}

	//загрузка фона
	backgroundImage = al_load_bitmap("Resources/Images/spaceBackground.jpg");
	mainAtlas = al_load_bitmap("Resources/Images/mainAtlas.png");

	if (backgroundImage == nullptr || mainAtlas == nullptr){
		throw "Load image error!";
	}
	if (backgroundImage == nullptr)
	{
		throw "Load image error!";
	}

	//цель отрисовки отрисовуются в буфер
	al_set_target_bitmap(al_get_backbuffer(display));

	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
	backgroundColor.a = 0;

	//регестация собития
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());


	//al_rest(5); // Sleep(5000)

}

void AllegroView::StartGame(Level &level)
{
	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	Direction direction = Direction::Note;
	Direction lastDirection = Direction::Right;
	int x = 0;
	int y = 0;

	al_convert_mask_to_alpha(mainAtlas, al_map_rgb(0,0,0));

	Ship* player = const_cast<Ship*>(level.GetPlayerShip());

	while (true)
	{
		al_wait_for_event(eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			direction = GetDirection(ev);
			if (direction != Direction::Note)
				lastDirection = direction;
			
			cout << (int)lastDirection << endl;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			direction = Direction::Note;
			

		}
		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue))
		{
			

			//al_clear_to_color(backgroundColor);//очищает окно и задает цвет
			//al_flip_display();//подменяет видимую часть на буфер(меняет местами буфер и видимую часть)
			al_draw_bitmap(backgroundImage, 0, 0, 0);

			player->SetDirection(direction);
			level.LevelTimerTick();
			player->SetDirection(lastDirection);
			
			for (int i = 0; i < level.GetObjectCount(); i++){
				Movable* ship = dynamic_cast<Movable*>(level.GetObjectByIndex(i));
				if (ship != nullptr){
					ShowShip(ship);
				}
			}
			al_flip_display();
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) // проверка на закритие окна
		{
			break;
		}
		
	}
}


void AllegroView::ShowShip(Movable* ship){

	ALLEGRO_BITMAP * sum_bitmap = al_create_sub_bitmap(mainAtlas, 28, 42, 16, 16);
	int x = ship->GetX();
	int y = ship->GetY();

	switch (ship->GetDitection()){
	case Direction::Up:


		al_draw_rotated_bitmap(sum_bitmap, 8, 8, x, y, -(ALLEGRO_PI / 2), 0); break;

	case Direction::Down:

		al_draw_rotated_bitmap(sum_bitmap, 8, 8, x, y, ALLEGRO_PI / 2, 0); break;
	case Direction::Left:

		al_draw_rotated_bitmap(sum_bitmap, 8, 8, x, y, ALLEGRO_PI, 0); break;

	case Direction::Right:

		al_draw_bitmap(sum_bitmap, x, y, 0); break;

	}

	
}



AllegroView::~AllegroView()
{
	if (display != nullptr)
	{
		al_destroy_display(display);
	}

	if (timer != nullptr)
	{
		al_destroy_timer(timer);
	}

	if (eventQueue != nullptr)
	{
		al_destroy_event_queue(eventQueue);
	}
}