using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.UIElements;

public class PaddleGlue : IDisposable
{
    public PaddleGlue(ref Ball ball, float PosX, float PosY, float leftWallPos, float rightWallPos)
    {
        Impl = Paddle_Create( ball.m_BallGlue.Impl,new Vector2(PosX, PosY), leftWallPos, rightWallPos);
    }

    public Vector2 GetPosition()
    {
        Vector2 pos = Paddle_GetPosition(Impl);
        Vector2 position = new Vector2(pos.x, pos.y);
        return position;
    }


    public void Update()
    {
        Paddle_Update(Impl, Time.deltaTime);
    }

    public void StartGame()
    {
        Paddle_StartGame(Impl);
    }

    public void Move(bool right, float delta)
    {
        Paddle_Move(Impl, right, delta);
    }

    public void Dispose()
    {
        CleanUp();

        GC.SuppressFinalize(this);
    }


    ~PaddleGlue()
    {
        CleanUp();
    }

    private void CleanUp()
    {
        if (Impl != IntPtr.Zero)
        {
            Paddle_Destroy(Impl);
            Impl = IntPtr.Zero;
        }
    }

    public IntPtr Impl { get; private set; }

    [DllImport("BreakoutPlugin")]
    static extern IntPtr Paddle_Create(IntPtr ptr, Vector2 position, float leftWallPos, float rightWallPos);

    [DllImport("BreakoutPlugin")]
    static extern void Paddle_Destroy(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern Vector2 Paddle_GetPosition(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern Vector2 Paddle_Update(IntPtr ptr, float deltaTime);
    [DllImport("BreakoutPlugin")]
    static extern void Paddle_StartGame(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern void Paddle_Move(IntPtr PaddlePtr, bool right, float delta);
}
