#include "Component.h"
#include "../actors/Actor.h"

Component::Component(Actor* owner, int updateOrder)
    :mOwner(owner)
    ,mUpdateOrder(updateOrder)
{
    // Add to actor's vector of components
    mOwner->AddComponent(this);
}

Component::~Component()
{
    mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime){std::ignore = deltaTime;}

void Component::ProcessInput(const uint8_t *keyState) { std::ignore = keyState;}