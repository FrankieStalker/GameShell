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
};