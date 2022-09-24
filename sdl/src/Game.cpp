#include "../headers/Game.h"



Game::Game() :mWindow(nullptr), mIsRunning(true){}

bool Game::Initialize()
{
    int res = SDL_Init(SDL_INIT_VIDEO);
    if(res != 0){
        SDL_Log("Unable to initialize sdl: %s",SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Game", 100, 100, 1024, 768, 0);
    if(!mWindow){
        SDL_Log("Unable to create window: %s",SDL_GetError());
        return false;
    }
    return true;
}

void Game::Shutdown()
{
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}


void Game::RunLoop()
{
    while(mIsRunning) {
        ProcessInput();
        // UpdateGame();
        // GenerateOutput();
    }
}


void Game::ProcessInput()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type)
        {
            case SDL_QUIT:
                mIsRunning = false;
                break;

        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }

}



