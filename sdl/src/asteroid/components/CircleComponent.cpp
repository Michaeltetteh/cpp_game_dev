#include "CircleComponent.h"
#include "../actors/Actor.h"


CircleComponent::CircleComponent(Actor *owner)
    :Component(owner), 
     mRadius(0.0f)
{}

float CircleComponent::GetRadius() const
{
    return mOwner->GetScale() * mRadius;
}

const Vector2 &CircleComponent::GetCenter() const
{
    return mOwner->GetPosition();
}


bool Intersects(const CircleComponent &a, const CircleComponent &b)
{
    //calc distance squared
    Vector2 diff = a.GetCenter() - b.GetCenter();
    float distanceSquared = diff.LengthSq(); // for comparison, not true distance we avoid sqrt() since its expensive

    float radiiSquared = a.GetRadius() + b.GetRadius();
    radiiSquared *= radiiSquared;  // (sum of radii)^2

    return distanceSquared <= radiiSquared; // has collided if distanceSquared <= radiiSquared
}