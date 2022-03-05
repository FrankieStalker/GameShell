#include "spaceship.h"
#include "mydrawengine.h"
#include "myinputs.h"

Spaceship::Spaceship()
{
	active = false;
}

Spaceship::~Spaceship()
{

}

void Spaceship::Initialise(Vector2D initPos)
{
	position = initPos;
	angle = 1.0f;
	active = true;
	loadImage(L"ship.bmp");
}

void Spaceship::Update()
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
}