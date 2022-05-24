#include "../headers/Saucer.hpp"

bool Saucer::isCollide(const Entity &other) const
{
    if(dynamic_cast<const ShootSaucer*>(&other) == nullptr)
        return Collision::circleTest(_sprite,other._sprite);
    return false;
}

void Saucer::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    float *near = nullptr;
    float near_distance = 300;
    for(Entity *entity_ptr : _world.getEntities())
    {
        if(entity_ptr != this && (dynamic_cast<const Meteor*>(entity_ptr) ||dynamic_cast<const ShootPlayer*>(entity_ptr)))
        {
            float x = getPosition().x - entity_ptr->getPosition().x;
            float y = getPosition().y - entity_ptr->getPosition().y;
            float dist = std::sqrt(x*x + y*y);
            if(dist < near_distance)
            {
                near_distance = dist;
                near = entity_ptr;
            }
        }
    }
    if(near != nullptr)
    {
        sf::Vector2f pos = near->getPosition() - getPosition();
        float  angle_rad = std::atan2(pos.y,pos.x);
        _impulse -= sf::Vector2f(std::cos(angle_rad),std::sin(angle_rad))* 300.f * seconds;
    }else
    {
     sf::Vector2f pos = asteroid::Configuration::player->getPostition() - getPosition();
     float  angle_rad = std::atan2(pos.y,pos.x);
     _impulse += sf::Vector2f (std::cos(angle_rad),std::sin(angle_rad)) *100.f * seconds;
    }
    _sprite.move(seconds * _impulse);
}