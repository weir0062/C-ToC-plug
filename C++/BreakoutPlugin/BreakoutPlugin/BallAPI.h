#pragma once

#ifdef BREAKOUTPLUGIN_EXPORTS 
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif

extern "C"
{
    PLUGIN_API void* Ball_Create(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos);
    PLUGIN_API void Ball_Destroy(void* ballPtr);
    PLUGIN_API CVector2 Ball_GetPosition(void* ballPtr);
    PLUGIN_API CVector2 Ball_GetVelocity(void* ballPtr);
    PLUGIN_API void Ball_Update(void* ballPtr, float deltaTime);
    PLUGIN_API void Ball_StartGame(void* ballPtr);
    PLUGIN_API float Ball_GetRadius(void* ballPtr);
}

