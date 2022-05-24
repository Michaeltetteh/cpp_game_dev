#include "../headers/Game.hpp"
#include "../headers/Configuration.hpp"


int main(int args, char *argv[])
{
    asteroid::Configuration::initialize();

//    Player::setDefaultInputs();
    asteroid::Game game;
    game.run(60);

    return 0;
}