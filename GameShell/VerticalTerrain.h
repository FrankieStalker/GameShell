//Created by w18010435
//Vertical Terrain class used to store all the function declarations and variables for Vertical Terrain class

#pragma once
#include "Terrain.h"

class VerticalTerrain : public Terrain
{
private:
	Rectangle2D collisionShape;

public:
	VerticalTerrain();
	~VerticalTerrain();

	void Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM);
	void Update(float frameTime) override;

	Vector2D GetCollsionNormal(Circle2D other);

	IShape2D& GetShape();
	void ProcessCollision(GameObject& gameObject);

	static const int VERTWIDTH = 125;
	static const int VERTHEIGHT = 510;
};

