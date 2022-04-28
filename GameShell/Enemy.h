#pragma once
#include "GameObject.h"
#include "Terrain.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Enemy : public GameObject
{
private:
	Terrain* pTerrain;
protected:
	Vector2D velocity;
	Vector2D acceleration;

	Rectangle2D collisionShape;

	bool direction;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

public:
	Enemy();
	~Enemy();

	void Initialise(Vector2D pos, Vector2D vel, float newSize, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

