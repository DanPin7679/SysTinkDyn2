#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "render.h"
#include "screen.h"
#include "shapes.h"

void renderCustom(const char * appname){
    std::cout << "In new Render" << std::endl;
    int screenW = 640;
    int screenH = 480;
    int minW = 2*640;
    int minH = 2*480;

    Screen screen(screenW, screenH, minW, minH);
    Canvas canvas(minW, minH);
    for(int x=0; x < minW; x++)
    {
        for(int y=0; y < minH; y++)
        {
            if(x==y)
            {
                canvas.PutPixel(x, y, Color(255,255,255));
            } else
            {
                canvas.PutPixel(x, y, Color(10,10,20));
            };

        }
    }
    while(1)
    {
        screen.input(canvas);
        screen.show(); 
    }
}

