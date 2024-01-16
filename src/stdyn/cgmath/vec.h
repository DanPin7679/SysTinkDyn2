#ifndef __VEC2_H__
#define __VEC2_H__

struct Vec2
{
    float x = 0;
    float y = 0;

    Vec2();
    Vec2 (float xin, float yin);

    bool operator == (const Vec2 & rhs) const; 
    bool operator != (const Vec2 & rhs) const;

    Vec2 operator + (const Vec2 & rhs) const;
    Vec2 operator - (const Vec2 & rhs) const;
    Vec2 operator / (const float val) const;
    Vec2 operator * (const float val) const;

    void operator += (const Vec2 & rhs);
    void operator -= (const Vec2 & rhs);
    void operator *= (const float val);
    void operator /= (const float val);

    float dist(const Vec2 & rhs) const;
};

struct Vec3
{
public:
    float x = 0;
    float y = 0;
    float z = 0;

    Vec3();
    Vec3 (float xin, float yin, float zin);

};

#endif