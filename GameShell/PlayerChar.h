#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class PlayerChar : public GameObject
{
private:
	Vector2D velocity; //Velocity of spaceship
	Vector2D acceleration; //Acceleration of spaceship
	Vector2D friction; //Friction of spaceship

	Circle2D collisionShape; //Collision for spaceship

	bool isOnGround;
	float jumpForce = 100.0f;

	float frictionPower = -0.5f; //Variable to reduce speed
	const Vector2D gravity = Vector2D(0, -50.0f); //Gravity variable

	ObjectManager* pObjectManager;

public:
	PlayerChar();
	~PlayerChar();

	bool IsOnGround() const;

	void Initialise(Vector2D initPos, ObjectManager* pOM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};

