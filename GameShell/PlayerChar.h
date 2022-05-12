//Created by w18010435
//Player character class used to store all the function declarations and variables for PlayerChar class

#pragma once

#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class PlayerChar : public GameObject
{
private:
	Vector2D velocity; //Velocity of spaceship
	Vector2D acceleration; //Acceleration of spaceship

	Circle2D collisionShape; //Collision for spaceship
	float cameraHeight;

	float shootDelay = 0.0f; //Delay on the shot
	float levelCompleteJumpTimer; //Deleay on starting new level when completed

	bool isOnGround; //Varaible to store if player is on ground?
	const float JUMP_FORCE = 4000.0f; //Strength of the jump

	float deathTimer; //Timer to start when player dies

	bool ready; //Check if player is ready before starting level

	const float FRICTION = 5.0f; // Friction to slow down
	const Vector2D GRAVITY = Vector2D(0, -5000.0f); //Gravity variable

	//Pointer to Object and Game manager
	ObjectManager* pObjectManager; 
	GameManager* pGameManager;

public:
	PlayerChar();
	~PlayerChar();

	bool IsOnGround() const; //Setter for on ground varaible

	void Initialise(Vector2D initPos, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	void StartPlay(); //Setter for ready to true
	bool IsReady(); //Get for ready variable

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObejct);
};