#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Rock : public GameObject
{
private:
	Rectangle2D collisionShape;

	int number = rand() % 4;
	const wchar_t imgArray[4][25] = { L"rock1.bmp", L"rock2.bmp", L"rock3.bmp", L"rock4.bmp" };

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

public:
	Rock();
	~Rock();
	//void Initialise(ObjectManager* pOM);
	void Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	void Render();

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};