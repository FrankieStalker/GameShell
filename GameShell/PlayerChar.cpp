//Created by w18010435
//Contains all declarations for PlayerChar class
//Has player controllers:
//A = left
//D = right
//Hold SHIFT when moving left or right to go quicker
//E = shoot
//SPACE = jump
//Collision for how player walks on surface of platforms

#include "PlayerChar.h"
#include "myinputs.h"
#include "Terrain.h"
#include "VerticalTerrain.h"
#include "Spikes.h"
#include "Enemy.h"
#include "FlyingEnemy.h"
#include "BossEnemey.h"
#include "bullet.h"

#include "objectmanager.h"
#include "GameManager.h"


PlayerChar::PlayerChar()
{
	
}

PlayerChar::~PlayerChar()
{
}

bool PlayerChar::IsOnGround() const
{
	return false;
}

void PlayerChar::Initialise(Vector2D initPos, ObjectManager* pOM, GameManager* pGM)
{
	position = initPos;
	pObjectManager = pOM;
	pGameManager = pGM;
	angle = 1.55f;
	active = true;
	ready = false;

	//currentImg = 0.0;

	loadImage(L"PlayerIcon.png");
}

void PlayerChar::Update(float frameTime)
{
	//----------------------------------------------------------------------------------------//
	//------------------------------------Debug Code------------------------------------------//
	//----------------------------------------------------------------------------------------//

#if _DEBUG
		MyDrawEngine::GetInstance()->WriteText(1700, 310, L"Player X pos", MyDrawEngine::GREEN);
		MyDrawEngine::GetInstance()->WriteInt(1700, 340, position.XValue, MyDrawEngine::GREEN);
		MyDrawEngine::GetInstance()->WriteText(1700, 370, L"Player Y pos", MyDrawEngine::GREEN);
		MyDrawEngine::GetInstance()->WriteInt(1700, 400, position.YValue, MyDrawEngine::GREEN);

		MyDrawEngine::GetInstance()->WriteText(1700, 430, L"On Ground?", MyDrawEngine::GREEN);
		if (isOnGround == true)
			MyDrawEngine::GetInstance()->WriteText(1700, 460, L"true", MyDrawEngine::GREEN);
		if (isOnGround == false)
			MyDrawEngine::GetInstance()->WriteText(1700, 460, L"false", MyDrawEngine::GREEN);

		MyDrawEngine::GetInstance()->FillCircle(collisionShape.GetCentre(), collisionShape.GetRadius(), MyDrawEngine::LIGHTBLUE);
#endif

	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------------------------//

	//Pointer for inputs
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (position.YValue > cameraHeight + 300.0f)
		cameraHeight = position.YValue - 300.0f;
	if (position.YValue < cameraHeight - 300.0f)
		cameraHeight = position.YValue + 300.0f;

	MyDrawEngine::GetInstance()->theCamera.PlaceAt(Vector2D(position.XValue, -cameraHeight));
	collisionShape.PlaceAt(position, 32);//Initial collision to aid when loading levels

	if (!ready) return;
	if (pGameManager->GetLevelState() == LevelState::SUCCESS)
	{
		levelCompleteJumpTimer -= frameTime;
		if (levelCompleteJumpTimer < 0)
		{
			velocity.YValue = JUMP_FORCE;
			levelCompleteJumpTimer = 1;
		}
	}
	acceleration.set(0, 0);

	if (pInputs->KeyPressed(DIK_D) && pGameManager->GetLevelState() != LevelState::SUCCESS)//Key press D -> go Right
	{
		//Acceleration of player charater increase to the right
		acceleration += Vector2D(2000, 0);
		angle = 1.55;
		if (pInputs->KeyPressed(DIK_LSHIFT) && pGameManager->GetLevelState() != LevelState::SUCCESS)//Hold shift to run quicker
		{
			acceleration = Vector2D(4000, 0);
		}
	}
	if (pInputs->KeyPressed(DIK_A) && pGameManager->GetLevelState() != LevelState::SUCCESS)//Key press A -> go Left
	{
		acceleration += Vector2D(-2000, 0);//Acceleration of player charater increase to the left
		angle = -1.55f;
		if (pInputs->KeyPressed(DIK_LSHIFT))//Hold shift to run quicker
		{
			acceleration = Vector2D(-4000, 0);
		}
	}
	if (pInputs->KeyPressed(DIK_SPACE) && isOnGround && pGameManager->GetLevelState() != LevelState::SUCCESS)//Key press space -> Jump
	{
		velocity.YValue = JUMP_FORCE;
		isOnGround = false;
		loadSound(L"Arcade-8-bit-jump-813.wav");
	}

	if (pInputs->KeyPressed(DIK_E) && pGameManager->GetLevelState() != LevelState::SUCCESS)//Key press E -> shoot
	{
		if (shootDelay <= 0)
		{
			shootDelay = 0.5f;
			Bullet* pBullet;
			pBullet = new Bullet();
			Vector2D bulletVel;
			bulletVel.setBearing(angle, 1000.0f);
			Vector2D bulletPosition = position;
			pBullet->Initialise(bulletPosition, bulletVel);
			pBullet->Shoot();
			if (pObjectManager)
			{
				pObjectManager->AddObject(pBullet);
			}
		}
	}

	shootDelay = shootDelay - 1.0f * frameTime;

	//Setting friction, velocity and position
	acceleration = acceleration + GRAVITY;
	//friction = frictionPower * velocity * frameTime;
	velocity = velocity + acceleration * frameTime;
	velocity = velocity - velocity * FRICTION * frameTime;
	position = position + velocity * frameTime;

	

	isOnGround = false;

	collisionShape.PlaceAt(position, 32);//Collision needed to be delcared again, if not issues with collision occur
}

