
#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Rock : public GameObject
{
private:
	Vector2D velocity;
	Vector2D friction;
	Vector2D acceleration;

	Circle2D collisionShape;

	int number = rand() % 4;
	const wchar_t imgArray[4][25] = { L"rock1.bmp", L"rock2.bmp", L"rock3.bmp", L"rock4.bmp" };

	ObjectManager* pObjectManager;

public:
	Rock();
	~Rock();
	void Initialise(ObjectManager* pOM);
	void Initialise(Vector2D pos, Vector2D angle, float size, ObjectManager* pOM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};
