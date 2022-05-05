#include "Enemy.h"
#include "rock.h"
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

	//MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
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
	if (typeid(gameObject) == typeid(Rock))
	{
		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to Terrain pointer, call get edge function taking the position of the player as a parameter

		if (edge == 3) //Left
		{
			position.XValue = gameObject.getPos().XValue - (64 + Terrain::WIDTH) / 2;
			velocity.XValue = -velocity.XValue;
		}
		if (edge == 4) //Right
		{
			position.XValue = gameObject.getPos().XValue + (64 + Terrain::WIDTH) / 2;
			velocity.XValue = -velocity.XValue;
		}
	}
	if (typeid(gameObject) == typeid(Bullet))
	{
		Deactivate();
		pGameManager->EnemyDead();
	}
}
