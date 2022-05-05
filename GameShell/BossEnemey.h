#pragma once
#include "Enemy.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class BossEnemy : public Enemy
{
private: 
	int health;
public:
	BossEnemy();
	~BossEnemy();

	void Initialise(Vector2D pos, Vector2D vel, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	int GetHealth();

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);

	static const int BOSSSIZE = 2050;
};

