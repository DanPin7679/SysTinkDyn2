#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <vector>
#include "vec.h" 


class Color
{  
public:
    Vec3 color = Vec3(0,0,0);
    Color();
    Color(float rin, float gin, float bin);
};

class Point
{
    Vec2 point = Vec2(0,0);
public:
    Point();
    Point(float xin, float yin);
};

class Canvas
{
public:
    int width = 640;
    int height = 480;
    int pitch;
    std::vector<float> buffer;
    Canvas(int w, int h);
    void PutPixel(float x, float y, Color c);
};



// class Line
// {
//     Point p1;
//     Point p2;

// public:
//     Line(Point p1, Point p2);
//     void Draw(Canvas canvas);
// };


#endif