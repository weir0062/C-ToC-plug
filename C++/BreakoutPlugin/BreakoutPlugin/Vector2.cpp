////////////////////////////////////////////////////////////////////////////////
// Vector2.cpp
// Description: 
////////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "Vector2.h"

// static
const Vector2 Vector2::ZERO(0.0f, 0.0f);

Vector2::Vector2(const Vector2& intVector2)
    : x(intVector2.x)
    , y(intVector2.y)
{

}
