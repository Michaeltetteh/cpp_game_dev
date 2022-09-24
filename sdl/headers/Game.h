#ifndef GAME_H 
#define GAME_H

#include <SDL.h>

class Game
{
public:
    Game();

    bool Initialize(); 

    void RunLoop();

    void Shutdown();

private:
    void ProcessInput();
    virtual void UpdateGame();
    virtual void GenerateOutput();

    bool mIsRunning;
    
protected:
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    int width;
    int height;

};

#endif