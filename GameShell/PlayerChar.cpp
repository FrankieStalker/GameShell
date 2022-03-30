#include "PlayerChar.h"
#include "myinputs.h"
#include "Platform.h"
#include "objectmanager.h"


PlayerChar::PlayerChar()
{
	Deactivate();
}

PlayerChar::~PlayerChar()
{
}

bool PlayerChar::IsOnGround() const
{
	return false;
}

void PlayerChar::Initialise(Vector2D initPos, ObjectManager* pOM)
{
	position = initPos;
	pObjectManager = pOM;
	angle = 0.0f;
	active = true;
	loadImage(L"puff1.bmp");
}

void PlayerChar::Update(float frameTime)
{
	GameObject::Update(frameTime);
	//Pointer for inputs
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_D))			//Key press W -> go forwards
	{
		acceleration = Vector2D(100, 0);
		//acceleration.setBearing(angle, -accPower);
		velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->KeyPressed(DIK_A))			//Key press S -> go backwards
	{
		acceleration = Vector2D(-100, 0);
		//acceleration.setBearing(angle, -accPower);
		velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->NewKeyPressed(DIK_SPACE))
	{
		velocity.YValue = jumpForce;
	}

	////Setting friction, velocity and position
	acceleration = acceleration + gravity;
	friction = frictionPower * velocity * frameTime;
	velocity = velocity + acceleration * frameTime;
	//velocity = velocity - velocity + friction * frameTime; //Cannot multiply by friction???
	position = position + velocity * frameTime;
}

IShape2D& PlayerChar::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void PlayerChar::ProcessCollision(GameObject& gameObejct)
{
	if (typeid(gameObejct) == typeid(Platform))
	{
		isOnGround = true;
	}
}
