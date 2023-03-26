using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.UIElements;

public class BallGlue : IDisposable
{
    public BallGlue(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos)
    {
        Impl = Ball_Create(leftWallPos, rightWallPos, topWallPos, bottomWallPos);
    }

    public Vector2 GetPosition()
    {
        Vector2 pos = Ball_GetPosition(Impl);
        Vector2 position = new Vector2(pos.x,pos.y);
        return position;
    }

    public Vector2 GetVelocity()
    {
        Vector2 vel = Ball_GetVelocity(Impl);
        Vector2 velocity = new Vector2(vel.x, vel.y);
        return velocity;
    }

    public void Update()
    {
        Ball_Update(Impl, Time.deltaTime);
    }

    public void StartGame()
    {
        Ball_StartGame(Impl);
    }

    public float GetRadius()
    {
        return Ball_GetRadius(Impl);
    }
 

    public void Dispose()
    {
        CleanUp();

        GC.SuppressFinalize(this);
    }

  
    ~BallGlue()
    {
        CleanUp();
    }

    private void CleanUp()
    {
        if (Impl != IntPtr.Zero)
        {
            Ball_Destroy(Impl);
            Impl = IntPtr.Zero;
        }
    }

    public IntPtr Impl { get; private set; }

    [DllImport("BreakoutPlugin")]
    static extern IntPtr Ball_Create(float leftWallPos, float rightWallPos, float topWallPos, float bottomWallPos);
    
    [DllImport("BreakoutPlugin")]
    static extern void Ball_Destroy(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern Vector2 Ball_GetPosition(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern Vector2 Ball_GetVelocity(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern Vector2 Ball_Update(IntPtr ptr, float deltaTime);
    [DllImport("BreakoutPlugin")]
    static extern void Ball_StartGame(IntPtr ptr);

    [DllImport("BreakoutPlugin")]
    static extern float Ball_GetRadius(IntPtr ptr);
}
