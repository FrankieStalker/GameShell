#pragma once

#include "mydrawengine.h"

class GameObject
{
private:
	PictureIndex image;
protected:
	Vector2D pos;
	bool active;
	float angle;
	std::wstring path;

	void loadImage(std::wstring fileName);		//This is the fucntion I'm confused about
public:
	void Render();
	void Initialize();
	virtual void Update() = 0;
};