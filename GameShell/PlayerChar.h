#pragma once

#include "GameObject.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class PlayerChar : public GameObject
{
private:
	Vector2D velocity; //Velocity of spaceship
	Vector2D acceleration; //Acceleration of spaceship

	Circle2D collisionShape; //Collision for spaceship
	/*PictureIndex expImg[14];
	float currentImg = 0.0f;*/
	float cameraHeight;
	float cameraWidth;

	float shootDelay = 0.0f; //Delay on the shot
	float levelCompleteJumpTimer;

	bool isOnGround;
	const float JUMP_FORCE = 4000.0f;

	bool ready;

	//float frictionPower = -0.5f; //Variable to reduce speed
	const float FRICTION = 5.0f;
	const Vector2D GRAVITY = Vector2D(0, -5000.0f); //Gravity variable

	ObjectManager* pObjectManager;
	GameManager* pGameManager;

public:
	PlayerChar();
	~PlayerChar();

	bool IsOnGround() const;

	void Initialise(Vector2D initPos, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;
	//void Render();

	void StartPlay();
	bool IsReady();

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};