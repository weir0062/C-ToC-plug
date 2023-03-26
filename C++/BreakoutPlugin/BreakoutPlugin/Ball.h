#pragma once
class Ball
{
public:
    Ball(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos);
    virtual ~Ball();

    Vector2 GenerateRandomDirection();
    void StartGame();
    void StopGame();
    void Update(float deltaTime);

    Vector2 GetPosition();
    void SetPosition(Vector2 position);
    Vector2 GetVelocity();
    void SetVelocity(Vector2 velocity);
    float GetRadius();

private:
    float m_RightWallPos;
    float m_LeftWallPos;
    float m_TopWallPos;
    float m_BottomWallPos;
    float m_Speed;
    float m_Radius;
    Vector2 m_Position;
    Vector2 m_Velocity;
    Vector2 m_WallNormal;
};

