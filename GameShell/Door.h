#pragma once
#include "GameObject.h"

//Promise that this class exists
class ObjectManager;
class GameManager;

class Door : public GameObject
{
private:
	Rectangle2D collisionShape; //Collision shape of door

	ObjectManager* pObjectManager; //Pointer to object manager
	GameManager* pGameManager; //Pointer to game manager

public:
	Door();
	~Door();
	//void Initialise(ObjectManager* pOM);
	void Initialise(Vector2D pos, ObjectManager* pOM, GameManager* pGM); //Initilaise door
	void Update(float frameTime) override; //Update door

	IShape2D& GetShape(); //Get door shape
	void ProcessCollision(GameObject& gameObject); //Process door collision

	static const int DOORWIDTH = 138;
	static const int DOORHEIGHT = 186;
};