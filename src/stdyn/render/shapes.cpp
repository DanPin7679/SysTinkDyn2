#include <vector>
#include "shapes.h" 
#include "vec.h" 

Color::Color(){};
Color::Color(float rin, float gin, float bin)
    :color(Vec3(rin, gin, bin)){}

Point::Point(){};
Point::Point(float xin, float yin)
    :point(Vec2(xin, yin)){}

Canvas::Canvas(int w, int h)
{
    width = w;
    height = h;
    pitch = width * 4;
    std::vector<float> _buffer (pitch * height, 0);
    buffer = _buffer;
}

void Canvas::PutPixel(float x, float y, Color c)
{
    float offset = 4*x + pitch*y;
    buffer[offset++] = c.color.x;
    buffer[offset++]  = c.color.y;
    buffer[offset++] = c.color.z;
    buffer[offset++] = 255;
}

