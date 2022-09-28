#include "Game.h"
#include "Actor.h"
#include "SDL2/SDL_image.h"

Game::Game() :mWindow(nullptr), mIsRunning(true),width(1024),height(768),mTicksCount(0) {}

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

    if(IMG_Init(IMG_INIT_PNG) == 0){
        SDL_Log("Unable to initialize sdl_image: %s",SDL_GetError());
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
    // Delta time is the difference in ticks from last frame (converted to seconds)
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    mTicksCount = SDL_GetTicks();

    SDL_SetRenderDrawColor(mRenderer, 255,0,0,255); //draw color
    SDL_RenderClear(mRenderer); // clear back buffer to current draw color

    //
    //update actors in mActors
    mUpdatingActors = true;
    for(auto actor : mActors)
        actor->Update(deltaTime);

    mUpdatingActors = false;

    //move all pending actors to mActors and clear mPendingActors
    for(auto actor : mPendingActors)
        mActors.emplace_back(actor);
    mPendingActors.clear();

    //add dead actors to temp vector
    std::vector<Actor *> deadActors;

    for(auto actor : mActors)
    {
        if(actor->GetState() == Actor::EDead)
            deadActors.emplace_back(actor);
    }

    //delete dead actors
    for(auto actor : deadActors)
        delete actor;

}


void Game::GenerateOutput()
{   
    SDL_RenderPresent(mRenderer); //swaps front and back color buffers
}


void Game::AddActor(Actor *actor)
{
    if(mUpdatingActors)
        mPendingActors.emplace_back(actor);
    else
        mActors.emplace_back(actor);
}

void Game::RemoveActor(Actor *actor)
{
    // Is it in pending actors?
    auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if (iter != mPendingActors.end())
    {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mPendingActors.end() - 1);
        mPendingActors.pop_back();
    }

    // Is it in actors?
    iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
    {
        // Swap to end of vector and pop off (avoid erase copies)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}



