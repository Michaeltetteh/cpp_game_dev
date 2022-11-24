#include "components/BGSpriteComponent.h"
#include "components/SpriteComponent.h"
#include "actors/Asteroid.h"
#include "SDL_image.h"
#include "actors/Actor.h"
#include "actors/Ship.h"
#include <algorithm>
#include "Game.h"
#include "glad/glad.h"


Game::Game()
    :mWindow(nullptr),
     mUpdatingActors(false),
     mIsRunning(true),
     mTicksCount(0),
     width(1024),
     height(768)
 {}

bool Game::Initialize()
{
    int res = SDL_Init(SDL_INIT_VIDEO);
    if(res != 0){
        SDL_Log("Unable to initialize sdl: %s",SDL_GetError());
        return false;
    }

    // setting opengl attributes
    //Returns 0 on success or a negative error code on failure; call SDL_GetError() for more information.
    //core OpenGL profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);

    //opengl version 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    //Request a color buffer with 8-bits per RGBA channel
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);

    //enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    //Force OpenGL to use hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL,1);

    mWindow = SDL_CreateWindow("Opengl Asteroid", 100, 100, width, height, SDL_WINDOW_OPENGL);
    if(!mWindow){
        SDL_Log("Unable to create window: %s",SDL_GetError());
        return false;
    }

    mContext = SDL_GL_CreateContext(mWindow);

    if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
    {
        SDL_Log("Failed to initialize glad...");
    }

//    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    if(!mRenderer) {
//        SDL_Log("Unable to create rederer: %s",SDL_GetError());
//        return false;
//    }

    if(IMG_Init(IMG_INIT_PNG) == 0){
        SDL_Log("Unable to initialize sdl_image: %s",SDL_GetError());
        return false;
    }

    LoadData();

    mTicksCount = SDL_GetTicks();
    return true;
}

void Game::Shutdown()
{
    UnLoadData();
    IMG_Quit();
    SDL_DestroyRenderer(mRenderer);
    //delete opengl context
    SDL_GL_DeleteContext(mContext);
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


//    mShip->ProcessKeyboard(state);

    mUpdatingActors = true;
    for(auto actor : mActors)
        actor->ProcessInput(state);
    mUpdatingActors = false;
}


void Game::UpdateGame()
{
    // Delta time is the difference in ticks from last frame (converted to seconds)
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    mTicksCount = SDL_GetTicks();

//    SDL_SetRenderDrawColor(mRenderer, 255,0,0,255); //draw color
//    SDL_RenderClear(mRenderer); // clear back buffer to current draw color

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
    //Set the clear color
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

//    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
//    SDL_RenderClear(mRenderer);
//
//    // Draw all sprite components
//    for (auto sprite : mSprites)
//    {
//        sprite->Draw(mRenderer);
//    }
//
//    SDL_RenderPresent(mRenderer);

    SDL_GL_SwapWindow(mWindow);
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


 SDL_Texture *Game::LoadTexture(const char *filename)
 {
     //load surface/image
     SDL_Surface *img = IMG_Load(filename);
     if(!img) {
         SDL_Log("Failed to load texture file %s", filename);
         return nullptr;
     }

     //create texture from surface
     SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, img);
     SDL_FreeSurface(img); //free an RGB surface
     if(!texture) {
         SDL_Log("Failed to convert surface to texture for %s", filename);
         return nullptr;
     }

     return texture;
 }


SDL_Texture *Game::GetTexture(const std::string &filename)
{
    SDL_Texture *tex = nullptr;
    auto iter = mTextures.find(filename);

    if(iter != mTextures.end()) {
        tex = iter->second;
    }
    else {
        tex = LoadTexture(filename.c_str());
        if(tex)
            mTextures.emplace(filename,tex);
    }

    return tex;
}


void Game::AddSprite(SpriteComponent *sprite)
{
    int drawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for( ;iter != mSprites.end(); ++iter)
    {
        if(drawOrder < (*iter)->GetDrawOrder())
            break;
    }
    mSprites.insert(iter,sprite);
}

void Game::RemoveSprite(class SpriteComponent *sprite)
{
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}


void Game::LoadData()
{
//    // Create player's ship
//    mShip = new Ship(this);
//    mShip->SetPosition(Vector2(100.0f, 384.0f));
////    mShip->SetScale(1.5f);
//    mShip->SetRotation(Math::PiOver2);
//
//    // Create actor for the background (this doesn't need a subclass)
//    Actor* temp = new Actor(this);
//    temp->SetPosition(Vector2(512.0f, 384.0f));
//    // Create the "far back" background
//    BGSpriteComponent* bg = new BGSpriteComponent(temp);
//    bg->SetScreenSize(Vector2(1024.0f, 768.0f));
//    std::vector<SDL_Texture*> bgtexs = {
//        GetTexture("Assets/Farback01.png"),
//        GetTexture("Assets/Farback02.png")
//    };
//    bg->SetBGTextures(bgtexs);
//    bg->SetScrollSpeed(-100.0f);
//    // Create the closer background
//    bg = new BGSpriteComponent(temp, 50);
//    bg->SetScreenSize(Vector2(1024.0f, 768.0f));
//    bgtexs = {
//        GetTexture("Assets/Stars.png"),
//        GetTexture("Assets/Stars.png")
//    };
//    bg->SetBGTextures(bgtexs);
//    bg->SetScrollSpeed(-200.0f);
//
//    //spawn asteroids
//    int num = 20;
//    for (int i = 0; i < num; ++i) {
//        new Asteroid(this);
//    }
}

void Game::UnLoadData()
{
    // Delete actors
    // Because ~Actor calls RemoveActor, have to use a different style loop
    while (!mActors.empty())
    {
        delete mActors.back();
    }

    // Destroy textures
    for (auto i : mTextures)
    {
        SDL_DestroyTexture(i.second);
    }
    mTextures.clear();
}


void Game::AddAsteroid(Asteroid* ast)
{
    mAsteroids.emplace_back(ast);
}

void Game::RemoveAsteroid(Asteroid* ast)
{
    auto iter = std::find(mAsteroids.begin(),
        mAsteroids.end(), ast);
    if (iter != mAsteroids.end())
    {
        mAsteroids.erase(iter);
    }
}


void Game::InitSpriteVerts()
{
    float vertices[] = {
            -0.5f, 0.5f, 0.0f, // vertex 0
            0.5f, 0.5f, 0.0f, // vertex 1
            0.5f, -0.5f, 0.0f, // vertex 2
            -0.5f, -0.5f, 0.0f // vertex 3
    };
    unsigned short indices[] = {
            0, 1, 2,
            2, 3, 0
    };
    mSpriteVerts = new VertexArrayBuffer(vertices, 4, reinterpret_cast<const unsigned int *>(indices), 6);
}