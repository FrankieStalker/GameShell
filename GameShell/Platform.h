#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Platform : public GameObject
{
private:
	Rectangle2D collisionShape; //Collision for spaceship

	ObjectManager* pObjectManager;

public:
	Platform();
	~Platform();

	void Initialise(Vector2D initPos, ObjectManager* pOM);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};

