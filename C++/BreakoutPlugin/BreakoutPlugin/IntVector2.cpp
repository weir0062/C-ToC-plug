////////////////////////////////////////////////////////////////////////////////
// Vector2.cpp
// Description: 
////////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "IntVector2.h"

// static
const IntVector2 IntVector2::ZERO(0, 0);

IntVector2::IntVector2(const IntVector2& intVector2)
    : x(intVector2.x)
    , y(intVector2.y)
{

}