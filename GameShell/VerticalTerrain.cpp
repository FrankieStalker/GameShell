#include "VerticalTerrain.h"
#include "BossEnemey.h"

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
	if (typeid(gameObject) == typeid(BossEnemy))
	{
		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to GameObject pointer, call get edge function taking the position of the object as a parameter

		if (edge == 1 || edge == 2 || edge == 3 || edge == 4)
			Deactivate();
	}
}
