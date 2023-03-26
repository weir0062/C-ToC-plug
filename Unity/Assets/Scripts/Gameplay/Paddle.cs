using UnityEngine;

public class Paddle
{
    public Paddle(ref Ball ball, Vector2 position, float leftWallPos, float rightWallPos)
    {
      m_Ball = ball;
      m_PaddleHalfWidth = 0.1f;

      paddleglue = new PaddleGlue(ref m_Ball, position.x, position.y, leftWallPos+m_PaddleHalfWidth, rightWallPos-m_PaddleHalfWidth);
    }
    void OnDestroy()
    {
        if (paddleglue != null)
        {
            paddleglue.Dispose();
        }
    }
    public void Update()
    {

        paddleglue.Update();
      if(Input.GetKey(KeyCode.A))
      {
            paddleglue.Move(false, Time.deltaTime);
      }

      if(Input.GetKey(KeyCode.D))
      {
            paddleglue.Move(true, Time.deltaTime);
      }
    }    

    public Vector2 GetPosition()
    {
        return paddleglue.GetPosition();
    }


    PaddleGlue paddleglue;
    Ball m_Ball;
    float m_PaddleHalfWidth;
}
