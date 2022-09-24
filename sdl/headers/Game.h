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
    virtual void ProcessInput();
    virtual void UpdateGame();
    virtual void GenerateOutput();

    SDL_Window *mWindow;

protected:
    bool mIsRunning;
    uint32_t mTicksCount;
    SDL_Renderer *mRenderer;
    int width;
    int height;

};

#endif