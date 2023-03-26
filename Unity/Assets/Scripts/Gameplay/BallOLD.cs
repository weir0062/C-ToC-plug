using UnityEngine;

public class BallOLD
{
    public BallOLD(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos, ref SoundController soundController)
    {
        m_WallNormal = new Vector2(0, 0);
        m_Position = new Vector2(-0.07f, -0.214f);
        m_Speed = 0.4f;

        m_Velocity = Vector2.zero;
       
        m_LeftWallPos = leftWallPos;
        m_RightWallPos = rightWallPos;
        m_TopWallPos = topWallPos;
        m_BottomWallPos = bottomWallPos;
        m_Radius = 0.04f;

        m_SoundController = soundController;

    }
    Vector2 GenerateRandomDirection()
    {
        float angle = Random.Range(20.0f, 160.0f);
        float radians = angle * Mathf.Deg2Rad;
        return new Vector2(Mathf.Cos(radians), Mathf.Sin(radians));
    }

    void StartGame()
    {
        m_Velocity = GenerateRandomDirection() * m_Speed;
    }

    void StopGame()
    {
        m_Velocity = Vector2.zero;
        m_WallNormal = Vector2.zero;
        m_Position = new Vector2(-0.07f, -0.214f);
    }

    public void Update()
    {
        if (m_Velocity == Vector2.zero && Input.GetKeyDown(KeyCode.Space))
            StartGame();

        m_Position += m_Velocity * Time.deltaTime;

        if (m_Position.x <= m_LeftWallPos)
        {
            m_WallNormal = new Vector2(-1, 0);
            m_Position.x = m_LeftWallPos;
            m_SoundController.PlayOneShot();
        }
        else if (m_Position.x >= m_RightWallPos)
        {
            m_WallNormal = new Vector2(1, 0);
            m_Position.x = m_RightWallPos;
            m_SoundController.PlayOneShot();
        }

        if (m_Position.y >= m_TopWallPos - m_Radius)
        {
            m_WallNormal = new Vector2(0, 1);
            m_Position.y = m_TopWallPos - m_Radius;
            m_SoundController.PlayOneShot();
        }

        if (m_Position.y <= m_BottomWallPos - m_Radius)
        {
            StopGame();
        }

        if (m_WallNormal != Vector2.zero)
        {
            m_Velocity = -2.0f * Vector2.Dot(m_Velocity, m_WallNormal) * m_WallNormal + m_Velocity;
            m_WallNormal = new Vector2(0, 0);
        }
    }
    public Vector2 GetPosition()
    {
        return m_Position;
    }
    public void SetPosition(Vector2 position)
    {
        m_Position = position;
    }

    public Vector2 GetVelocity()
    {
        return m_Velocity;
    }

    public void SetVelocity(Vector2 velocity)
    {
        m_Velocity = velocity;
    }

    public float GetRadius()
    {
        return m_Radius;
    }

    float m_RightWallPos;
    float m_LeftWallPos;
    float m_TopWallPos;
    float m_BottomWallPos;
    float m_Speed;
    float m_Radius;
    Vector2 m_Position;
    Vector2 m_Velocity;
    Vector2 m_WallNormal;
    SoundController m_SoundController;
}
