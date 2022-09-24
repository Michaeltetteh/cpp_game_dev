#ifndef PONG_H 
#define PONG_H

#include "Game.h"

const int thickness = 15;
const float playerH = 100.0f;

struct Vec2
{
    // Vec2(float a,float b):x(a),y(b){}

    float x;
    float y;
};


class Pong: public Game
{
private:
    int thickness;
    Vec2 mPlayer;
    Vec2 mBallPos;
    int mplayerDirection;

public:
    Pong();
    void UpdateGame() override;
    void GenerateOutput() override;
    void ProcessInput() override;
};

Pong::Pong() :thickness(15)
{
    Game game;
    mPlayer.x = (float)width/2.0f;
    mPlayer.y = 768.0f - (playerH/2.0f);
    mBallPos.x = 1024.0f/2.0f;
    mBallPos.y = 768.0f/2.0f;
    // mBallVel.x = -200.0f;
    // mBallVel.y = 235.0f;
}

void Pong::ProcessInput()
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

    mplayerDirection = 0;
    if(state[SDL_SCANCODE_A])
        mplayerDirection -= 1;
    if(state[SDL_SCANCODE_D])
        mplayerDirection += 1;
}

void Pong::UpdateGame()
{
    // Wait until 16ms has elapsed since last frame
    while(!SDL_TICKS_PASSED(SDL_GetTicks(),mTicksCount + 16))
        ;


    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    mTicksCount = SDL_GetTicks();

    // Clamp maximum delta time value
    if(deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }


    // printf("DeltaTime: %f Ticks: %d\n",deltaTime,mTicksCount);
    printf("Player position : (X= %f Y= %f)\n",mPlayer.x,mPlayer.y);
    if(mplayerDirection != 0)
    {
        mPlayer.x += mplayerDirection * 300.0f * deltaTime;
        if(mPlayer.x > (width-100.0f))
            mPlayer.x = width - 100.0f;
        if(mPlayer.x < 10.0f)
            mPlayer.x = 10.0f;

        // //Torus implementation
        // if(mPlayer.x > width)
        //     mPlayer.x = 10.0f;
        // if(mPlayer.x < 0)
        //     mPlayer.x = width;
    }

}

void Pong::GenerateOutput()
{
    SDL_SetRenderDrawColor(mRenderer,0,0,255,255);
    SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    SDL_Rect wall{
        0,
        0, 
        width,
        thickness
    };
    SDL_RenderFillRect(mRenderer,&wall);


    // Draw right wall
    wall.x = width - thickness;
    wall.y = 0;
    wall.w = thickness;
    wall.h = 1024;
    SDL_RenderFillRect(mRenderer, &wall);

    // Draw left wall
    wall.x = 0;
    wall.y = 0;
    wall.w = thickness;
    wall.h = 768;
    SDL_RenderFillRect(mRenderer, &wall);

    // Draw player
    SDL_Rect player{
        static_cast<int>(mPlayer.x),
        static_cast<int>(mPlayer.y - playerH/2),
        100,
        thickness
    };
    SDL_RenderFillRect(mRenderer, &player);
    
    // Draw ball
    SDL_Rect ball{  
        static_cast<int>(mBallPos.x - thickness/2),
        static_cast<int>(mBallPos.y - thickness/2),
        thickness,
        thickness
    };
    SDL_RenderFillRect(mRenderer, &ball);
    SDL_RenderPresent(mRenderer);
}



#endif