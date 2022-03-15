#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::loadImage(const wchar_t filename[])
{
	image = MyDrawEngine::GetInstance()->LoadPicture(filename);
}

void GameObject::loadSound(const wchar_t filename[])
{
	MySoundEngine* pSE = MySoundEngine::GetInstance();
	sound = pSE->LoadWav(filename);
	pSE->Play(sound);

}

void GameObject::Render()
{
	if (active)
	{
		//Draw image
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, angle);
	}
}

bool GameObject::IsActive() const
{
	return active;
}

void GameObject::Deactivate()
{
	active = false;
}