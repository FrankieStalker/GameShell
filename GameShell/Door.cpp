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
	collisionShape.PlaceAt(position.YValue + DOORHEIGHT / 2, position.XValue - DOORWIDTH / 2, position.YValue - DOORHEIGHT / 2, position.XValue + DOORWIDTH / 2);
	loadImage(L"DoorSprite.png");
}

void Door::Update(float frameTime)
{
#if _DEBUG
	MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
#endif
}

IShape2D& Door::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Door::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(PlayerChar) && pGameManager->GetKeyCollected() == true)
	{
		//pGameManager->KeyIsCollected();
		pGameManager->ProceedLevel();
	}
}
