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