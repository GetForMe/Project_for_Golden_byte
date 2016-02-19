#include "Vector2.h"
//те саме що точка - мiстить параметри кординати x,y
//у Палича це десь називаэться Vector2,
//хоча треба було б назвати клас Coord або Point


Vector2::Vector2()
{
	X = Y = 0;
}


Vector2::Vector2(float x, float y)
{
	X = x;
	Y = y;
}
