#include "rock.h"

Rock::Rock()
{
	active = false;
}

Rock::~Rock()
{

}

void Rock::Initialise()
{
	Vector2D randPos;
	randPos.setBearing(rand() % 628 / 100.0f, rand() % 400 + 600);
	position = randPos;
	active = true;

	loadImage(imgArray[number]);
}

void Rock::Update(float frameTime)
{
	velocity = Vector2D(rand() % 10 - 20, rand() % 50 - 100);
	position = position + velocity * frameTime;
}