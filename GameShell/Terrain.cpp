#include "Terrain.h"
#include "BossEnemey.h"

#include "objectmanager.h"
#include "GameManager.h"

Terrain::Terrain()
{

}

Terrain::~Terrain()
{

}

void Terrain::Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM)
{
	position = pos;
	size = platSize;
	pObjectManager = pOM;
	pGameManager = pGM;
	active = true;
	collisionShape.PlaceAt(pos.YValue + HEIGHT / 2, pos.XValue - WIDTH / 2, pos.YValue - HEIGHT / 2, pos.XValue + WIDTH / 2);

	loadImage(L"Terrain.png");
}

void Terrain::Update(float frameTime)
{
	MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
}

Vector2D Terrain::GetCollsionNormal(Circle2D other)
{
	return collisionShape.CollisionNormal(other);
}

IShape2D& Terrain::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Terrain::ProcessCollision(GameObject& gameObject)
{
	if (typeid(gameObject) == typeid(BossEnemy))
	{
		int edge = dynamic_cast <GameObject*>(&gameObject)->GetEdge(position); //Worked out address of game object and cast that to GameObject pointer, call get edge function taking the position of the object as a parameter

		if (edge == 1 || edge == 2 || edge == 3 || edge == 4)
		{
			Deactivate();
			pGameManager->RemoveTerrain(this);
		}
			
	}

}