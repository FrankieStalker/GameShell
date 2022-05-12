//Created by w18010435
//Contains all the declarations for GameManager class
//Allowing level loading with file streaming
//Changing game state depending on player success or failure
//Overall most of the game comes through this file

#include <fstream>

#include "gamecode.h"
#include "GameManager.h"
#include "Terrain.h"
#include "VerticalTerrain.h"
#include "Enemy.h"
#include "FlyingEnemy.h"
#include "BossEnemey.h"
#include "PlayerChar.h"
#include "rock.h"
#include "Spikes.h"
#include "Key.h"
#include "Door.h"

GameManager::GameManager()
{
	playerLives = 3; //Initilise player lives
}

GameManager::~GameManager(){}

void GameManager::StartLevel(int level)
{
    levelNum = level;
	startLevelTimer = -2.0f;
	successTimer = 5.0f;
	std::ifstream levelName;
	number = rand() % 4; //Random number for key location
	
	if (levelNum == 1) //Run level 1 code
	{
		//Delete all objects at the start of the level
		//Clear all objects of previous level
		theObjectManager.DeleteAllObjects();
		ClearTerrainList();

		numEnemies = 10;

		levelState = LevelState::CURRENT;
		keyCollected = false;
		endLevelTimer = 100.0f;

		levelName.open("level1.txt");

		//Check for what number was generated
		//Create key at that numbers location
		if (number == 0)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(250, -1700), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 1)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(2600, -2600), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 2)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(0, -4400), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 3)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(-3100, -4300), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 4)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(0, -2700), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
	}

	if (levelNum == 2) //Run level 2 code
	{
		//Delete all objects at the start of the level
		//Clear all objects of previous level
		theObjectManager.DeleteAllObjects();
		ClearTerrainList();

		levelState = LevelState::CURRENT;
		keyCollected = false;
		endLevelTimer = 25.0f;

		levelName.open("level2.txt");

		//Check for what number was generated
		//Create key at that numbers location
		if (number == 0)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(3100, -7100), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 1)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(0, -7100), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 2)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(-1000, -7500), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 3)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(2600, -7500), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
		if (number == 4)
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(3100, -5900), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
	}

	if (levelNum == 3)
	{
		theObjectManager.DeleteAllObjects();
		ClearTerrainList();

		levelState = LevelState::CURRENT;
		keyCollected = false;
		endLevelTimer = 50.0f;

		levelName.open("level3.txt");
	}

	if (levelNum == 4)
	{
		theObjectManager.DeleteAllObjects();
		ClearTerrainList();

		levelState = LevelState::CURRENT;

		levelName.open("level4.txt");
	}
		
	while (levelName)
	{
		char a;
		levelName >> a; //Takes type of object
		float x; 
		levelName >> x; //Takes x cord
		float y; 
		levelName >> y; //Takes y cord

		if (a == 't') //If t appears in the file create a platform
		{
			Terrain* t = new Terrain();
			t->Initialise(Vector2D(x, y), 1.0f, &theObjectManager, this);
			theObjectManager.AddObject(t);
			pTerrainList.push_back(t);
		}

		if (a == 'v') //If t appears in the file create a platform
		{
			VerticalTerrain* vt = new VerticalTerrain();
			vt->Initialise(Vector2D(x, y), 1.0f, &theObjectManager, this);
			theObjectManager.AddObject(vt);
			//pTerrainList.push_back(vt);
		}

		if (a == 'b') //If b appears in the file create a collision box
		{
			Rock* pRock = new Rock();
			pRock->Initialise(Vector2D(x, y), &theObjectManager, this);
			theObjectManager.AddObject(pRock);
		}

		if (a == 'f') //If f appears in the file create a flying enemy
		{
			FlyingEnemy* pFlyingEnemy = new FlyingEnemy();
			Vector2D vel(rand() % -500 + 500, 0);
			pFlyingEnemy->Initialise(Vector2D(x, y), vel, 0.5f, 1.55f, &theObjectManager, this);
			theObjectManager.AddObject(pFlyingEnemy);
		}

		if (a == 'y') //If y appears in the file create a vertical flying enemy
		{
			FlyingEnemy* pFlyingEnemy = new FlyingEnemy();
			Vector2D vel(0, rand() % -500 + 500);
			pFlyingEnemy->Initialise(Vector2D(x, y), vel, 0.5f, 0.0f, &theObjectManager, this);
			theObjectManager.AddObject(pFlyingEnemy);
		}

		if (a == 'e') //If e appears in the file create an enemy
		{
			Enemy* pEnemy = new Enemy();
			Vector2D vel(rand() % -500 + 500, 0);
			pEnemy->Initialise(Vector2D(x, y), vel, 0.5f, &theObjectManager, this);
			theObjectManager.AddObject(pEnemy);
		}

		if (a == 'o') //If o appears in the file create the boss enemy
		{
			pBossEnemy = new BossEnemy();
			Vector2D vel(300, 0);
			pBossEnemy->Initialise(Vector2D(x, y), vel, &theObjectManager, this);
			theObjectManager.AddObject(pBossEnemy);
		}

		if (a == 'd') //If d appears in the file create the boss enemy
		{
			Door* pDoor = new Door();
			pDoor->Initialise(Vector2D(x, y), &theObjectManager, this);
			theObjectManager.AddObject(pDoor);
		}

		if (a == 'p') //If p appears in the file create a player
		{
			pPlayerChar = new PlayerChar(); //Create new Player character
			pPlayerChar->Initialise(Vector2D(x, y), &theObjectManager, this); //Initilise the starting position
			theObjectManager.AddObject(pPlayerChar); //Add to object manager
		}

		if (a == 's') //If s appears in the file create a spike
		{
			Spikes* pSpikes = new Spikes();
			pSpikes->Initialise(Vector2D(x, y), 1.0f, &theObjectManager, this);
			theObjectManager.AddObject(pSpikes);
		}

		if (a == 'k') //If k appears in file create a key
		{
			Key* pKey = new Key();
			pKey->Initialise(Vector2D(x, y), &theObjectManager, this);
			theObjectManager.AddObject(pKey);
		}
	}
	//Close file
	levelName.close();
}