void PlayerChar::StartPlay()
{
	ready = true;
}

bool PlayerChar::IsReady()
{
	return ready;
}

IShape2D& PlayerChar::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void PlayerChar::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Terrain))
	{
		// ****************************************************************************************
		// Allows player to walk on flat surfaces *************************************************
		// ****************************************************************************************
		Vector2D normal = dynamic_cast <Terrain*>(&gameObject)->GetCollsionNormal(collisionShape); // Gets the vector that points away from the object
		
		if (normal.YValue > 0.8f) //If vector is mostly pointing upwards
		{
			isOnGround = true;
		}
		else {
			isOnGround = false;
		}
		velocity = velocity - 2 * (velocity * normal) * normal * 0.5f; //Move away from object
		position = position + dynamic_cast <Terrain*>(&gameObject)->GetCollsionNormal(collisionShape) * 1; //Move away from object

		// ****************************************************************************************
		// ****************************************************************************************
		// ****************************************************************************************

		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to Terrain pointer, call get edge function taking the position of the player as a parameter

		if (edge == 1) //Top
		{
			isOnGround = true; //Set player to true for touching ground

			velocity.YValue = 0; //Set upward velocity to 0

			position.YValue = gameObject.getPos().YValue + (64 + Terrain::HEIGHT) / 2; //Set player to stay abover the platform and not sink in
		}
		if (edge == 2) //Bottom
		{
			isOnGround = false;
			velocity.YValue = -velocity.YValue; //Set the downward velocity to - the current Y velocity

			position.YValue = gameObject.getPos().YValue - (64 + Terrain::HEIGHT) / 2;
		}
		if (edge == 3 && !isOnGround) //Left
		{
			isOnGround = false;
			if (velocity.XValue > 25.0f)
			{
				position.XValue = gameObject.getPos().XValue - (64 + Terrain::WIDTH) / 2;
			}
			if (velocity.XValue > 0)
			{
				velocity.XValue = -velocity.XValue;
			}
		}
		if (edge == 4 && !isOnGround) //Right
		{
			isOnGround = false;
			if (velocity.XValue < -25.0f)
			{
				position.XValue = gameObject.getPos().XValue + (64 + Terrain::WIDTH) / 2;
			}
			if (velocity.XValue < 0)
			{
				velocity.XValue = -velocity.XValue;
			}
		}
	}

	if (typeid(gameObject) == typeid(VerticalTerrain))
	{
		Vector2D normal = dynamic_cast <VerticalTerrain*>(&gameObject)->GetCollsionNormal(collisionShape); // Gets the vector that points away from the object
		if (normal.XValue < 0.8f) //If vector is mostly pointing sideways
		{
			isOnGround = false;
		}
		else {
			isOnGround = true;
		}
		velocity = velocity - 2 * (velocity * normal) * normal * 0.5f; //Move away from object
		position = position + dynamic_cast <VerticalTerrain*>(&gameObject)->GetCollsionNormal(collisionShape) * 1; //Move away from object

		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to Terrain pointer, call get edge function taking the position of the player as a parameter

		if (edge == 3 && !isOnGround || edge == 3 && isOnGround) //Left
		{
			isOnGround = false;
			if (velocity.XValue > 5.0f)
			{
				position.XValue = gameObject.getPos().XValue - (64 + VerticalTerrain::VERTWIDTH) / 2;
			}
			if (velocity.XValue > 0)
			{
				velocity.XValue = -velocity.XValue;
			}
		}
		if (edge == 4 && !isOnGround || edge == 4 && isOnGround) //Right
		{
			isOnGround = false;
			if (velocity.XValue < -5.0f)
			{
				position.XValue = gameObject.getPos().XValue + (64 + VerticalTerrain::VERTWIDTH) / 2;
			}
			if (velocity.XValue < 0)
			{
				velocity.XValue = -velocity.XValue;
			}
		}
	}

	//If player collides with enemy or spikes player dies
	if (typeid(gameObject) == typeid(Enemy) || typeid(gameObject) == typeid(FlyingEnemy) || typeid(gameObject) == typeid(BossEnemy) || typeid(gameObject) == typeid(Spikes))
	{
		loadSound(L"Arcade-8-bit-death-289.wav");
		Deactivate();
		pGameManager->PlayerDead();
		pGameManager->StayAtLevel();
	}
}
