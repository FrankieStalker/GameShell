#include <fstream>

#include "gamecode.h"
#include "GameManager.h"
#include "Terrain.h"
#include "VerticalTerrain.h"
#include "Enemy.h"
#include "FlyingEnemy.h"
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
	startLevelTimer = -5.0f;
	
    if(levelNum == 1) //Run level 1 code
	{
		//Delete all objects at the start of the level
		//Clear all objects of previous level
		theObjectManager.DeleteAllObjects();
		ClearTerrainList();

		keyCollected = false;
		levelProceed = 3;
		endLevelTimer = 101.0f;

		std::ifstream level1;
		level1.open("level1.txt");
		
		while (level1)
		{
			char a;
			level1 >> a; //Takes type of object
			float x; 
			level1 >> x; //Takes x cord
			float y; 
			level1 >> y; //Takes y cord

			if (a == 't') //If t appears in the file create a platform
			{
				Terrain* t = new Terrain();
				t->Initialise(Vector2D(x, y), 1.0f, &theObjectManager, this);
				theObjectManager.AddObject(t);
				pTerrainList.push_back(t);
			}

			//if (a == 'b') //If b appears in the file create a collision box
			//{
			//	Rock* pRock = new Rock();
			//	pRock->Initialise(Vector2D(x, y), &theObjectManager, this);
			//	theObjectManager.AddObject(pRock);
			//}

			if (a == 'e') //If e appears in the file create an enemy
			{
				Enemy* pEnemy = new Enemy();
				Vector2D vel(200, 0);
				pEnemy->Initialise(Vector2D(x, y), vel, 0.5f, &theObjectManager, this);
				theObjectManager.AddObject(pEnemy);
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
			number = rand() % 4; //Random number for key location
			numEnemies = 10; //Number of enemies in the level
		}

		level1.close();

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
		levelProceed = 3;
		keyCollected = false;
		endLevelTimer = 26.0f;

		std::ifstream level2;
		level2.open("level2.txt");

		while (level2)
		{
			char a;
			level2 >> a;
			float x;
			level2 >> x;
			float y;
			level2 >> y;

			if (a == 't') //If t appears in the file create a platform
			{
				Terrain* t = new Terrain();
				t->Initialise(Vector2D(x, y), 1.0f, &theObjectManager, this);
				theObjectManager.AddObject(t);
				pTerrainList.push_back(t);
			}

			//if (a == 'b') //If b appears in the file create a collision box
			//{
			//	Rock* pRock = new Rock();
			//	pRock->Initialise(Vector2D(x, y), &theObjectManager, this);
			//	theObjectManager.AddObject(pRock);
			//}

			//if (a == 'e') //If e appears in the file create an enemy
			//{
			//	Enemy* pEnemy = new Enemy();
			//	Vector2D vel(100, 0);
			//	pEnemy->Initialise(Vector2D(x, y), vel, 0.5f, &theObjectManager, this);
			//	theObjectManager.AddObject(pEnemy);
			//}

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

			number = rand() % 4; //Random number for key location
		}

		level2.close();

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
		levelProceed = 3;
		keyCollected = false;
		endLevelTimer = 26.0f;

		std::ifstream level3;
		level3.open("level3.txt");

		while (level3)
		{
			char a;
			level3 >> a;
			float x;
			level3 >> x;
			float y;
			level3 >> y;

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
				pTerrainList.push_back(vt);
			}

			if (a == 'b') //If b appears in the file create a collision box
			{
				Rock* pRock = new Rock();
				pRock->Initialise(Vector2D(x, y), &theObjectManager, this);
				theObjectManager.AddObject(pRock);
			}

			if (a == 'f')
			{
				FlyingEnemy* pFlyingEnemy = new FlyingEnemy();
				Vector2D vel(rand() % -500 + 500, 0);
				pFlyingEnemy->Initialise(Vector2D(x, y), vel, 0.5f, &theObjectManager, this);
				theObjectManager.AddObject(pFlyingEnemy);
			}

			//if (a == 'e') //If e appears in the file create an enemy
			//{
			//	Enemy* pEnemy = new Enemy();
			//	Vector2D vel(100, 0);
			//	pEnemy->Initialise(Vector2D(x, y), vel, 0.5f, &theObjectManager, this);
			//	theObjectManager.AddObject(pEnemy);
			//}

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

			if (a == 'k')
			{
				Key* pKey = new Key();
				pKey->Initialise(Vector2D(x, y), &theObjectManager, this);
				theObjectManager.AddObject(pKey);
			}
		}

		level3.close();
	}
}

