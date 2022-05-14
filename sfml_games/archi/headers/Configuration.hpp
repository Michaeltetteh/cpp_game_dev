
#ifndef ARCHI_CONFIGURATION_HPP
#define ARCHI_CONFIGURATION_HPP

#include "ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include "ActionMap.hpp"
namespace book
{
    class Configuration
    {
    public:
        Configuration() = delete;
        Configuration(const Configuration&) = delete;
        Configuration &operator=(const Configuration&) = delete;

        enum Texture : int {Player};
        static book::ResourceManager<sf::Texture,int> textures;

        enum PlayerInputs: int{UP,LEFT,RIGHT};
        static ActionMap<int> player_inputs;

        static void initialize();

    private:
        static void initTextures();
        static void initPlayerInputs();
    };
}


#endif //ARCHI_CONFIGURATION_HPP
