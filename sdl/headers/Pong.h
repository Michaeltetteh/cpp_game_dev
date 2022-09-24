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

#endif