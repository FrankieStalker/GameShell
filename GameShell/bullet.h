//Created by w18010435
//Bullet class used to store all the function declarations and variables for Bullet class

#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
private:
	Vector2D velocity; //Volicty of bullet

	Circle2D collisionShape;

	float timeDelay = 2.0f; //Bullet time
public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D bulletPos, Vector2D bulletVel);
	void Update(float frameTime);

	void Shoot(); //Function for player shoot sound

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);
};