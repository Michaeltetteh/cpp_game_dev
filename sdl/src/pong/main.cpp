#include <stdio.h>
#include "Pong.h"



int main(int argc, char *argv[])
{
    Pong game;
    bool init = game.Initialize();
    
    if(init){
        game.RunLoop();
    }

    game.Shutdown();


    return 0;
}