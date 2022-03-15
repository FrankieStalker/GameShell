#include "objectmanager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::AddObject(GameObject* pNewObject)
{
	//Place object at the end of list
	pObjectList.push_back(pNewObject);
}

void ObjectManager::UpdateAll(float frameTime)
{
	//Loop through each object in the list
	for (GameObject* pNext : pObjectList)
	{
		//Check to see if not nullptr
		if (pNext != nullptr)
		{
			//If not, then update
			pNext->Update(frameTime);
		}
	}
}

void ObjectManager::RenderAll()
{
	MyDrawEngine::GetInstance()->WriteInt(50, 50, pObjectList.size(), MyDrawEngine::GREEN);

	//Loop through each object in the list
	for (GameObject* pNext : pObjectList)
	{
		//Check to see if not nullptr
		if (pNext != nullptr)
		{
			//If not, then render
			pNext->Render();
		}
	}
}

void ObjectManager::DeleteAllObjects()
{
	//Loop through each object in the list
	for (GameObject* pNext : pObjectList)
	{
		//Delete object
		delete pNext;
		//Set to nullptr
		pNext = nullptr;
	}
	//Clear the object list
	pObjectList.clear();
}

void ObjectManager::DeleteInactiveObjects()
{
	for (GameObject*& pNext : pObjectList)
	{
		if(!pNext->IsActive())
		{
			delete pNext;
			pNext = nullptr;
		}
	}
	pObjectList.remove(nullptr);
}