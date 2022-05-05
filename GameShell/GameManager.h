#pragma once
#include <list>
#include "objectmanager.h"
#include "Terrain.h"

//Promise this classs exists
class PlayerChar;
class BossEnemy;

class GameManager
{
private:
	int levelNum; //Variable for level number
	int numEnemies; //Variable for number of enemies
	float endLevelTimer; //Variable for end of level time
	float startLevelTimer; //Variable to store timer before level
	int playerLives; //Varable for number of player lives
	int number; //Variable for storing random number
	bool keyCollected; //Variable to store if key has been colected
	int levelProceed; //Variable for storing the level initiliser

	std::list<Terrain*> pTerrainList; //List of terrians for enemy checks
	PlayerChar* pPlayerChar; //Pointer to the player character
	BossEnemy* pBossEnemy;

public:
	GameManager();
	~GameManager();

	//Creating ObjectManager object
	ObjectManager theObjectManager;

	void StartLevel(int level);
	void Render();
	void Update(float frameTime);

	bool CollidesGround(Vector2D pos);
	void EnemyDead();
	void PlayerDead();

	void SpawnDoor(Vector2D pos);

	void KeyIsCollected();

	void ProceedLevel();
	void StayAtLevel();

	void ClearTerrainList();
	void ClearInactiveTerrain();

	void SetPlayerLives();

	D3DCOLOR BackgroundColour(D3DCOLOR colour);
};

