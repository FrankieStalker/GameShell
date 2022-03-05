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
	position = Vector2D(rand() % 600, rand() % 1200 - 600);
	active = true;

	loadImage(imgArray[number]);
}

void Rock::Update()
{
	velocity = Vector2D(rand() % 10 - 20, rand() % 50 - 100);
	position = position + velocity * frameTime;
}