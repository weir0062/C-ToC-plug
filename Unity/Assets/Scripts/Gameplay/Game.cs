using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Game : MonoBehaviour {

    // Use this for initialization
    Renderer Renderer;
    public GameObject LeftWall;
    public GameObject RightWall;
    public GameObject TopWall;
    public GameObject BottomWall;
    void Start ()
    {
        float LeftWallX = LeftWall.transform.position.x;
        float RightWallX = RightWall.transform.position.x;
        float TopWallY = TopWall.transform.position.z;
        float BottomWallY= BottomWall.transform.position.z;
        m_Ball = new Ball(LeftWallX, RightWallX, TopWallY, BottomWallY);
        m_Paddle = new Paddle(ref m_Ball,new Vector2(0,0), LeftWallX, RightWallX);
        Renderer = GameObject.Find("Tv").GetComponent<Renderer>();
        Renderer.material.shader = Shader.Find("Tv");
    }
	
	// Update is called once per frame
	void Update ()
    {
        m_Ball.Update();
        m_Paddle.Update();
        Renderer.material.SetVector("_BallPosition", new Vector3(m_Ball.GetPosition().x, 0, m_Ball.GetPosition().y));
        Renderer.material.SetVector("_PaddlePosition", new Vector3(m_Paddle.GetPosition().x, 0, m_Paddle.GetPosition().y));

    }

    Ball m_Ball;
    Paddle m_Paddle;
}
