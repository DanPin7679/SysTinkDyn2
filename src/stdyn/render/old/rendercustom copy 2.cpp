#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "rendercustom.h"
#include "Screen.h"

struct vec3
{
        float x,y,z;
};

void rotate(vec3& point, float x = 1, float y = 1, float z = 1)
{
    float rad = 0;

    rad = x;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos (rad) * point.z;
    
    rad = y;
    point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
    point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;
    
    rad = z;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;
}

void line(Screen& screen, float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float length = std:: sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx);
    for (float i = 0; i < length; i++)
    {
        screen.pixels(
            x1 + std::cos(angle) * i, 
            y1 + std::sin(angle) * i
            );
    };
}

void renderCustom(const char * appname){
    std::cout << "In new Render" << std::endl;
    int screenW = 640;
    int screenH = 480;
    Screen screen(screenW, screenH);

    // for(int i = 0; i < 100; i++)
    // {
    //     screen.pixels(rand()%screenW, rand()%screenH);
    //     line(screen, 10, 10, 100, 100);
    // }    

    std::vector<vec3> points {
        {100,100, 100},
        {200,100, 100},
        {200,200, 100},
        {100,200,100},
        {100,100, 200},
        {200,100, 200},
        {200,200, 200},
        {100,200, 200}
    };

    vec3 c{0,0,0};
    for(auto& p : points)
    {
        c.x += p.x;
        c.y += p.y;
        c.z += p.z;
    }
    c.x /= points.size();
    c.y /= points.size();
    c.z /= points.size();

    bool gameIsRunning = true;
    while(gameIsRunning)
    {
        for(auto& p : points)
        {
            p.x -= c.x;
            p.y -= c.y;
            p.z -= c.z;
            rotate(p, 0.002, 0.001, 0.004);
            p.x += c.x;
            p.y += c.y;
            p.z += c.z;
        }
        for(auto& p : points)
        {
            screen.pixels(p.x, p.y);
        }
        screen.show();
        screen.clear();
        screen.input(gameIsRunning);
    }
    SDL_Quit();
}

