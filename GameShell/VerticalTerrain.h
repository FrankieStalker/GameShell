#pragma once
#include "Terrain.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class VerticalTerrain : public Terrain
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;
public:
	VerticalTerrain();
	~VerticalTerrain();

	void Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);

	static const int VERTWIDTH = 125;
	static const int VERTHEIGHT = 510;
};

