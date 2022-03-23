#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Spaceship : public GameObject
{
private:
	Vector2D velocity; //Velocity of spaceship
	Vector2D acceleration; //Acceleration of spaceship
	Vector2D friction; //Friction of spaceship

	Circle2D collisionShape; //Collision for spaceship

	float shootDelay = 0.0f; //Delay on the shot

	const float accPower = 250.0f; //Acceleartion power
	const float rotSpeed = 4.0f; //Speed of rotation
	const float frictionPower = -0.5f; //Variable to reduce speed
	const Vector2D gravity = Vector2D(0.0, -0.98); //Gravity variable

	ObjectManager* pObjectManager;

public:
	Spaceship();
	~Spaceship();

	void Initialise(Vector2D initPos, ObjectManager* pOM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};
