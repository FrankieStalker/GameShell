#pragma once
#include "GameObject.h"
#include "mysoundengine.h" // Includes sound engine

class Bullet : public GameObject
{
private:
	Vector2D velocity; //Volicty of bullet
	SoundIndex shootSound; //Shoot sound

	float timeDelay = 2.0f; //Bullet time
public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D bulletPos, Vector2D bulletVel);
	void Update(float frameTime);
	void Shoot();
};
