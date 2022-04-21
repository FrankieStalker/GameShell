#pragma once
#include "GameObject.h"
#include "Terrain.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Enemy : public GameObject
{
private:
	Vector2D velocity;
	Vector2D acceleration;

	Rectangle2D collisionShape;

	bool direction;

	int number = rand() % 4;
	const wchar_t imgArray[4][25] = { L"rock1.bmp", L"rock2.bmp", L"rock3.bmp", L"rock4.bmp" };

	Terrain* pTerrain;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

public:
	Enemy();
	~Enemy();

	void Initialise(Vector2D pos, Vector2D vel, float size, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

