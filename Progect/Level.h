#pragma once
#include "Header.h"
#include "Opponents.h"
#include "Vector2.h"

class Level
{
	const int NUM_Opponents = 5;
	vector<Vector2> spawnPoints;

	list<Opponents> opponent;
	//������ ��������� ����

	list<Opponents> visibleOpponents;
	//������ ��������� ������� � ������ ������ ����

	void CreateOpponent();
	Level* level;
	
public:
	

	Level(); // ������� �������

	void Update();
	void Initialize(int opponentCount);
	list<Opponents>* GetOpponents();

	~Level();
};

