#include "PlayerChar.h"
#include "myinputs.h"
#include "objectmanager.h"


PlayerChar::PlayerChar()
{
	Deactivate();
}

PlayerChar::~PlayerChar()
{
}

void PlayerChar::Initialise(Vector2D initPos, ObjectManager* pOM)
{
	position = initPos;
	pObjectManager = pOM;
	angle = 0.0f;
	active = true;
	jumping = false;
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
		acceleration = Vector2D(500, 0);
		velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->KeyPressed(DIK_A))			//Key press S -> go backwards
	{
		acceleration = Vector2D(-500, 0);
		velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->NewKeyPressed(DIK_SPACE))
	{
		acceleration = Vector2D(0.0f, 100.0f);
		velocity = velocity + acceleration + gravity * frameTime;
	}

	//Setting friction, velocity and position
	friction = frictionPower * velocity * frameTime;
	velocity = velocity + friction;
	position = position + velocity * frameTime;
}

IShape2D& PlayerChar::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void PlayerChar::ProcessCollision(GameObject& gameObejct)
{
}
