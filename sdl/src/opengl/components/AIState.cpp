#include "AIComponent.h"
#include "AIState.h"
#include "Logger/Logger.h"


void AIPatrol::Update(float deltaTime)
{
    std::ignore = deltaTime;
    LOG_INFO("Updating %s state", GetName())
    bool dead = true;
    if (dead)
    {
        mOwner->ChangeState("Death");
    }
}

void AIPatrol::OnEnter()
{
    LOG_INFO("Entering %s state", GetName())
}

void AIPatrol::OnExit()
{
    LOG_INFO("Exiting %s state", GetName())
}

void AIDeath::Update(float deltaTime)
{
    std::ignore = deltaTime;
    LOG_INFO("Updating %s state", GetName())
}

void AIDeath::OnEnter()
{
    LOG_INFO("Entering %s state", GetName())
}

void AIDeath::OnExit()
{
    LOG_INFO("Exiting %s state", GetName())
}

void AIAttack::Update(float deltaTime)
{
    std::ignore = deltaTime;
    LOG_INFO("Updating %s state", GetName())
}

void AIAttack::OnEnter()
{
    LOG_INFO("Entering %s state", GetName())
}

void AIAttack::OnExit()
{
    LOG_INFO("Exiting %s state", GetName())
}
