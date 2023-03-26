#pragma once
class Ball;
class Paddle
{
public:
    Paddle(Ball* ball, float PosX, float PosY, float leftwallpos, float rightWallPos);
    virtual ~Paddle();

    void Update(float deltaTime);

    Vector2 GetPosition() { return m_Position; }
    void ResetPosition() { m_Position = m_StartPosition; }

    void Move(bool right, float delta);
    bool CheckCollision(Ball* ball,  Vector2& pointOfCollision);
   Vector2 CalculateClosestPoint(Vector2 aCircleCenter, float aRadius, Vector2 aLineStart, Vector2 aLineEnd);

private:
    float m_RightWallPos;
    float m_LeftWallPos;
    float m_Speed;
    Vector2 m_Position;
    Vector2 m_StartPosition;
    Ball* m_ball;
    float m_PaddleHalfWidth = 0.1f;
    
};

