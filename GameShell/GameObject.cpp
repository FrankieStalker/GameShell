#include "GameObject.h"

GameObject::GameObject()
{
	size = 1.0f;
}

GameObject::~GameObject()
{

}

PictureIndex GameObject::loadImage(const wchar_t filename[])
{
	image = MyDrawEngine::GetInstance()->LoadPicture(filename);

	return image;
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
		pDE->DrawAt(position, image, size, angle);
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
