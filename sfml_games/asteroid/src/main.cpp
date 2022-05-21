#include "../headers/Game.hpp"
#include "../headers/Configuration.hpp"


int main(int args, char *argv[])
{
    book::Configuration::initialize();

//    Player::setDefaultInputs();
    Game game;
    game.run_mts(0,60);

    return 0;
}