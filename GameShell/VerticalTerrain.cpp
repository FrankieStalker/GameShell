#include "VerticalTerrain.h"

VerticalTerrain::VerticalTerrain()
{
}

VerticalTerrain::~VerticalTerrain()
{
}

void VerticalTerrain::Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM)
{
	position = pos;
	size = platSize;
	pObjectManager = pOM;
	pGameManager = pGM;
	active = true;
	collisionShape.PlaceAt(pos.YValue + VERTHEIGHT / 2, pos.XValue - VERTWIDTH / 2, pos.YValue - VERTHEIGHT / 2, pos.XValue + VERTWIDTH / 2);

	loadImage(L"VertPlatform.png");
}

void VerticalTerrain::Update(float frameTime)
{
	//MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
}

Vector2D VerticalTerrain::GetCollsionNormal(Circle2D other)
{
	return collisionShape.CollisionNormal(other);
}

IShape2D& VerticalTerrain::GetShape()
{
    // TODO: insert return statement here
	return collisionShape;
}

void VerticalTerrain::ProcessCollision(GameObject& gameObject)
{
}
