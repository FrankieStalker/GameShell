//Created by w18010435
//Spikes class used to store all the function declarations and variables for Spike class

#pragma once
#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Spikes : public GameObject
{
private:
	Rectangle2D collisionShape;

	ObjectManager* pObjectManager = nullptr;

	GameManager* pGameManager = nullptr;

	static const int SPIKESIZE = 510;

public:
	Spikes();
	~Spikes();

	void Initialise(Vector2D pos, float size, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

