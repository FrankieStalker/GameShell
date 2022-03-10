#pragma once
#include "GameObject.h"

class Rock : public GameObject
{
private:
	Vector2D velocity;
	Vector2D friction;
	Vector2D acceleration;

	int number = rand() % 4;
	const wchar_t imgArray[4][25] = { L"rock1.bmp", L"rock2.bmp", L"rock3.bmp", L"rock4.bmp" };

public:
	Rock();
	~Rock();
	void Initialise();
	void Update(float frameTime);
};