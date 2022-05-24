
#ifndef ASTEROID_ENEMY_HPP
#define ASTEROID_ENEMY_HPP

#include "Entity.hpp"

namespace asteroid
{
    class Enemy : public  Entity
    {
    public:
        Enemy(const Enemy&) = delete;
        Enemy &operator=(const Enemy&) = delete;
        Enemy(Configuration::Textures tex_id,World &world);

        virtual int getPoints() const = 0;
        virtual void onDestroy();

    };
}


#endif
