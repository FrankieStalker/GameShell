//Created by w18010435
//Boss enemy class used to store all the function declarations and variables for BossEnemy class

#pragma once
#include "Enemy.h"

class BossEnemy : public Enemy
{
private: 
	int health; //Variable for storing boss health
public:
	BossEnemy();
	~BossEnemy();

	void Initialise(Vector2D pos, Vector2D vel, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	int GetHealth();

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);

	static const int BOSSSIZE = 2050; //Variable for stroing boss size
};

