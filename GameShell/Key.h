#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Key : public GameObject
{
private:
	Circle2D collisionShape;

	ObjectManager* pObjectManager;

	GameManager* pGameManager;

public:
	Key();
	~Key();
	//void Initialise(ObjectManager* pOM);
	void Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

