#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "MoveComponent.h"

class InputComponent : public  MoveComponent
{
public:
    InputComponent(class Actor *owner);

    void ProcessInput(const uint8_t *keyState);

    void SetMaxAngularSpeed(float angularSpeed){ mMaxAngularSpeed = angularSpeed;}
    float GetMaxAngularSpeed(){return mMaxAngularSpeed;}

    void SetMaxForwardSpeed(float forwardSpeed){ mMaxForwardSpeed = forwardSpeed;}
    float GetMaxForwardSpeed(){return mMaxForwardSpeed;}

    void SetForwardKey(int forwardKey) { mForwardKey = forwardKey;}
    int GetForwardKey(){return mForwardKey;}

    void SetBackKey(int backKey) { mBackKey = backKey;}
    int GetBackKey(){return mBackKey;}

    void SetCounterClockWiseKey(int counterClockWiseKey) { mCounterClockwiseKey = counterClockWiseKey;}
    int GetCounterClockWiseKey(){return mCounterClockwiseKey;}

    void SetClockWiseKey(int clockWiseKey) { mClockwiseKey = clockWiseKey;}
    int GetClockWiseKey(){return mClockwiseKey;}

private:
    float mMaxForwardSpeed;
    float mMaxAngularSpeed;

    int mForwardKey;
    int mBackKey;

    int mClockwiseKey;
    int mCounterClockwiseKey;

};


#endif