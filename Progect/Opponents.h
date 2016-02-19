#pragma once
#include "Header.h"
//#include "GameEnumeration.h" - так у ярослава //todo maybe

class Opponents
{
	int ID;
	int x;
	int y;
	bool live;
	float speed;
	
public:
	Opponents();
	Opponents(int x, int y, int speed);

	int GetX() const;
	int GetY() const;

	void Move();
	~Opponents();
};

