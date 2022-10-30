#include "MoveComponent.h"
#include "../../../lib/math/Math.h"
#include "../actors/Actor.h"

MoveComponent::MoveComponent(class Actor *actor, int UpdateOrder)
        :Component(actor,UpdateOrder),
         mAngularSpeed(0.0f),
         mForwardSpeed(0.0f)
        {}


void MoveComponent::Update(float deltaTime)
{
    if(!Math::NearZero(mAngularSpeed)) {
        float rotation = mOwner->GetRotation();
        rotation += mAngularSpeed * deltaTime;
        mOwner->SetRotation(rotation);
    }
    if(!Math::NearZero(mForwardSpeed)) {
        Vector2 pos = mOwner->GetPosition();
        pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

        // (Screen wrapping code only for asteroids)
        if (pos.x < 0.0f) { pos.x = 1022.0f; }
        else if (pos.x > 1024.0f) { pos.x = 2.0f; }

        if (pos.y < 0.0f) { pos.y = 766.0f; }
        else if (pos.y > 768.0f) { pos.y = 2.0f; }

        mOwner->SetPosition(pos);
    }
}