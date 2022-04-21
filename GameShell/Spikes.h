#pragma once
#include "GameObject.h"

//Promise this class
class ObjectManager;
class GameManager;

class Spikes : public GameObject
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

	static const int SPIKESIZE = 510;

public:
	Spikes();
	~Spikes();

	void Initialise(Vector2D pos, float size, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	int GetEdge(Vector2D other);

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

