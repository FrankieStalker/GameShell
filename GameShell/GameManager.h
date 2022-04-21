#pragma once
#include <list>
#include "objectmanager.h"
#include "Terrain.h"

class PlayerChar;

class GameManager
{
private:
	int levelNum; //Variable for level number
	int numEnemies; //Variable for number of enemies
	float endLevelTimer; //Variable for end of level time
	int playerLives; //Varable for number of player lives
	int number;
	bool keyCollected;
	int levelProceed;

	//std::list<Terrain*> pTerrainList;
	PlayerChar* pPlayerChar;

public:
	GameManager();
	~GameManager();

	//Creating ObjectManager object
	ObjectManager theObjectManager;

	void StartLevel(int level);
	void Render();
	void Update(float frameTime);

	//bool CollidesGround(Vector2D pos);
	void EnemyDead();
	void PlayerDead();

	void SpawnDoor(Vector2D pos);

	void KeyIsCollected();

	void ProceedLevel();
	void StayAtLevel();

	//void ClearTerrainList();
};

