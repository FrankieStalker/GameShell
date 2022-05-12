//Created by w18010435
//Collision box class for flying birds to collide with
//Helps with their movement

#include "rock.h"
#include "bullet.h"

#include "objectmanager.h"
#include "GameManager.h"

Rock::Rock()
{
}

Rock::~Rock()
{

}

void Rock::Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM)
{
	pObjectManager = pOM;
	pGameManager = pGM;
	position = pos;

	active = true;
}

void Rock::Update(float frameTime)
{
	//MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
	collisionShape.PlaceAt(position.YValue + HEIGHT, position.XValue - WIDTH / 2, position.YValue - HEIGHT, position.XValue + WIDTH / 2);
}

void Rock::Render()
{

}

IShape2D& Rock::GetShape()
{
	return collisionShape;
}

void Rock::ProcessCollision(GameObject& gameObject)
{

}