#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Terrain : public GameObject
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

public:
	Terrain();
	~Terrain();

	void Initialise(Vector2D pos, float size, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	int GetEdge(Vector2D other);

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};