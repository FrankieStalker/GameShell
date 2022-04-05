#include "PlayerChar.h"
#include "myinputs.h"
#include "Terrain.h"
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

	//currentImg = 0.0;

	loadImage(L"puff1.bmp");
	//expImg[0] = loadImage(L"puff1.bmp");
	//expImg[1] = loadImage(L"puff2.bmp");

}

//void PlayerChar::Render()
//{
//	for (int i = (int)currentImg; i < 1; i++)
//	{
//		if (active)
//		{
//			MyDrawEngine::GetInstance()->DrawAt(position, expImg[i], size, angle);
//		}
//	}
//}

void PlayerChar::Update(float frameTime)
{
	/*currentImg = currentImg + 0.01f;
	if (currentImg >= 1)
	{
		currentImg = 0.0f;
	}*/

	acceleration.set(0, 0);
	GameObject::Update(frameTime);
	//Pointer for inputs
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_D))			//Key press W -> go forwards
	{
		acceleration += Vector2D(2000, 0); //Acceleration of player charater increase to the right
		if (pInputs->KeyPressed(DIK_LSHIFT))
		{
			acceleration += Vector2D(5000, 0);
		}
		//acceleration.setBearing(angle, -accPower);
		//velocity = velocity + acceleration * frameTime;
	}
	if (pInputs->KeyPressed(DIK_A))			//Key press S -> go backwards
	{
		acceleration += Vector2D(-2000, 0); //Acceleration of player charater increase to the left
		if (pInputs->KeyPressed(DIK_LSHIFT))
		{
			acceleration += Vector2D(-5000, 0);
		}
		//acceleration.setBearing(angle, -accPower);
		//velocity = velocity + acceleration * frameTime;
	}
  	if (pInputs->KeyPressed(DIK_SPACE) && isOnGround)
	{
		velocity.YValue = JUMP_FORCE;
		isOnGround = false;
	}

	////Setting friction, velocity and position
	acceleration += GRAVITY;
	//friction = frictionPower * velocity * frameTime;
	velocity = velocity + acceleration * frameTime;
	velocity = velocity - velocity * FRICTION * frameTime; //Cannot multiply by friction???
	position = position + velocity * frameTime;

	MyDrawEngine::GetInstance()->WriteInt(500, 500, position.XValue, MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteInt(500, 600, position.YValue, MyDrawEngine::GREEN);

	if (isOnGround == true)
		MyDrawEngine::GetInstance()->WriteText(Vector2D(400, 400), L"true", MyDrawEngine::GREEN);
	if(isOnGround == false)
		MyDrawEngine::GetInstance()->WriteText(Vector2D(400, 400), L"false", MyDrawEngine::GREEN);

	collisionShape.PlaceAt(position, 32);
}

IShape2D& PlayerChar::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void PlayerChar::ProcessCollision(GameObject& gameObejct)
{
	if (typeid(gameObejct) == typeid(Terrain))
	{
		if (gameObejct.getPos().YValue < position.YValue
			&& position.XValue > gameObejct.getPos().XValue - Terrain::WIDTH/2
			&& position.XValue < gameObejct.getPos().XValue + Terrain::WIDTH/2)
		{
			isOnGround = true;

			if (velocity.YValue < 0)
			{
				velocity.YValue = 0;
			}
			//velocity.YValue = 0;
			position.YValue = gameObejct.getPos().YValue + (64 + Terrain::HEIGHT) / 2;
		}
	}
}