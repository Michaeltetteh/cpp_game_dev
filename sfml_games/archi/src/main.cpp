//
// Created by mike on 13/05/2022.
//
#include "../headers/Game.hpp"

int main(int args, char *argv[])
{
//    Game game;
////    game.run_fts(1,60);
////    game.run_vts(1);
//    game.run_mts(0,60);

    Player::setDefaultInputs();
    Game game;
    game.run_mts(0,60);

    return 0;
}