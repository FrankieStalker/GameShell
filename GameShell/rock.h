//Created by w18010435
//Rock (Flying Enemy bound box) class used to store all the function declarations and variables for Rock class

#pragma once
#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Rock : public GameObject
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager = nullptr;

	GameManager* pGameManager = nullptr;

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