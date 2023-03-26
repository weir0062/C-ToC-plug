#ifndef FLOAT_VECTOR_2_H
#define FLOAT_VECTOR_2_H

#include <math.h>

struct CVector2
{
    float x;
    float y;
};

struct Vector2
{
    // Static constants
    static const Vector2 ZERO;

    Vector2() {}

    Vector2(float inX, float inY)
        : x(inX)
        , y(inY)
    {
    }

    Vector2(const Vector2& Vector2);

    void Set(float inX, float inY);

    float GetLength() const;
    float GetLengthSqrd() const;

    bool operator==(const Vector2& right) const;
    bool operator!=(const Vector2& right) const;

    Vector2& operator=(const Vector2& right);

    float& operator [] (float i);
    const float& operator [] ( float i) const;

    Vector2& operator += (const Vector2& v);
    Vector2& operator -= (const Vector2& v);
    Vector2& operator *= (float i);

    float x;
    float y;
};

//Global operators
Vector2              operator - (const Vector2& a);
Vector2              operator + (const Vector2& a, const Vector2& b);
Vector2              operator - (const Vector2& a, const Vector2& b);
Vector2              operator * (const Vector2& a, float i);
Vector2              operator * (float i, const Vector2& a);
Vector2              operator / (const Vector2& a, float i);

//Inline functions
inline void Vector2::Set(float inX, float inY)
{
    x = inX;
    y = inY;
}

inline bool Vector2::operator==(const Vector2& right) const
{
    return x == right.x && y == right.y;
}

inline bool Vector2::operator!=(const Vector2& right) const
{
    return x != right.x || y != right.y;
}

inline Vector2& Vector2::operator=(const Vector2& other)
{
    x = other.x;
    y = other.y;
    return *this;
}

inline Vector2& Vector2::operator += (const Vector2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

inline Vector2& Vector2::operator -= (const Vector2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

inline Vector2& Vector2::operator *= (float i)
{
    x *= i;
    y *= i;
    return *this;
}

//External helper operators
inline Vector2 operator - (const Vector2& a)
{
    return Vector2(-a.x, -a.y);
}

inline Vector2 operator + (const Vector2& a, const Vector2& b)
{
    Vector2 ret(a);
    ret += b;
    return ret;
}

inline Vector2 operator - (const Vector2& a, const Vector2& b)
{
    Vector2 ret(a);
    ret -= b;
    return ret;
}

inline Vector2  operator * (const Vector2& a, float i)
{
    return Vector2(a.x * i, a.y * i);
}

inline Vector2 operator * (float i, const Vector2& a)
{
    return Vector2(a.x * i, a.y * i);
}

inline Vector2  operator / (const Vector2& a, float i)
{
    return Vector2(a.x / i, a.y / i);
}

inline float Vector2::GetLength() const
{
    return sqrtf(GetLengthSqrd());
}

inline float Vector2::GetLengthSqrd() const
{
    return static_cast<float>(x * x + y * y);
}

#endif //VECTOR_2_H