void GameManager::Render()
{
	//----------------------------------------------------------------------------------------//
	//------------------------------------Debug Code------------------------------------------//
	//----------------------------------------------------------------------------------------//

#if _DEBUG
		MyDrawEngine::GetInstance()->WriteText(1700, 250, L"Key Collected?", MyDrawEngine::GREEN);
		if (keyCollected == true)
			MyDrawEngine::GetInstance()->WriteText(1700, 280, L"true", MyDrawEngine::GREEN);
		if (keyCollected == false)
			MyDrawEngine::GetInstance()->WriteText(1700, 280, L"false", MyDrawEngine::GREEN);
#endif

	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//

	if (playerLives > 0 && levelState != LevelState::SUCCESS)
	{
		MyDrawEngine::GetInstance()->WriteText(50, 450, L"Player Lives:", MyDrawEngine::CYAN, 2);
		MyDrawEngine::GetInstance()->WriteInt(50, 480, playerLives, MyDrawEngine::CYAN, 2);

		if (levelNum > 0 && levelNum != 4 && playerLives > 0)
		{
			MyDrawEngine::GetInstance()->WriteText(50, 250, L"Game Time:", MyDrawEngine::CYAN, 2);
			MyDrawEngine::GetInstance()->WriteInt(50, 280, endLevelTimer, MyDrawEngine::CYAN, 2);

			if (levelNum == 1)
			{
				MyDrawEngine::GetInstance()->WriteText(50, 350, L"No. of Enemies:", MyDrawEngine::CYAN, 2);
				MyDrawEngine::GetInstance()->WriteInt(50, 380, numEnemies, MyDrawEngine::CYAN, 2);
			}
		}
	}

	if(playerLives > 0 && levelState == LevelState::FAILURE)
		MyDrawEngine::GetInstance()->WriteText(560, 100, L"Player died, restarting level...", MyDrawEngine::CYAN, 3);
	
	if (startLevelTimer < 0)
	{
		MyDrawEngine::GetInstance()->WriteText(885, 350, L"Level number", MyDrawEngine::CYAN, 2);
		MyDrawEngine::GetInstance()->WriteInt(950, 380, levelNum, MyDrawEngine::CYAN, 2);
	}

	if (levelState == LevelState::CURRENT)
	{
		//Level 1 task
		if (levelNum == 1)
			MyDrawEngine::GetInstance()->WriteText(140, 100, L" Defeat all enemies, find the key, and reach the door before the \n                         timer runs out", MyDrawEngine::CYAN, 3);

		//Level 2 & 3 task
		if (levelNum == 2 || levelNum == 3)
			MyDrawEngine::GetInstance()->WriteText(230, 100, L"Find the key and reach the door before the timer runs out", MyDrawEngine::CYAN, 3);

		//Level 4 task
		if (levelNum == 4)
		{
			MyDrawEngine::GetInstance()->WriteText(500, 100, L"OVERLORD INCOMMING, FIGHT TO SURVIVE", MyDrawEngine::CYAN, 3);
			MyDrawEngine::GetInstance()->WriteText(50, 350, L"Boss Health", MyDrawEngine::CYAN, 2);
			MyDrawEngine::GetInstance()->WriteInt(50, 380, pBossEnemy->GetHealth(), MyDrawEngine::CYAN, 2);
		}
	}
}

