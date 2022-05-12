//Created by w18010435
//Door class used to store all the function declarations and variables for Door class

#pragma once
#include "GameObject.h"

//Forward declartion
class ObjectManager;
class GameManager;

class Door : public GameObject
{
private:
	Rectangle2D collisionShape; //Collision shape of door

	ObjectManager* pObjectManager = nullptr; //Pointer to object manager
	GameManager* pGameManager = nullptr; //Pointer to game manager

public:
	Door();
	~Door();

	void Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM); //Initilaise door
	void Update(float frameTime) override; //Update door

	IShape2D& GetShape(); //Get door shape
	void ProcessCollision(GameObject& gameObject); //Process door collision

	//Variables for door height and width
	static const int DOORWIDTH = 138;
	static const int DOORHEIGHT = 186;
};