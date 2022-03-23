#include "Explosion.h"
#include "objectmanager.h"

Explosion::Explosion()
{
	active = false;
}

Explosion::~Explosion()
{

}

void Explosion::Initialise(Vector2D pos)
{
	position = pos;
	active = true;

	/*for (int i = 0; i < 8; i++)
	{
		loadImage(imgArray[0]);
	}*/
}

void Explosion::Update(float frameTime)
{
	position = position * frameTime;

	for (int i = 0; i < 8; i++)
	{
		loadImage(imgArray[i]);
	}
}

IShape2D& Explosion::GetShape()
{
	return collisionShape;
}

void Explosion::ProcessCollision(GameObject& gameObejct)
{

}
