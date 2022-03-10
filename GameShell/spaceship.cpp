#include "spaceship.h"
#include "mydrawengine.h"
#include "myinputs.h"
#include "bullet.h"
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

void Spaceship::Update(float frameTime)
{
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

	if (pInputs->NewKeyPressed(DIK_SPACE))
	{
		Bullet* pBullet;
		pBullet = new Bullet();
		Vector2D bulletVel;
		bulletVel.setBearing(angle, 200.0f);
		pBullet->Initialise(position, bulletVel);
		if (pObjectManager)
		{
			pObjectManager->AddObject(pBullet);
		}
	}
}