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

void GameObject::Update(float frameTime)
{
	if (position.XValue > 1800.0f || position.XValue < -1800.0f)
	{
		position.XValue *= -1;
	}

	if (position.YValue > 1000.0f || position.YValue < -1000.f)
	{
		position.YValue *= -1;
	}
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

const Vector2D& GameObject::getPos() const
{
	// TODO: insert return statement here
	return position;
}

bool GameObject::IsActive() const
{
	return active;
}

void GameObject::Deactivate()
{
	active = false;
}