//Created by w18010435
//All function decleartions for Key class

#pragma once
#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Key : public GameObject
{
private:
	Circle2D collisionShape;

	ObjectManager* pObjectManager = nullptr;

	GameManager* pGameManager = nullptr;

public:
	Key();
	~Key();
	//void Initialise(ObjectManager* pOM);
	void Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

