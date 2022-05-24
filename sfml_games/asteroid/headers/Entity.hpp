#ifndef ASTEROID_ENTITY_HPP
#define ASTEROID_ENTITY_HPP


#include <SFML/Graphics/Drawable.hpp>
#include "Configuration.hpp"
#include "World.hpp"

namespace asteroid
{
    class World;
    class Entity : public sf::Drawable
    {
    public:
        Entity(const Entity&) = delete;
        Entity &operator=(const Entity&)= delete;
        Entity(asteroid::Configuration::Textures tex_id, World &world);
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

        friend class Meteor;
        friend class Player;
        friend class Saucer;
        friend class ShootPlayer;
        friend class ShootSaucer;

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };

    template<typename ... Args>
    void Entity::setPosition(Args&& ... args)
    {
        _sprite.setPosition(std::forward<Args>(args)...);
    }
}


#endif //ASTEROID_ENTITY_HPP
