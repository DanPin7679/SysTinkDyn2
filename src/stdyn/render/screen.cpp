#include <SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include "screen.h"



Screen::Screen (int w, int h, int minW, int minH)
{
    m_width = w;
    m_height = h;
    m_minW = minW;
    m_minH = minH;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL could not be initialized: " <<
                SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    SDL_CreateWindowAndRenderer (w*2, h*2, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2,2);

    SDL_SetWindowMinimumSize(window, minW, minH);
    SDL_RenderSetLogicalSize(renderer, minW, minH);

    screen_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_STREAMING,
        minW, minH);

    pixels = (unsigned int*)malloc(minW * minH * 4);
};

void Screen::show()
{
    SDL_RenderClear(renderer);
    SDL_UpdateTexture(screen_texture, NULL, pixels, m_minW * 4);
    SDL_RenderCopy(renderer, screen_texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Screen::clear()
{
    
}

void Screen::input(Canvas canvas)
{
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) exit(0);
    }

    float offset;
    for (int y = 0; y < canvas.height; ++y)
    {
        for (int x = 0; x < canvas.width; ++x)
        {
            offset = 4*x + canvas.pitch*y;
            pixels[x + y * canvas.width] = SDL_MapRGBA(
                     SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888),
                     canvas.buffer[offset],
                     canvas.buffer[offset+1],
                     canvas.buffer[offset+2],
                     canvas.buffer[offset+3]);
        }
    }
}