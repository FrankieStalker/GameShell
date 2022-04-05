#include "Terrain.h"
#include "objectmanager.h"
#include "PlayerChar.h"
#include<typeinfo>.

Terrain::Terrain()
{
	Deactivate();
}

Terrain::~Terrain()
{

}

void Terrain::Initialise(Vector2D pos, float platSize, ObjectManager* pOM)
{
	position = pos;
	size = platSize;
	pObjectManager = pOM;
	active = true;
	collisionShape.PlaceAt(pos.YValue + HEIGHT / 2, pos.XValue - WIDTH/2, pos.YValue - HEIGHT / 2,  pos.XValue + WIDTH/2);

	loadImage(L"platform.png");
}

void Terrain::Update(float frameTime)
{
	//MyDrawEngine::GetInstance()->FillRect(collisionShape, MyDrawEngine::LIGHTBLUE);
}

int Terrain::GetEdge(Vector2D other)
{
	if (other.XValue < position.XValue
		&& other.YValue < position.YValue + HEIGHT / 2
		&& other.YValue > position.YValue - HEIGHT / 2)
	return 1;
	/*else if (other.XValue < position.XValue
		&& other.YValue < position.YValue + HEIGHT / 2
		&& other.YValue > position.YValue - HEIGHT / 2)
		return 2;*/
}

IShape2D& Terrain::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Terrain::ProcessCollision(GameObject& gameObject)
{
	
}
