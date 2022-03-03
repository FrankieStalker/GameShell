#pragma once

#include "mydrawengine.h"
#include "GameObject.h"

class Spaceship : public GameObject
{
private:
	Vector2D velocity;
	Vector2D position;
	Vector2D acceleration;
	Vector2D friction;
	
	float angle;
	bool active;
	PictureIndex img;

	float frameTime = 0.016;

	const float accPower = 250.0f;
	const float rotSpeed = 4.0f;
	const float frictionPower = -2.0f;
	const Vector2D gravity = Vector2D(0.0, -0.98);

public:
	Spaceship();
	~Spaceship();

	void Initialise(Vector2D initPos);
	void Render();
	void Update();

};