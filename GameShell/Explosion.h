#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Explosion : public GameObject
{
private:
	PictureIndex expImg[8];
	float currentImg = 0.0f;
	Circle2D collisionShape;
public:
	Explosion();
	~Explosion();

	void Initialise(Vector2D pos);
	void Update(float frameTime) override;
	void Render();

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};

