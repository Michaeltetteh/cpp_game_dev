#ifndef ASTEROID_ENTITY_HPP
#define ASTEROID_ENTITY_HPP


#include <SFML/Graphics/Drawable.hpp>
#include "Configuration.hpp"
#include "World.hpp"


class Entity : public sf::Drawable
{
public:
    Entity(const Entity&) = delete;
    Entity &operator=(const Entity&)= delete;
    Entity(asteroid::Configuration::Texture tex_id, World &world);
    virtual ~Entity();

    virtual bool isAlive() const;
    const sf::Vector2f &getPosition() const;
    template<typename ...Args>
    void setPosition(Args&& ...args);
    virtual bool isCollide(const Entity &other) const = 0;

    virtual void update(sf::Time deltaTime) = 0;
    virtual void onDestroy();

protected:
    sf::Sprite      _sprite;
    sf::Vector2f    _impulse;
    World           &_world;
    bool            _alive;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //ASTEROID_ENTITY_HPP
