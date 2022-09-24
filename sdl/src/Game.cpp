#include "../headers/Game.h"



Game::Game() :mWindow(nullptr), mIsRunning(true),width(1024),height(768) {}

bool Game::Initialize()
{
    int res = SDL_Init(SDL_INIT_VIDEO);
    if(res != 0){
        SDL_Log("Unable to initialize sdl: %s",SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("Game", 100, 100, width, height, 0);
    if(!mWindow){
        SDL_Log("Unable to create window: %s",SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer) {
        SDL_Log("Unable to create rederer: %s",SDL_GetError());
        return false;
    }

    return true;
}

void Game::Shutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}


void Game::RunLoop()
{
    while(mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
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


void Game::UpdateGame()
{
    SDL_SetRenderDrawColor(mRenderer, 255,0,0,255); //draw color
    SDL_RenderClear(mRenderer); // clear back buffer to current draw color
}


void Game::GenerateOutput()
{   
    SDL_RenderPresent(mRenderer); //swaps front and back color buffers
}

