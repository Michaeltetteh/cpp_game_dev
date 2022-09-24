#include <stdio.h>
#include "../headers/Game.h"
#include "../headers/Rect.h"



int main(int argc, char *argv[])
{
    DrawRect game;
    bool init = game.Initialize();
    
    if(init){
        game.RunLoop();
    }

    game.Shutdown();


    return 0;
}