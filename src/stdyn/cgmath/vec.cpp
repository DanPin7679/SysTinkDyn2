#include "vec.h"
#include <math.h>

Vec2::Vec2(){}

Vec2::Vec2 (float xin, float yin)
    :x(xin), y(yin){}

bool Vec2::operator == (const Vec2 & rhs) const
{
    return (x==rhs.x && y==rhs.y);
}

bool Vec2::operator != (const Vec2 & rhs) const
{
    return (x!=rhs.x || y!=rhs.y);
}


Vec2 Vec2::operator + (const Vec2 & rhs) const
{
    return Vec2(rhs.x +x, rhs.y + y);
}

Vec2 Vec2::operator - (const Vec2 & rhs) const
{
    return Vec2(rhs.x - x, rhs.y - y);
}

Vec2 Vec2::operator / (const float val) const
{
     return Vec2(x / val, y / val);
}

Vec2 Vec2::operator * (const float val) const
{
     return Vec2(x * val, y * val);
}


void Vec2::operator += (const Vec2 & rhs)
{
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator -= (const Vec2 & rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

void Vec2::operator *= (const float val)
{
    x *= val;
    y *= val;
}

void Vec2::operator /= (const float val)
{
    x /= val;
    y /= val;
}

float Vec2::dist(const Vec2 & rhs) const
{
    return 0.0;
}

Vec3::Vec3(){}

Vec3::Vec3 (float xin, float yin, float zin)
    :x(xin), y(yin), z(zin){}