void GameManager::Render()
{
	//----------------------------------------------------------------------------------------//
	//------------------------------------Debug Code------------------------------------------//
	//----------------------------------------------------------------------------------------//

	MyDrawEngine::GetInstance()->WriteText(1765, 50, L"Game Time", MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteInt(1805, 80, endLevelTimer, MyDrawEngine::GREEN);

	MyDrawEngine::GetInstance()->WriteText(1765, 150, L"Player Lives", MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteInt(1805, 180, playerLives, MyDrawEngine::GREEN);

	MyDrawEngine::GetInstance()->WriteText(1765, 250, L"No. of Enemies", MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteInt(1805, 280, numEnemies, MyDrawEngine::GREEN);

	if (keyCollected == true)
		MyDrawEngine::GetInstance()->WriteText(800, 800, L"true", MyDrawEngine::GREEN);
	if (keyCollected == false)
		MyDrawEngine::GetInstance()->WriteText(800, 800, L"false", MyDrawEngine::GREEN);

	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//

	if (startLevelTimer < 0)
	{
		MyDrawEngine::GetInstance()->WriteText(1765, 350, L"Level number", MyDrawEngine::GREEN);
		MyDrawEngine::GetInstance()->WriteInt(1805, 380, levelNum, MyDrawEngine::GREEN);
	}
		

	//Level 1 task
	if (levelNum == 1)
		MyDrawEngine::GetInstance()->WriteText(690, 100, L"Defeate all enemies, find the key, and reach the door before the timer runs out", MyDrawEngine::GREEN);
	//Level 2 & 3 task
	if (levelNum == 2 || levelNum == 3)
		MyDrawEngine::GetInstance()->WriteText(690, 100, L"Find the key and reach the door before the timer runs out", MyDrawEngine::GREEN);
}

void GameManager::Update(float frameTime)
{
	startLevelTimer += frameTime;

	/*if (!pPlayerChar->IsReady() && startLevelTimer > 0)
		pPlayerChar->StartPlay();*/

	endLevelTimer = endLevelTimer - frameTime;

	if (endLevelTimer < 0.0f)
	{
		StartLevel(levelNum);
		PlayerDead();
	}

	//If level proceed is == 1 (AKA True) player has completed level
	//If level proceed is == 2 (AKA False) player has not completed level
	//When level is started level proceed is set to 3 to avoid level recursion
	if (levelProceed == 1) 
	{
		StartLevel(levelNum + 1);
		if(levelNum == 2)
			playerLives = 3;
		if (levelNum == 3)
			playerLives = 5;
	}
	else if (levelProceed == 2)
		StartLevel(levelNum);

	//Run this code when level 1
	if (levelNum == 1)
	{
		//Create door if key collected and enemies killed
		if (numEnemies < 1 && keyCollected == true)
		{
			Door* pDoor = new Door();
			pDoor->Initialise(Vector2D(0, -5900), &theObjectManager, this);
			theObjectManager.AddObject(pDoor);
			keyCollected = false;
		}
	}

	//Run this code when level 2
	if (levelNum == 2)
	{
		//Create door if key collected
		if (keyCollected == true)
		{
			Door* pDoor = new Door();
			pDoor->Initialise(Vector2D(-500, -5200), &theObjectManager, this);
			theObjectManager.AddObject(pDoor);
			keyCollected = false;
		}
	}

	//Run this code when level 3
	if (levelNum == 3)
	{
		//Create door if key collected
		if (keyCollected == true)
		{
			Door* pDoor = new Door();
			pDoor->Initialise(Vector2D(0, -6100), &theObjectManager, this);
			theObjectManager.AddObject(pDoor);
			keyCollected = false;
		}
	}

	if (playerLives < 1)
	{

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

//Sets proceed level to 1 to allow the level number to increase
void GameManager::ProceedLevel()
{
	levelProceed = 1;
}

//Sets proceed level to 2 to stay at the same level
void GameManager::StayAtLevel()
{
	levelProceed = 2;
}

void GameManager::ClearTerrainList()
{
	pTerrainList.clear();
}

D3DCOLOR GameManager::BackgroundColour(D3DCOLOR colour)
{
	return colour;
}