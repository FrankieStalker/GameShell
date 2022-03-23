#include "rock.h"
#include "bullet.h"
#include "gamecode.h"
#include "objectmanager.h"
#include<typeinfo>.

Rock::Rock()
{
	active = false;
}

Rock::~Rock()
{

}

void Rock::Initialise(ObjectManager* pOM)
{
	pObjectManager = pOM;
	//velocity = Vector2D(rand() % 10 - 20, rand() % 50 - 100);
	velocity = Vector2D(5, 5);
	velocity.setBearing(rand() % 628 / 100.0f, rand() % 200);

	Vector2D randPos;
	randPos.setBearing(rand() % 628 / 100.0f, rand() % 400 + 600);
	position = randPos;
	active = true;

	loadImage(imgArray[number]);
}

void Rock::Initialise(Vector2D pos, Vector2D angle, float newSize, ObjectManager* pOM)
{
	pObjectManager = pOM;
	position = pos;
	velocity = angle;

	size = newSize;

	active = true;

	loadImage(imgArray[number]);

}

void Rock::Update(float frameTime)
{
	position = position + velocity * frameTime;

	collisionShape.PlaceAt(position, 64*size);
}

IShape2D& Rock::GetShape()
{
	return collisionShape;
}

void Rock::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Bullet))
	{
		active = false;
		Deactivate();

		if (size > 0.3f)
		{
			for (int i = 0; i < 3; i++)
			{
				Rock* pRock = new Rock();
				Vector2D pos = position + Vector2D(rand() % 150 - 75, rand() % 150 - 75);
				Vector2D vel(rand() % 200 - 100, rand() % 200 - 100);
				pRock->Initialise(pos, vel, size / 2, *&pObjectManager);
				if (pObjectManager)
				{
					pObjectManager->AddObject(pRock);
				}
			}
		}
	}
}