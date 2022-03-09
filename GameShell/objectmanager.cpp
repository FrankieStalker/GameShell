#include "objectmanager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(GameObject* pNewObject)
{

}

void ObjectManager::UpdateAll(float frameTime)
{
	if (!nullptr)
	{
		for (GameObject*& pNext : pObjectList)
		{
			pNext->Update();
		}
	}
}

void ObjectManager::RenderAll()
{
	if (!nullptr)
	{
		for (GameObject*& pNext : pObjectList)
		{
			pNext->Render();
		}
	}
}

void ObjectManager::DeleteAllObjects()
{
	for (GameObject* pNext : pObjectList)
	{
		delete pNext;
		pNext = nullptr;
	}
	pObjectList.clear();
}