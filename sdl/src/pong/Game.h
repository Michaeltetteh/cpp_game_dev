#ifndef SDLGAME_GAME_H
#define SDLGAME_GAME_H


#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>


#define NEWLINE     "\n"
#define LOG_INFO(message,...) SDL_Log(message NEWLINE, __VA_ARGS__);


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


#endif //SDLGAME_GAME_H
