#pragma once

#include "GameObject.h"

class Spaceship : public GameObject
{
private:
	Vector2D velocity; //Velocity of spaceship
	Vector2D acceleration; //Acceleration of spaceship
	Vector2D friction; //Friction of spaceship

	float frameTime = 0.016; //Frame time for 60s

	const float accPower = 250.0f; //Acceleartion power
	const float rotSpeed = 4.0f; //Speed of rotation
	const float frictionPower = -0.5f; //Variable to reduce speed
	const Vector2D gravity = Vector2D(0.0, -0.98); //Gravity variable

public:
	Spaceship();
	~Spaceship();
	void Initialise(Vector2D initPos);
	void Update();
};