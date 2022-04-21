#include "Door.h"
#include "PlayerChar.h"

#include "objectmanager.h"
#include "GameManager.h"

Door::Door()
{
}

Door::~Door()
{
}

void Door::Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM)
{
	pObjectManager = pOM;
	pGameManager = pGM;
	position = pos;

	active = true;

	loadImage(L"boss1.bmp");
}

void Door::Update(float frameTime)
{
	MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
	collisionShape.PlaceAt(position.YValue + HEIGHT, position.XValue - WIDTH / 2, position.YValue - HEIGHT, position.XValue + WIDTH / 2);
}

IShape2D& Door::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Door::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(PlayerChar))
	{
		pGameManager->KeyIsCollected();
		pGameManager->ProceedLevel();
	}
}
