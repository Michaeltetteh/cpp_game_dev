#ifndef PONG_H 
#define PONG_H

#include "Game.h"
#define NEWLINE     "\n"

#define LOG_INFO(message,...) SDL_Log(message NEWLINE, ##__VA_ARGS__);

const int thickness = 15;
const float playerH = 100.0f;

struct Vec2
{
    Vec2(float a,float b):x(a),y(b){}

    float x;
    float y;
};


class Pong: public Game
{
private:
    int thickness;
    Vec2 mPlayer;
    Vec2 mBallPos;
    Vec2 mBallVelocity;
    int mplayerDirection;
    // float deltaTime;
    void Log();
    SDL_Rect _mTopWall;
    SDL_Rect _mRightWall;
    SDL_Rect _mLeftWall;
    SDL_Rect _mPlayer;
    SDL_Rect _mBall;
    SDL_bool hasCollided(SDL_Rect *A,SDL_Rect *B);

public:
    Pong();
    void UpdateGame() override;
    void GenerateOutput() override;
    void ProcessInput() override;
    void DetectCollision();
    void setRects();
};

SDL_bool Pong::hasCollided(SDL_Rect *A,SDL_Rect *B)
{
    return SDL_HasIntersection(A, B);
}

void Pong::setRects()
{
    _mTopWall = SDL_Rect{
        0,
        0, 
        width,
        thickness
    };
    _mRightWall = SDL_Rect{
        width - thickness,
        0,
        thickness,
        1024,
    };
    _mLeftWall = SDL_Rect{
        0,
        0,
        thickness,
        768,
    };
    _mPlayer = SDL_Rect{
        static_cast<int>(mPlayer.x),
        static_cast<int>(mPlayer.y - playerH/2),
        100,
        thickness
    };
    _mBall = SDL_Rect{
        static_cast<int>(mBallPos.x - (thickness/2) + mBallVelocity.x),
        static_cast<int>(mBallPos.y - (thickness/2) + mBallVelocity.y),
        thickness,
        thickness
    };
}

Pong::Pong() 
    :thickness(15),
     mPlayer(
        (float)width / 2.0f, 
        768.0f - (playerH / 2.0f)
     ),
     mBallPos(
        1024.0f / 2.0f, 
        768.0f / 2.0f
     ),
     mBallVelocity(0, -100.0f)
{
    Game game;
}

void Pong::Log()
{
    // LOG_INFO("DeltaTime: %f Ticks: %d\n",deltaTime,mTicksCount);
    LOG_INFO("Player position : X=%f Y=%f\n",mPlayer.x,mPlayer.y);
    LOG_INFO("Ball position : X=%f Y=%f\n",mBallPos.x,mBallPos.y);
    LOG_INFO("Ball velocity : X= %f Y=%f\n\n",mBallVelocity.x,mBallVelocity.y);
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

    Log();

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

    DetectCollision();

    //update ball position
    mBallPos.x += mBallVelocity.x * deltaTime;
    mBallPos.y += mBallVelocity.y * deltaTime;

}

void Pong::DetectCollision()
{
    if(hasCollided(&_mBall, &_mTopWall)){
        printf("COLLISION AT pos (x:%f  y:%f) vel(x:%f,y:%f)",mBallPos.x,mBallPos.y,mBallVelocity.x,mBallVelocity.y);
        mBallVelocity.y *= -1.0f;   
    }
    else if (hasCollided(&_mBall, &_mPlayer)){
        mBallVelocity.y *= -1.0f;
    }
    //ball off screen
    else if (mBallPos.y > (height - thickness)){
        mIsRunning = false;
    }
    else if (hasCollided(&_mBall, &_mRightWall)){
        mBallVelocity.x *= -1.0f;
    }
    else if (hasCollided(&_mBall,&_mLeftWall)){
        mBallVelocity.x *= -1.0f;
    }


}

void Pong::GenerateOutput()
{

    setRects();
    SDL_SetRenderDrawColor(mRenderer,0,0,255,255);
    SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

    SDL_RenderFillRect(mRenderer,&_mTopWall);

    // Draw right wall
    SDL_RenderFillRect(mRenderer, &_mRightWall);

    // Draw left wall
    SDL_RenderFillRect(mRenderer, &_mLeftWall);

    // Draw player
    SDL_RenderFillRect(mRenderer, &_mPlayer);
    
    // Draw ball
    SDL_RenderFillRect(mRenderer, &_mBall);

    SDL_RenderPresent(mRenderer);
}



#endif