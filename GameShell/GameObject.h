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

	virtual void loadImage(const wchar_t filename[]); //Load image function
public:
	void Render(); //Render function
	virtual void Update() = 0; //Abstract update fucntion
};