//Created by w18010435
//All declarions for ObjectManager class

#pragma once
#include <list>
#include "GameObject.h"

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
	void DeleteInactiveObjects();
	void CheckAllCollision();
};