#include "pch.h"
#include "Ball.h"
#include <corecrt_math_defines.h>
#include <random>


Ball::Ball(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos)
{
    m_WallNormal = Vector2(0, 0);
    m_Position = Vector2(-0.07f, -0.214f);
    m_Speed = 0.4f;

    m_Velocity = Vector2(0, 0);

    m_LeftWallPos = leftWallPos;
    m_RightWallPos = rightWallPos;
    m_TopWallPos = topWallPos;
    m_BottomWallPos = bottomWallPos;
    m_Radius = 0.04f;
}

Ball::~Ball()
{

}

Vector2 Ball::GenerateRandomDirection()
{
    std::random_device randomDevice; // random hardware number 
    std::mt19937 seed(randomDevice()); // seed
    std::uniform_int_distribution<> distribution(20, 160); // range
    
    float angle = (float)distribution(seed);// Random.Range(20.0f, 160.0f);
    float radians = angle * (float)M_PI / 180.0f;
    return Vector2((float)cos(radians), (float)sin(radians));
}

void Ball::StartGame()
{
    m_Velocity = GenerateRandomDirection() * m_Speed;
}

void Ball::StopGame()
{
    m_Velocity = Vector2(0, 0);
    m_WallNormal = Vector2(0, 0);
    m_Position = Vector2(-0.07f, -0.214f);
}

void Ball::Update(float deltaTime)
{
    m_Position += m_Velocity * deltaTime;

    if (m_Position.x <= m_LeftWallPos)
    {
        m_WallNormal = Vector2(-1, 0);
        m_Position.x = m_LeftWallPos;
    }
    else if (m_Position.x >= m_RightWallPos)
    {
        m_WallNormal = Vector2(1, 0);
        m_Position.x = m_RightWallPos;
    }

    if (m_Position.y >= m_TopWallPos - m_Radius)
    {
        m_WallNormal = Vector2(0, 1);
        m_Position.y = m_TopWallPos - m_Radius;
    }

    if (m_Position.y <= m_BottomWallPos - m_Radius)
    {
        StopGame();
    }

    if (m_WallNormal != Vector2(0,0))
    {
        float dot = m_Velocity.x * m_WallNormal.x + m_Velocity.y * m_WallNormal.y;
        m_Velocity = -2.0f * dot * m_WallNormal + m_Velocity;
        m_WallNormal = Vector2(0, 0);
    }
}

Vector2 Ball::GetPosition()
{
    return m_Position;
}

void Ball::SetPosition(Vector2 position)
{
    m_Position = position;
}

Vector2 Ball::GetVelocity()
{
    return m_Velocity;
}

void Ball::SetVelocity(Vector2 velocity)
{
    m_Velocity = velocity;
}
float Ball::GetRadius()
{
    return m_Radius;
}