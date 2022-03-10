#pragma once

#include "mydrawengine.h"

class GameObject
{
private:
	PictureIndex image; //Image for object
protected:
	Vector2D position; //Starting position of object
	bool active; //Status check
	float angle; //Angle in which is spawns

	float frameTime = 0.016f; //Frame time for 60s

	void loadImage(const wchar_t filename[]); //Load image function
public:
	GameObject();
	~GameObject();

	void Render(); //Render function
	virtual void Update(float frameTime) = 0; //Abstract update fucntion
};