#include "Key.h"
#include "PlayerChar.h"

#include "objectmanager.h"
#include "GameManager.h"

Key::Key()
{
}

Key::~Key()
{
}

void Key::Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM)
{
	pObjectManager = pOM;
	pGameManager = pGM;
	position = pos;

	active = true;

	loadImage(L"KeyIcon.png");
}

void Key::Update(float frameTime)
{
	//MyDrawEngine::GetInstance()->FillCircle(collisionShape.GetCentre(), collisionShape.GetRadius(), MyDrawEngine::LIGHTBLUE);
	collisionShape.PlaceAt(position, 24);
}

IShape2D& Key::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Key::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(PlayerChar))
	{
		Deactivate();
		pGameManager->KeyIsCollected();
	}
}
