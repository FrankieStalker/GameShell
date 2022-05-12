//Created by w18010435
//Abstract super class that all game objects inherit from

#pragma once

#include "mydrawengine.h"
#include "mysoundengine.h"

class GameObject
{
private:
	PictureIndex image; //Image for object
	SoundIndex sound; //Sound for object
protected:
	Vector2D position; //Starting position of object
	bool active; //Status check
	float angle; //Angle in which is spawns

	float frameTime = 0.016f; //Frame time for 60s

	float size;

	PictureIndex loadImage(const wchar_t filename[]); //Load image function
	void loadSound(const wchar_t fileName[]); //load sound function
public:
	GameObject();
	virtual ~GameObject();

	virtual void Render(); //Render function
	virtual void Update(float frameTime) = 0; //Abstract update fucntion

	int GetEdge(Vector2D other);

	virtual IShape2D& GetShape() = 0; //Abstract function for collision
	virtual void ProcessCollision(GameObject& gameObject) = 0; //Abstract function for checking collsion

	const Vector2D& getPos() const;

	bool IsActive() const;
	void Deactivate();

	static const int WIDTH = 510;
	static const int HEIGHT = 125;
};