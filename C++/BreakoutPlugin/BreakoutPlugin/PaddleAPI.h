#pragma once

#ifdef BREAKOUTPLUGIN_EXPORTS 
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif



extern "C"
{
    PLUGIN_API void* Paddle_Create(void* BallPtr,  float PosX, float PosY,  float leftWallPos, float rightWallPos);
    PLUGIN_API void Paddle_Destroy(void* PaddlePtr);
    PLUGIN_API CVector2 Paddle_GetPosition(void* PaddlePtr);
    PLUGIN_API void Paddle_Move(void* PaddlePtr,bool right, float delta);
    PLUGIN_API void Paddle_Update(void* PaddlePtr, float deltaTime);
}

