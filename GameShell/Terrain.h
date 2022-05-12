//Created by w18010435
//Terrain class used to store all the function declarations and variables for Terrain class

#pragma once
#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Terrain : public GameObject
{
private:
	Rectangle2D collisionShape;

protected:
	ObjectManager* pObjectManager = nullptr;

	GameManager* pGameManager = nullptr;

public:
	Terrain();
	~Terrain();

	void Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};