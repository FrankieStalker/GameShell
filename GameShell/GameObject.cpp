//Created by w18010435
//Functions definitions for all Superclass fucntions
//Class where all game objects get their core functionality from

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

int GameObject::GetEdge(Vector2D other)
{
	if (other.XValue < position.XValue - WIDTH / 2) return 3; //Left
	else if (other.XValue > position.XValue + WIDTH / 2) return 4; //Right
	else if (other.YValue > position.YValue + HEIGHT / 2) return 1; //Top
	else if (other.YValue < position.YValue - HEIGHT / 2) return 2; //Bottom
	else if (other.XValue > position.XValue) return 1; //Top
	else { return 2; } //Bottom
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