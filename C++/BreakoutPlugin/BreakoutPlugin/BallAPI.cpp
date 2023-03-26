#include "pch.h"
#include "BallAPI.h"
#include "Ball.h"

PLUGIN_API void* Ball_Create(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos)
{
    return new Ball(leftWallPos, rightWallPos, topWallPos, bottomWallPos);
}

PLUGIN_API void Ball_Destroy(void* ballPtr)
{
    Ball* ball = static_cast<Ball*>(ballPtr);

    if (ball != nullptr)
    {
        delete ball;
        ball = nullptr;
    }
}

PLUGIN_API CVector2 Ball_GetPosition(void* ballPtr)
{
    CVector2 position;
    Ball* ball = static_cast<Ball*>(ballPtr);
    if (ball != nullptr)
    {
        position.x = ball->GetPosition().x;
        position.y = ball->GetPosition().y;
    }

    return position;
}

PLUGIN_API CVector2 Ball_GetVelocity(void* ballPtr)
{
    CVector2 velocity;
    Ball* ball = static_cast<Ball*>(ballPtr);
    if (ball != nullptr)
    {
        velocity.x = ball->GetVelocity().x;
        velocity.y = ball->GetVelocity().y;
    }

    return velocity;

}

PLUGIN_API void Ball_Update(void* ballPtr, float deltaTime)
{
    Ball* ball = static_cast<Ball*>(ballPtr);
    if (ball != nullptr)
    {
        ball->Update(deltaTime);
    }
}

PLUGIN_API void Ball_StartGame(void* ballPtr)
{
    Ball* ball = static_cast<Ball*>(ballPtr);
    if (ball != nullptr)
    {
        ball->StartGame();
    }
}

PLUGIN_API float Ball_GetRadius(void* ballPtr)
{
    float radius = 0;
    Ball* ball = static_cast<Ball*>(ballPtr);
    if (ball != nullptr)
    {
        radius = ball->GetRadius();
    }

    return radius;
}

