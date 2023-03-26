using UnityEngine;

public class Ball
{
    public Ball(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos)
    {
        m_BallGlue = new BallGlue(leftWallPos, rightWallPos, topWallPos, bottomWallPos);
    }

    void OnDestroy()
    {
        if (m_BallGlue != null)
        {
            m_BallGlue.Dispose();
        }
    }
   
    public void Update()
    {
        if (m_BallGlue.GetVelocity() == Vector2.zero && Input.GetKeyDown(KeyCode.Space))
            m_BallGlue.StartGame();

       m_BallGlue.Update();

    }
    public Vector2 GetPosition()
    {
        return m_BallGlue.GetPosition();
    }
    public void SetPosition(Vector2 position)
    {
       
    }

    public Vector2 GetVelocity()
    {
        return m_BallGlue.GetVelocity();
    }

    public void SetVelocity(Vector2 velocity)
    {
       
    }

    public float GetRadius()
    {
        return m_BallGlue.GetRadius();
    }

    public BallGlue m_BallGlue;
}
