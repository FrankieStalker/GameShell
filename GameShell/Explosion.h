#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;

class Explosion : public GameObject
{
private:
	const wchar_t imgArray[8][25] = { L"explosion1.bmp", L"explosion2.bmp", L"explosion3.bmp", L"explosion4.bmp", L"explosion5.bmp", L"explosion6.bmp", L"explosion7.bmp", L"explosion8.bmp" };

	Circle2D collisionShape;
	ObjectManager* pObjectManager;
public:
	Explosion();
	~Explosion();

	void Initialise(Vector2D pos);
	void Update(float frameTime) override;

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};

