#include "Spikes.h"

#include "objectmanager.h"
#include "GameManager.h"

Spikes::Spikes(){}

Spikes::~Spikes(){}

void Spikes::Initialise(Vector2D pos, float platSize, ObjectManager* pOM, GameManager* pGM)
{
    position = pos;
    size = platSize;
    pObjectManager = pOM;
    pGameManager = pGM;
    active = true;
    collisionShape.PlaceAt(pos.YValue + SPIKESIZE / 2, pos.XValue - SPIKESIZE / 2, pos.YValue - SPIKESIZE / 2, pos.XValue + SPIKESIZE / 2);

    loadImage(L"spikes.png");
}

void Spikes::Update(float frameTime){}

Vector2D Spikes::GetCollsionNormal(Circle2D other)
{
    return collisionShape.CollisionNormal(other);
}

IShape2D& Spikes::GetShape()
{
    // TODO: insert return statement here
    return collisionShape;
}

void Spikes::ProcessCollision(GameObject& gameObject){}
