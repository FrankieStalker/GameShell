//Created by w18010435
//Contains all the definitions for bullet class fucntions
//The projectile thet the player shoots to kill/damage enemies

#include "bullet.h"
#include "Enemy.h"
#include "FlyingEnemy.h"
#include "BossEnemey.h"

Bullet::Bullet()
{
	Bullet::Deactivate();
}

Bullet::~Bullet()
{

}

void Bullet::Initialise(Vector2D bulletPos, Vector2D bulletVel)
{
	position = bulletPos;
	velocity = bulletVel;
	active = true;
	loadImage(L"BulletPic.png");
}

void Bullet::Update(float frameTime)
{
#if _DEBUG
	//MyDrawEngine::GetInstance()->FillCircle(collisionShape.GetCentre(), collisionShape.GetRadius(), MyDrawEngine::LIGHTBLUE);
#endif

	collisionShape.PlaceAt(position, 12);
	position = position + velocity * frameTime;

	timeDelay = timeDelay - 1 * frameTime;

	if (timeDelay < 0)
	{
		Deactivate();
	}
}

void Bullet::Shoot()
{
	loadSound(L"shoot.wav");
}

IShape2D& Bullet::GetShape()
{
	return collisionShape;
}

void Bullet::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Enemy) || typeid(gameObject) == typeid(FlyingEnemy) || typeid(gameObject) == typeid(BossEnemy))
	{
		Deactivate();
	}
}