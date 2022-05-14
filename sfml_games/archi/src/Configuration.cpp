#include "../headers/Configuration.hpp"
using namespace book;

book::ResourceManager<sf::Texture,int> Configuration::textures;
ActionMap<int> Configuration::player_inputs;

void Configuration::initialize()
{
    initTextures();
    initPlayerInputs();
}

void Configuration::initTextures()
{
    textures.load(Texture::Player,"../media/player/Ship.png");
}

void Configuration::initPlayerInputs()
{
    player_inputs.map(PlayerInputs::UP,Action(sf::Keyboard::Up));
    player_inputs.map(PlayerInputs::RIGHT,Action(sf::Keyboard::Right));
    player_inputs.map(PlayerInputs::LEFT,Action(sf::Keyboard::Left));
}