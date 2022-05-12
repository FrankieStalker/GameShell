//Created by w18010435
//Game manager class used to store all the function declarations and variables for GameManager class
//Enum class for LevelState to keep track of level state

#pragma once
#include <list>
#include "objectmanager.h"
#include "Terrain.h"

//Forward declartion
class PlayerChar;
class BossEnemy;
class MySoundEngine;

// enum for current level state
// SUCCESS == Proceed Level
// FAILURE == Restart Level
// CURRENT == Current Level
enum class LevelState {SUCCESS, FAILURE, CURRENT};

class GameManager
{
private:
	int levelNum; // Variable for level number
	int numEnemies; // Variable for number of enemies
	float endLevelTimer; // Variable for end of level time
	float startLevelTimer; // Variable to store timer before level
	int playerLives; // Varable for number of player lives
	int number; // Variable for storing random number
	bool keyCollected; // Variable to store if key has been colected
	LevelState levelState; // Variable for storing the level initiliser
	float deathTimer = 2.0f;

	float successTimer; // Variable for timer till next level after success

	std::list<Terrain*> pTerrainList; //List of terrians for enemy checks
	PlayerChar* pPlayerChar = nullptr; //Pointer to the player character
	BossEnemy* pBossEnemy = nullptr; //Pointer to the boss enemy

public:
	GameManager();
	~GameManager();

	ObjectManager theObjectManager; //Creating ObjectManager object

	void StartLevel(int level); //Called to start level
	void Render(); //Render function
	void Update(float frameTime); //Update function
	
	//Check created for enemy movement
	//Helps with inverting enemy movement if not collidng with ground
	bool CollidesGround(Vector2D pos);

	//If enemy dies -1 to numEnemies
	//If player dies -1 to playerLives
	void EnemyDead();
	void PlayerDead();

	//Sets key collected varible to true when called
	void KeyIsCollected();
	bool GetKeyCollected();

	//Functions to change level state enum for staying or proceeding level
	void ProceedLevel();
	void StayAtLevel();

	//Function to clear terrain list and remove singular terrain when needed
	void ClearTerrainList();
	void RemoveTerrain(Terrain* pT);

	LevelState GetLevelState();

	//Function to set the lives of the player when game is started
	void SetPlayerLives();
};

