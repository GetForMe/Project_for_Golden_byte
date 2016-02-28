#pragma once
#include "Header.h"
#include "Opponents.h"
#include "Vector2.h"

class Level
{
	const int NUM_Opponents = 5;
	vector<Vector2> spawnPoints;

	list<Opponents> opponent;
	//список опонентов всех

	list<Opponents> visibleOpponents;
	//список опонентов которые в данный момент есть

	void CreateOpponent();
	Level* level;
	
public:
	

	Level(); // Игровой уровень

	void Update();
	void Initialize(int opponentCount);
	list<Opponents>* GetOpponents();

	~Level();
};

