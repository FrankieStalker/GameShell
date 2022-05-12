//Created by w18010435
//All function definitions for Enemy class
//Basic enemy type in the game that player will encounter

#include "Enemy.h"
#include "bullet.h"

#include "GameManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialise(Vector2D pos, Vector2D vel, float newSize, ObjectManager* pOM, GameManager* pGM)
{
	position = pos;
	velocity = vel;
	size = newSize;

	pObjectManager = pOM;
	pGameManager = pGM;

	active = true;

	loadImage(L"EnemyIcon.png");
}

void Enemy::Update(float frameTime)
{
#if _DEBUG
	//MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
#endif

	Vector2D beneathMe;
	if (direction == true)
		beneathMe = position - Vector2D(-10, 75);
	else
		beneathMe = position - Vector2D(10, 75);

	MyDrawEngine::GetInstance()->DrawLine(position, beneathMe, MyDrawEngine::RED);
	if (!pGameManager->CollidesGround(beneathMe))
	{
		velocity = -velocity;
	}

	collisionShape.PlaceAt(position.YValue + 64 / 2, position.XValue - 64 / 2, position.YValue - 64 / 2, position.XValue + 64 / 2);
	position = position + velocity * frameTime;
}

IShape2D& Enemy::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Enemy::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Bullet))
	{
		loadSound(L"Retro-8-bit-damage-571.wav");
		Deactivate();
		pGameManager->EnemyDead();
	}
}
