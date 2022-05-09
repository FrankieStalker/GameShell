#include "BossEnemey.h"
#include "bullet.h"

#include "GameManager.h"

BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Initialise(Vector2D pos, Vector2D vel, ObjectManager* pOM, GameManager* pGM)
{
	position = pos;
	velocity = vel;

	pObjectManager = pOM;
	pGameManager = pGM;
	active = true;
	health = 75;

	loadImage(L"BossEnemyIcon.png");
}

void BossEnemy::Update(float frameTime)
{
#if _DEBUG
	MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
#endif
	collisionShape.PlaceAt(position.YValue + BOSSSIZE / 2, position.XValue - BOSSSIZE / 2, position.YValue - BOSSSIZE / 2, position.XValue + BOSSSIZE / 2);
	position = position + velocity * frameTime;
}

int BossEnemy::GetHealth()
{
	return health;
}

IShape2D& BossEnemy::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void BossEnemy::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Bullet))
	{
		loadSound(L"Retro-8-bit-damage-571.wav");
		health = health - 1;
		if (health <= 0)
		{
			Deactivate();
			pGameManager->ProceedLevel();
		}
	}
}
