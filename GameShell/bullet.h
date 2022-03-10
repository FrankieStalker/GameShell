#pragma once
#include "spaceship.h"
#include "mysoundengine.h" // Includes sound engine

class Bullet : public Spaceship
{
private:
	Vector2D velocity; //Volicty of bullet
	SoundIndex shootSound; //Shoot sound
public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D bulletPos, Vector2D bulletVel);
};
