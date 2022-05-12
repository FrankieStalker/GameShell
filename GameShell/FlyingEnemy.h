//Created by w18010435
//Flying enemy class used to store all the function declarations and variables for FlyingEnemy class

#pragma once
#include "Enemy.h"

class FlyingEnemy : public Enemy
{
public:
	FlyingEnemy();
	~FlyingEnemy();

	void Initialise(Vector2D pos, Vector2D vel, float newSize, float newAngle, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};

