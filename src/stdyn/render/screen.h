#include <SDL.h>
#include <glad/glad.h>
#include <shapes.h>
#ifndef __SCREEN_H__
#define __SCREEN_H__

class Screen
{
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture * screen_texture;
    int m_width;
    int m_height;
    int m_minW;
    int m_minH;
    unsigned int * pixels;
public:
    Screen (int w, int h, int minW, int minH);
    void show();
    void clear();
    void input(Canvas canvas);
};

#endif