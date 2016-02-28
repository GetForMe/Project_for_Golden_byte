#include "Level.h"



Level::Level()
{
	Vector2 p1(25, 230);
	Vector2 p2(50, 250);
	Vector2 p3(60, 260);

	spawnPoints.push_back(p1);
	spawnPoints.push_back(p2);
	spawnPoints.push_back(p3);
}

void Level::Initialize(int opponentCount)
{
	for (size_t i = 0;i < opponentCount;i++)
	{
		CreateOpponent();
	}
}

void Level::CreateOpponent()
{
	Vector2 pos = spawnPoints[rand() % spawnPoints.size()];

	Opponents  op(pos.X, pos.Y, 5);
	opponent.push_back(op); //todo
}

void Level::Update()
{
	list<

	if (visibleOpponents.size() == 0) 
	{
		visibleOpponents.push_back(opponent.front());
		//opponent.front() - кидает в список видимьых

		opponent.pop_back;
		//удаляет из общего списка чужих авто
	}
}

list<Opponents>* Level::GetOpponents()
{
	return &visibleOpponents;
}



Level::~Level()
{

}
