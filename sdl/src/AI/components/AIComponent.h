#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "Component.h"
#include <string>
#include <unordered_map>


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