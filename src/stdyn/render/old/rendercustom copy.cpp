#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "rendercustom.h"

void SetPixel(SDL_Renderer * renderer, int x, int y, uint8_t r, uint8_t g, uint8_t b){
    SDL_SetRenderDrawColor(renderer, 255,0,0, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void renderCustom(const char * appname){
    int screenW = 640;
    int screenH = 480;

    SDL_Window* window=nullptr;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow(
            appname,
            20,
            20,
            screenW,
            screenH,
            SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window,-1,0);

     // Create a rectangle
    SDL_Rect rectangle;
    rectangle.x = 50;
    rectangle.y = 100;
    rectangle.w = 20;
    rectangle.h = 20;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    bool gameIsRunning = true;
    while(gameIsRunning){
        SDL_Event event;
        
        int x,y;
        Uint32 buttons;
        buttons = SDL_GetMouseState(&x,&y);

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            if(event.button.button == SDL_BUTTON_LEFT){
                //std::cout << "left mouse was pressed (" << x << "," << y << ")\n" ;
                SetPixel(renderer, x, y, 255, 0, 0);
            }
            if(event.button.button == SDL_BUTTON_RIGHT){
                //std::cout << "rightmouse was pressed (" << x << "," << y << ")\n" ;
                SetPixel(renderer, x, y, 0, 0, 255);
            }
        }

        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);

        // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // SDL_RenderDrawLine(renderer, 10, 10, 500, 500);
        SDL_RenderPresent( renderer );
        
    }

    SDL_Delay(500);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

