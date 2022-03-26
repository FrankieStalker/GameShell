#include "spaceship.h"
//#include "mydrawengine.h"
#include "myinputs.h"
#include "rock.h"
#include "bullet.h"
#include "Explosion.h"
#include "objectmanager.h"


Spaceship::Spaceship()
{
	active = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialise(Vector2D initPos, ObjectManager* pOM)
{
	position = initPos;
	pObjectManager = pOM;
	angle = 1.0f;
	active = true;
	loadImage(L"ship.bmp");
}

IShape2D& Spaceship::GetShape()
{
	return collisionShape;
}

void Spaceship::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(Rock))
	{
		Explosion* pExp;
		pExp = new Explosion();
		pExp->Initialise(position);
		pExp->Explode();
		if (pObjectManager)
		{
			pObjectManager->AddObject(pExp);
		}
		active = false;
		Deactivate();
	}
}
 
void Spaceship::Update(float frameTime)
{
	GameObject::Update(frameTime);
	//Pointer for inputs
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_W))			//Key press W -> go forwards
	{
		acceleration = Vector2D(500, 0);
		acceleration.setBearing(angle, accPower);
		velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->KeyPressed(DIK_S))			//Key press S -> go backwards
	{
		acceleration = Vector2D(-500, 0);
		acceleration.setBearing(angle, -accPower);
		velocity = velocity + acceleration * frameTime;
	}

	//Setting friction, velocity and position
	friction = frictionPower * velocity * frameTime;
	velocity = velocity + friction + gravity;
	position = position + velocity * frameTime;

	//Rotation
	if (pInputs->KeyPressed(DIK_A))
	{
		//Setting the rotation angle
		angle = angle - rotSpeed * frameTime;
	}
	if (pInputs->KeyPressed(DIK_D))
	{
		angle = angle + rotSpeed * frameTime;
	}

	if (pInputs->KeyPressed(DIK_SPACE))
	{
		if (shootDelay <= 0)
		{
			shootDelay = 0.5f;
			Bullet* pBullet;
			pBullet = new Bullet();
			Vector2D bulletVel;
			bulletVel.setBearing(angle, 500.0f);
			Vector2D bulletPosition = position;
			pBullet->Initialise(bulletPosition, bulletVel);
			pBullet->Shoot();
			if (pObjectManager)
			{
				pObjectManager->AddObject(pBullet);
			}
		}
	}

	shootDelay = shootDelay - 0.5f * frameTime;

	collisionShape.PlaceAt(position, 32);
}
