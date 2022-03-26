#include "objectmanager.h"
#include <iostream>

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
	MyDrawEngine::GetInstance()->WriteText(50, 50, L"No. Of Objects:", MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteInt(100, 70, pObjectList.size(), MyDrawEngine::GREEN);

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

void ObjectManager::CheckAllCollision()
{
	std::list<GameObject*>::iterator it1;
	std::list<GameObject*>::iterator it2;
	for (it1 = pObjectList.begin(); it1 != pObjectList.end(); it1++)
	{
		for (it2 = std::next(it1); it2 != pObjectList.end(); it2++)
		{
			if ((*it1) && (*it2) &&
				(*it1)->IsActive() && (*it2)->IsActive() && //Check if active
				(*it1)->GetShape().Intersects((*it2)->GetShape()))
			{
				(*it1)->ProcessCollision((**it2));
				(*it2)->ProcessCollision((**it1));
			}
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
		if (!pNext->IsActive())
		{
			delete pNext;
			pNext = nullptr;
		}
	}
	pObjectList.remove(nullptr);
}