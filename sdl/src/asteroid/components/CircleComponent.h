#ifndef CIRCLECOMPONENT_H
#define CIRCLECOMPONENT_H

#include "Component.h"
#include "../../../lib/math/Math.h"

class CircleComponent : public Component
{
public:
    CircleComponent(class Actor *owner);

    void SetRadius(float radius){ mRadius = radius;}
    float GetRadius() const;


    const Vector2 &GetCenter() const;

private:
    float mRadius;
};

bool Intersects(const CircleComponent &a, const CircleComponent &b);

#endif