#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "Component.h"
#include <string>
#include <unordered_map>

class AIState
{

public:
    AIState(class AIComponent *owner)
        :mOwner(owner)
        {}
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update(float deltaTime) = 0;

    virtual const char* GetName() const = 0;
protected:
    class AIComponent *mOwner;
};


class AIComponent : public Component
{
public:
    AIComponent(class Actor *owner);

    void Update(float deltaTime) override;
    void ChangeState(const std::string& name);

    //add a state
    void RegisterState(class AIState *state);
private:
    std::unordered_map<std::string, class AIState*> mStateMap;
    class AIState *mCurrentState; //current state
};

#endif