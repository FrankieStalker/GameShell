#include "Platform.h"

Platform::Platform()
{
	active = false;
}

Platform::~Platform()
{
}

void Platform::Initialise(Vector2D initPos, ObjectManager* pOM)
{

}

void Platform::Update(float frameTime)
{
	collisionShape.PlaceAt(position, position);
}

IShape2D& Platform::GetShape()
{
	// TODO: insert return statement here
	return collisionShape;
}

void Platform::ProcessCollision(GameObject& gameObejct)
{

}
