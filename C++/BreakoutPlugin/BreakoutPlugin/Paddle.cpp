#include "pch.h"
#include "Paddle.h"
#include "Ball.h"
#include <corecrt_math_defines.h>
#include <random>


Paddle::Paddle(Ball* ball, float PosX,float PosY, float leftwallpos, float rightWallPos)
{

    m_StartPosition = Vector2(PosX, PosY);
    m_Position = Vector2(PosX, PosY);
    m_Speed = 0.4f;

    m_LeftWallPos = leftwallpos;
    m_RightWallPos = rightWallPos;
    m_ball = ball;

}

Paddle::~Paddle()
{

}



void Paddle::Update(float deltaTime)
{

    if (m_ball->GetVelocity() == Vector2::ZERO)
    {
            m_Position.x = m_StartPosition.x;
        return;
    }

    m_Position.y = -0.239;

  /*  if (m_Position.x <= m_LeftWallPos)
    {
        m_Position.x = m_LeftWallPos;
    }
    else if (m_Position.x >= m_RightWallPos)
    {
        m_Position.x = m_RightWallPos;
    }  */
   Vector2 pointOfCollision;

    if (CheckCollision(m_ball, pointOfCollision))
    {
        Vector2 paddleNormal = Vector2(0, -1);
        m_ball->SetPosition( Vector2(pointOfCollision.x, pointOfCollision.y + m_ball->GetRadius()));
        m_ball->SetVelocity(-2.0f * (m_ball->GetVelocity() - paddleNormal).GetLengthSqrd() * paddleNormal + m_ball->GetVelocity());
    }
}


bool Paddle::CheckCollision(Ball* ball,  Vector2 &pointOfCollision)
{
    //Ensure the ball is moving
    if (ball->GetVelocity() != Vector2::ZERO)
    {
        //Calculate the closest point of the line
        Vector2 lineStart =  Vector2(m_Position.x - m_PaddleHalfWidth, m_Position.y);
        Vector2 lineEnd =  Vector2(m_Position.x + m_PaddleHalfWidth, m_Position.y);
        Vector2 closestPoint = CalculateClosestPoint(m_ball->GetPosition(), m_ball->GetRadius(), lineStart, lineEnd);
        pointOfCollision = closestPoint;
        //Calculate the distance between the closest point and the center of the ball
        float distance = (ball->GetPosition()- closestPoint).GetLength();
        float radius = ball->GetRadius();

        //If the distance squared is less than the radii squared, then there's a collision
        return distance < radius;
    }
    pointOfCollision = Vector2::ZERO;
    return false;
}

Vector2 Paddle::CalculateClosestPoint(Vector2 aCircleCenter, float aRadius, Vector2 aLineStart, Vector2 aLineEnd)
{
    //Calculate the circle vector        
    Vector2 circleVector = aCircleCenter - aLineStart;

    //Calculate the line segment vector        
    Vector2 lineVector = aLineEnd - aLineStart;

    //Normalize the line segment vector        
    Vector2 normalizedVector = lineVector/lineVector.GetLength();

    //Calculate the dot product between the circle vector and the normalized line segment vector       
    float magnitude = (normalizedVector, circleVector).GetLengthSqrd();

    //Calculate the projection using the result of the dot product and multiply it by the normalized line segment        
    Vector2 projection = normalizedVector * magnitude;

    //Calculate the closest point on the line segment, by adding the project vector to the line start vector        
    Vector2 closestPoint = aLineStart + projection;
    closestPoint.x = min(max(aLineStart.x, closestPoint.x), aLineEnd.x);
    closestPoint.y = min(max(aLineStart.y, closestPoint.y), aLineEnd.y);
    return closestPoint;
}

void Paddle::Move(bool right, float delta)
{ 
    m_Position.x += m_Speed * delta * (right ? 1:-1 );
}
