#include "../headers/Pong.h"


SDL_bool Pong::hasCollided(SDL_Rect *A,SDL_Rect *B)
{
    return SDL_HasIntersection(A, B);
}

void Pong::setRects()
{
    topWall =  SDL_Rect{
        0,          
        0,          
        1024,       
        thickness   
    };
    bottomWall =  SDL_Rect{
        0,         
        768 - thickness,         
        1024,       // Width
        thickness   // Height
    };
    rightWall =  SDL_Rect{
        1024 - thickness,
        0,
        thickness,
        1024
    };
    player =  SDL_Rect{
        static_cast<int>(mPlayer.x),
        static_cast<int>(mPlayer.y - playerH/2),
        thickness,
        static_cast<int>(playerH)
    };

    ball =  SDL_Rect{
        static_cast<int>(mBallPos.x - thickness/2),
        static_cast<int>(mBallPos.y - thickness/2),
        thickness,
        thickness
    };
    
}

Pong::Pong() 
    :thickness(15),
     mPlayer(
        10.0f, 
        768.0f/2.0f
     ),
     mBallPos(
        1024.0f/2.0f, 
        768.0f/2.0f
     ),
     mBallVelocity(-200.0f, 235.0f)
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
    if(state[SDL_SCANCODE_W])
        mplayerDirection -= 1;
    if(state[SDL_SCANCODE_S])
        mplayerDirection += 1;
}

void Pong::UpdateGame()
{
    // Wait until 16ms has elapsed since last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
        ;

    // Delta time is the difference in ticks from last frame
    // (converted to seconds)
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    
    // Clamp maximum delta time value
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }

    // Update tick counts (for next frame)
    mTicksCount = SDL_GetTicks();
    
    // Update paddle position based on direction
    if (mplayerDirection != 0)
    {
        mPlayer.y += mplayerDirection * 300.0f * deltaTime;
        // Make sure paddle doesn't move off screen!
        if (mPlayer.y < (playerH/2.0f + thickness))
        {
            mPlayer.y = playerH/2.0f + thickness;
        }
        else if (mPlayer.y > (768.0f - playerH/2.0f - thickness))
        {
            mPlayer.y = 768.0f - playerH/2.0f - thickness;
        }
    }
    
    // Update ball position based on ball velocity
    mBallPos.x += mBallVelocity.x * deltaTime;
    mBallPos.y += mBallVelocity.y * deltaTime;
    
    DetectCollision();
    Log();
}

void Pong::DetectCollision()
{
    // Bounce if needed
    // Did we intersect with the paddle?
    float diff = mPlayer.y - mBallPos.y;
    // Take absolute value of difference
    diff = (diff > 0.0f) ? diff : -diff;
    if (
        // Our y-difference is small enough
        diff <= playerH / 2.0f &&
        hasCollided(&ball, &player) &&
        // The ball is moving to the left
        mBallVelocity.x < 0.0f)
    {
        mBallVelocity.x *= -1.0f;
    }
    // Did the ball go off the screen? (if so, end game)
    else if (mBallPos.x <= 0.0f)
    {
        mIsRunning = false;
    }
    // Did the ball collide with the right wall?
    else if (hasCollided(&ball, &rightWall) &&  mBallVelocity.x > 0.0f)
    {
        mBallVelocity.x *= -1.0f;
    }
    
    // Did the ball collide with the top wall?
    if (hasCollided(&ball, &topWall)&& mBallVelocity.y < 0.0f)
    {
        mBallVelocity.y *= -1;
    }
    // Did the ball collide with the bottom wall?
    else if (hasCollided(&ball, &bottomWall) &&
        mBallVelocity.y > 0.0f)
    {
        mBallVelocity.y *= -1;
    }
}

void Pong::GenerateOutput()
{

    SDL_SetRenderDrawColor(
        mRenderer,
        0,      // R
        0,      // G 
        255,    // B
        255     // A
    );
    
    // Clear back buffer
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    setRects();
    SDL_RenderFillRect(mRenderer, &topWall);
    
    // Draw bottom wall
    SDL_RenderFillRect(mRenderer, &bottomWall);
    
    // Draw right wall
    SDL_RenderFillRect(mRenderer, &rightWall);

    SDL_RenderFillRect(mRenderer, &player);
    
    SDL_RenderFillRect(mRenderer, &ball);
    
    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}
