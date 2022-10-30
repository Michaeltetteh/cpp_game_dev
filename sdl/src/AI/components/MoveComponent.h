#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H

#include "Component.h"

class MoveComponent : public Component
{
public:
    MoveComponent(class Actor * actor, int UpdateOrder=10);

    void Update(float deltaTime) override;

    void SetAngularSpeed(float angularSpeed) { mAngularSpeed = angularSpeed;}
    float GetAngularSpeed() { return mAngularSpeed;}
    void SetForwardSpeed(float forward) { mForwardSpeed = forward;}
    float GetForwardSpeed(){ return mForwardSpeed;}


private:
    float mAngularSpeed; //in radians/second
    float mForwardSpeed;
};


#endif