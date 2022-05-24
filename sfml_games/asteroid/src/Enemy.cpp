#include "../headers/Enemy.hpp"

Enemy::Enemy(asteroid::Configuration::Texture tex_id, World &world)
    : Entity(tex_id,world),
    {
        float angle = random(0.f,2.f*M_PI);
        _impulse = sf::Vector2f(std::cos(angle),std::sin(angle));
    }

void Enemy::onDestroy()
{
    Entity::onDestroy();
    asteroid::Configuration::addScore(getPoints());
}