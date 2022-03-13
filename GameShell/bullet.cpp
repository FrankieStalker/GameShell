#include "bullet.h"

Bullet::Bullet()
{
	active = false;
}

Bullet::~Bullet()
{

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
		active = false;
	}
}

void Bullet::Shoot()
{
	loadSound(L"shoot.wav");
}