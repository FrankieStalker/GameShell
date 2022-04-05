#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Terrain : public GameObject
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager;

public:
	Terrain();
	~Terrain();

	void Initialise(Vector2D pos, float size, ObjectManager* pOM);
	void Update(float frameTime) override;

	static const int WIDTH = 500;
	static const int HEIGHT = 116;

	int GetEdge(Vector2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};