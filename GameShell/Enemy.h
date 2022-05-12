//Created by w18010435
//Enemy class used to store all the function declarations and variables for Enemy class

#pragma once
#include "GameObject.h"
#include "Terrain.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Enemy : public GameObject
{
private:
	Terrain* pTerrain = nullptr; //Pointer to terrain 
protected:
	Vector2D velocity;
	Vector2D acceleration;

	Rectangle2D collisionShape;

	bool direction;

	ObjectManager* pObjectManager = nullptr;

	GameManager* pGameManager = nullptr;

public:
	Enemy();
	~Enemy();

	void Initialise(Vector2D pos, Vector2D vel, float newSize, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

