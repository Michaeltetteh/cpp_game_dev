#include "AIComponent.h"
#include "../utils/Logger.h"
#include "AIState.h"

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

void AIComponent::ChangeState(const std::string &name)
{
    //exit the current state
    if(mCurrentState)
        mCurrentState->OnExit();

    //find new state
    auto iter = mStateMap.find(name);
    if(iter != mStateMap.end())
    {
        //set sate to current state and enter
        mCurrentState = iter->second;
        mCurrentState->OnEnter();
    }
    else
    {
        LOG_INFO("Could not find AIState %s in state map", name.c_str())
        mCurrentState = nullptr;
    }
}

