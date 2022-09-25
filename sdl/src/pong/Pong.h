#ifndef PONG_H 
#define PONG_H

#include "../om/Game.h"

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

public:
    Pong();
    void UpdateGame() override;
    void GenerateOutput() override;
    void ProcessInput() override;
    void DetectCollision();
    void setRects();

private:
    void Log();
    SDL_bool hasCollided(SDL_Rect *A,SDL_Rect *B);

    int thickness;
    int mplayerDirection;
    int mplayer2Direction;

    Vec2 mPlayer;
    Vec2 mPlayer2;
    Vec2 mBallPos;
    Vec2 mBallVelocity;

    SDL_Rect topWall;
    SDL_Rect bottomWall;
    SDL_Rect player_2;
    SDL_Rect player;
    SDL_Rect ball;

};

#endif