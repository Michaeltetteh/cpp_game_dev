#ifndef GAME_H 
#define GAME_H

#include <SDL.h>
#include <vector>


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