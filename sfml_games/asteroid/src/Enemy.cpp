#include "../headers/Enemy.hpp"
#include "../headers/random.hpp"
namespace asteroid
{
    Enemy::Enemy(asteroid::Configuration::Textures tex_id, World &world)
            : Entity(tex_id,world)
    {
        float angle = asteroid::random(0.f,2.f*M_PI);
        _impulse = sf::Vector2f(std::cos(angle),std::sin(angle));
    }

    void Enemy::onDestroy()
    {
        Entity::onDestroy();
        asteroid::Configuration::addScore(getPoints());
    }
}
