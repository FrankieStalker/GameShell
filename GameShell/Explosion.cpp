#include "Explosion.h"
#include "objectmanager.h"

Explosion::Explosion()
{
	active = false;
}

Explosion::~Explosion()
{

}

void Explosion::Initialise(Vector2D pos)
{
	position = pos;
	active = true;

	currentImg = 0;

	expImg[0] = loadImage(L"explosion1.bmp");
	expImg[1] = loadImage(L"explosion2.bmp");
	expImg[2] = loadImage(L"explosion3.bmp");
	expImg[3] = loadImage(L"explosion4.bmp");
	expImg[4] = loadImage(L"explosion5.bmp");
	expImg[5] = loadImage(L"explosion6.bmp");
	expImg[6] = loadImage(L"explosion7.bmp");
	expImg[7] = loadImage(L"explosion8.bmp");
}

void Explosion::Render()
{
	if (active)
	{
		MyDrawEngine::GetInstance()->DrawAt(position, expImg[(int)currentImg], size*2, angle);
	}
}

void Explosion::Update(float frameTime)
{
	currentImg = currentImg + 0.1f;
	if (currentImg >= 8)
	{
		Deactivate();
	}
}

IShape2D& Explosion::GetShape()
{
	return collisionShape;
}

void Explosion::ProcessCollision(GameObject& gameObejct)
{

}

void Explosion::Explode()
{
	loadSound(L"explosion5.wav");
}
