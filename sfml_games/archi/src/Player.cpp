#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include "../headers/Player.hpp"
#include "../headers/Configuration.hpp"

Player::Player()
    : ActionTarget(book::Configuration::player_inputs),
      _isMoving(false),
      _rotation(0)
    {
//        _shape.setFillColor(sf::Color::Blue);
        _ship.setTexture(book::Configuration::textures.get(book::Configuration::Texture::Player));
        _ship.setOrigin(16,16);

        bind(PlayerInputs::UP,[this](const sf::Event&){
            _isMoving = true;
        });

        bind(PlayerInputs::LEFT,[this](const sf::Event&){
            _rotation -= 1;
        });

        bind(PlayerInputs::RIGHT,[this](const sf::Event&){
            _rotation += 1;
        });
    }

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    if(_rotation != 0)
    {
        float angle = _rotation * 180 * seconds;
        _ship.rotate(angle);
    }
    if(_isMoving)
    {
        float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;
        _velocity += sf::Vector2f(std::cos(angle),std::sin(angle)) * 60.f * seconds;
    }
    _ship.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_ship,states);
}


void Player::processEvents()
{
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}

void Player::setDefaultInputs()
{
    _playerInputs.map(PlayerInputs::UP,Action(sf::Keyboard::Up));
    _playerInputs.map(PlayerInputs::RIGHT,Action(sf::Keyboard::Right));
    _playerInputs.map(PlayerInputs::LEFT,Action(sf::Keyboard::Left));
}

ActionMap<int> Player::_playerInputs;