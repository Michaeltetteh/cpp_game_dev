#include <stdio.h>
#include "Pong.h"



int main()
{
    Pong game;
    bool init = game.Initialize();
    
    if(init){
        game.RunLoop();
    }

    game.Shutdown();


    return 0;
}