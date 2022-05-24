#ifndef ASTEROID_COLLISION_HPP
#define ASTEROID_COLLISION_HPP

#include <SFML/Graphics/Sprite.hpp>

class Collision
{
    Collision() = delete;
    Collision(const Collision &) = delete;
    Collision &operator=(const Collision&) = delete;

    static bool circleTest(const sf::Sprite &first,const sf::Sprite &second);
};

#endif