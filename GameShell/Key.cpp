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

	collisionShape.PlaceAt(position, 24);
	active = true;

	loadImage(L"KeyIcon.png");
}

void Key::Update(float frameTime)
{
#if _DEBUG
	MyDrawEngine::GetInstance()->FillCircle(collisionShape.GetCentre(), collisionShape.GetRadius(), MyDrawEngine::LIGHTBLUE);
#endif
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
		loadSound(L"Game-coin-collect-620.wav");
		Deactivate();
		pGameManager->KeyIsCollected();
	}
}
