
#ifndef ASTEROID_SAUCER_HPP
#define ASTEROID_SAUCER_HPP

#include "Enemy.hpp"
#include "Collision.hpp"

class Saucer : public Enemy
{
public:
    Saucer(const Saucer&) = delete;
    Saucer &operator=(const Saucer&) = delete;

    using Enemy::Enemy;

    virtual bool isCollide(const Entity& other) const;
    virtual  void update(sf::Time deltaTime);
    virtual void onDestroy();
    static void newSaucer(World &world);
};

#endif