void GameManager::Update(float frameTime)
{
	startLevelTimer += frameTime;
	deathTimer -= frameTime;

	if (!pPlayerChar->IsReady() && startLevelTimer > 0)
	{
		pPlayerChar->StartPlay();
	}
	
	if(levelState != LevelState::SUCCESS && startLevelTimer >= 0)
		endLevelTimer = endLevelTimer - frameTime;

	//If levelState is == SUCCESS (AKA True) player has completed level
	//If levelState is == FAILURE (AKA False) player has not completed level
	//When level is started levelState is set to CURRENT to avoid level recursion
	if (levelState == LevelState::SUCCESS)
	{
		successTimer -= frameTime;
		if (levelNum == 4)
		{
			MyDrawEngine::GetInstance()->WriteText(50, 600, L"You defeated the overlord! you are a true hero, returining to main menu", MyDrawEngine::CYAN, 3);
			if (successTimer <= 0)
			{
				Game::instance.EndTheGame();
			}
		}
		else 
		{
			MyDrawEngine::GetInstance()->WriteText(100, 600, L"Congratulations, completed the level, starting next level, buckle up!", MyDrawEngine::CYAN, 3);
			if (successTimer <= 0)
			{
				StartLevel(levelNum + 1);
				if (levelNum == 2)
					playerLives = 3;

				if (levelNum == 3 || levelNum == 4)
					playerLives = 5;
			}
		}
	}
	else if (levelState == LevelState::FAILURE && playerLives > 0 && deathTimer < 0.0f || endLevelTimer < 0.0f && levelNum != 4)
		StartLevel(levelNum);

	//If player dies
	if (playerLives < 1)
	{
		theObjectManager.DeleteAllObjects();
		levelState = LevelState::FAILURE;
		successTimer = successTimer - frameTime;
		MyDrawEngine::GetInstance()->WriteText(250, 600, L"Player ran out of lives, Game Over, returning to main menu", MyDrawEngine::CYAN, 3);
		if (successTimer <= 0)
		{
			Game::instance.EndTheGame();
		}
	}
}

bool GameManager::CollidesGround(Vector2D pos)
{
	for (Terrain* pNext : pTerrainList)
	{
		if (pNext->GetShape().Intersects(Point2D(pos)))
		{
			return true;
		}
	}
	return false;
}

//Decrease enemy lives when defeated
void GameManager::EnemyDead()
{
	numEnemies--;
}

//Decrease player lives when defeated
void GameManager::PlayerDead()
{
	playerLives--;
}

//Sets key collected to true to allow the game to know if door should spawn
void GameManager::KeyIsCollected()
{
	keyCollected = true;
}

bool GameManager::GetKeyCollected()
{
	return keyCollected;
}

//Sets proceed level to SUCCESS to allow the level number to increase if criteria is met
void GameManager::ProceedLevel()
{
	if (levelNum == 1 && numEnemies > 0)
	{
		levelState = LevelState::CURRENT;
	}
	else if (levelState != LevelState::SUCCESS)
	{
		levelState = LevelState::SUCCESS;
		successTimer = 5.0f;
	}
}

//Sets proceed level to FAILURE to stay at the same level
void GameManager::StayAtLevel()
{
	deathTimer = 3.0f;
	levelState = LevelState::FAILURE;
}

LevelState GameManager::GetLevelState()
{
	return levelState;
}

void GameManager::ClearTerrainList()
{
	pTerrainList.clear();
}

void GameManager::RemoveTerrain(Terrain* pT)
{
	pTerrainList.remove(pT);
}

void GameManager::SetPlayerLives()
{
	if(levelNum == 1 || levelNum == 2)
		playerLives = 3;
	if (levelNum == 3 || levelNum == 4)
		playerLives = 5;
}

