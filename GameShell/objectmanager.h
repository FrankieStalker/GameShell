#pragma once
#include <list>
#include "GameObject.h"

//Promise that classes exist
class Spaceship;
class Rock;
class GameObject;

class ObjectManager
{
private:
	std::list<GameObject*> pObjectList;
public:
	ObjectManager();
	~ObjectManager();

	void AddObject(GameObject* pNewObject);
	void UpdateAll(float frameTime);
	void RenderAll();
	void DeleteAllObjects();
};