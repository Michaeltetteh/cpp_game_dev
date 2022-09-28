#ifndef GAME_H 
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>

#define NEWLINE     "\n"
#define LOG_INFO(message,...) SDL_Log(message NEWLINE, ##__VA_ARGS__);


class Game
{
public:
    Game();

    bool Initialize(); 

    void RunLoop();

    void Shutdown();

    std::vector<class Actor *> mActors;
    std::vector<class Actor *> mPendingActors;

    void AddActor(class Actor *actor);
    void RemoveActor(class Actor *actor);

private:
    virtual void ProcessInput();
    virtual void UpdateGame();
    virtual void GenerateOutput();

    SDL_Window *mWindow;
    bool mUpdatingActors;

protected:
    bool mIsRunning;
    uint32_t mTicksCount;
    SDL_Renderer *mRenderer;
    int width;
    int height;

};

#endif