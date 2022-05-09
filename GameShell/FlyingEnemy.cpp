#include "FlyingEnemy.h"
#include "rock.h"
#include "bullet.h"

#include "GameManager.h"

FlyingEnemy::FlyingEnemy()
{
}

FlyingEnemy::~FlyingEnemy()
{
}

void FlyingEnemy::Initialise(Vector2D pos, Vector2D vel, float newSize, float newAngle, ObjectManager* pOM, GameManager* pGM)
{
	position = pos;
	velocity = vel;
	size = newSize;

	angle = newAngle;

	pObjectManager = pOM;
	pGameManager = pGM;

	active = true;

	loadImage(L"FlyingEnemy.png");
}

void FlyingEnemy::Update(float frameTime)
{
	collisionShape.PlaceAt(position.YValue + 64 / 2, position.XValue - 64 / 2, position.YValue - 64 / 2, position.XValue + 64 / 2);
	position = position + velocity * frameTime;
}

IShape2D& FlyingEnemy::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void FlyingEnemy::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Rock))
	{
		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to Terrain pointer, call get edge function taking the position of the player as a parameter

		if (edge == 1) //Top
		{
			position.YValue = gameObject.getPos().YValue + (64 + Terrain::WIDTH) / 2;
			velocity.YValue = -velocity.YValue;
			angle = 0.0f;
		}
		if (edge == 2) //Bottom
		{
			position.YValue = gameObject.getPos().YValue - (64 + Terrain::WIDTH) / 2;
			velocity.YValue = -velocity.YValue;
			angle = 3.14f;
		}

		if (edge == 3) //Left
		{
			position.XValue = gameObject.getPos().XValue - (64 + Terrain::WIDTH) / 2;
			velocity.XValue = -velocity.XValue;
			angle = -angle;
		}
		if (edge == 4) //Right
		{
			position.XValue = gameObject.getPos().XValue + (64 + Terrain::WIDTH) / 2;
			velocity.XValue = -velocity.XValue;
			angle = -angle;
		}
	}
	if (typeid(gameObject) == typeid(Bullet))
	{
		loadSound(L"Retro-8-bit-damage-571.wav");
		Deactivate();
		pGameManager->EnemyDead();
	}
}
