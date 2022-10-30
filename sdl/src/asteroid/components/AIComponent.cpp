#include "AIComponent.h"

AIComponent::AIComponent(Actor *owner)
    :Component(owner)
    {}

void AIComponent::RegisterState(AIState *state)
{
    mStateMap.emplace(state->GetName(),state);
}

void AIComponent::Update(float deltaTime)
{
    if(mCurrentState)
        mCurrentState->Update(deltaTime);
}

