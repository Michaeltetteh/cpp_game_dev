#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include "../headers/Player.hpp"
#include "../headers/Configuration.hpp"

Player::Player(World &world)
    : Entity(asteroid::Configuration::Texture::Player,world),
      ActionTarget(asteroid::Configuration::player_inputs),
      _isMoving(false),
      _rotation(0)
    {
        bind(asteroid::Configuration::PlayerInputs::UP,[this](const sf::Event&){
            _isMoving = true;
        });

        bind(asteroid::Configuration::PlayerInputs::LEFT,[this](const sf::Event&){
            _rotation -= 1;
        });

        bind(asteroid::Configuration::PlayerInputs::RIGHT,[this](const sf::Event&){
            _rotation += 1;
        });

        bind(asteroid::Configuration::PlayerInputs::Shoot,[this](const sf::Event&){
            shoot();
        });
        bind(asteroid::Configuration::PlayerInputs::Hyperspace,[this](const sf::Event&){
           goToHyperspace();
        });
    }

bool Player::isCollide(const Entity &other) const
{
    if (dynamic_cast<const ShootPlayer *>(&other) == nullptr)
        return Collision::circleTest(_sprite, other._sprite);
    return false;
}

void Player::shoot()
{
    if(_timeSinceLastShoot > sf::seconds(0.3))
    {
        _world.add(new ShootPlayer(*this));
        _timeSinceLastShoot = sf::Time::Zero;
    }
}

void Player::goToHyperspace()
{
    _impulse = sf::Vector2f(0,0);
    setPosition(random(0,_world.getX()),random(0,_world.getY()));
    _world.add(asteroid::Configuration::Sounds::Jump);
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    _timeSinceLastShoot += deltaTime;
    if(_rotation != 0)
    {
        float angle = _rotation * 250 * seconds;
        _sprite.rotate(angle);
    }
    if(_isMoving)
    {
        float angle = _sprite.getRotation() / 180 * M_PI - M_PI / 2;
        _impulse += sf::Vector2f(std::cos(angle),std::sin(angle)) * 300.f * seconds;
    }
    _sprite.move(seconds * _impulse);
}

void Player::onDestroy()
{
    Entity::onDestroy();
    asteroid::Configuration::lives--;
    _world.add(asteroid::Configuration::Sounds::Boom);
}
void Player::processEvents()
{
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}
