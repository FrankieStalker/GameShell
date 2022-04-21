#include "bullet.h"
#include "Enemy.h"

Bullet::Bullet()
{
	Bullet::Deactivate();
}

Bullet::~Bullet()
{

}

IShape2D& Bullet::GetShape()
{
	return collisionShape;
}

void Bullet::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Enemy))
	{
		active = false;
		Deactivate();
	}
}

void Bullet::Initialise(Vector2D bulletPos, Vector2D bulletVel)
{
	position = bulletPos;
	velocity = bulletVel;
	active = true;
	loadImage(L"bullet.bmp");
}

void Bullet::Update(float frameTime)
{
	position = position + velocity * frameTime;

	timeDelay = timeDelay - 1 * frameTime;

	if (timeDelay < 0)
	{
		Deactivate();
	}

	collisionShape.PlaceAt(position, 12);
}

void Bullet::Shoot()
{
	loadSound(L"shoot.wav");
}