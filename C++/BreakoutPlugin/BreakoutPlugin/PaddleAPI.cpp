#include "pch.h"
#include "Paddle.h"
#include "PaddleAPI.h"
#include "BallAPI.h"
#include "Ball.h"

PLUGIN_API void* Paddle_Create(void* BallPtr, float PosX, float PosY, float leftWallPos, float rightWallPos)
{
    Ball* ball = static_cast<Ball*>(BallPtr);
    return new Paddle(ball, PosX, PosY, leftWallPos, rightWallPos);
}

PLUGIN_API void Paddle_Destroy(void* PaddlePtr)
{
    Paddle* paddle = static_cast<Paddle*>(PaddlePtr);

    if (paddle != nullptr)
    {
        delete paddle;
        paddle = nullptr;
    }
}

PLUGIN_API CVector2 Paddle_GetPosition(void* PaddlePtr)
{
    CVector2 position;
    Paddle* paddle = static_cast<Paddle*>(PaddlePtr);
    if (paddle != nullptr)
    {
        position.x = paddle->GetPosition().x;
        position.y = paddle->GetPosition().y;
    }

    return position;
}




PLUGIN_API void Paddle_Move(void* PaddlePtr, bool right, float delta)
{
    Paddle* paddle = static_cast<Paddle*>(PaddlePtr);
    if (paddle != nullptr)
    {
        paddle->Move(right, delta);
    }

}

PLUGIN_API void Paddle_Update(void* PaddlePtr, float deltaTime)
{
    Paddle* paddle = static_cast<Paddle*>(PaddlePtr);
    if (paddle != nullptr)
    {
        paddle->Update(deltaTime);
    }
}



