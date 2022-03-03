#include "GameObject.h"

void GameObject::Initialize()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(path.c_str());
}

void GameObject::loadImage(std::wstring fileName)
{
	path = fileName;
}