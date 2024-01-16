#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "rendercustom.h"

void renderCustom(const char * appname){

    SDL_Window* window=nullptr;
    SDL_Surface* screen;
    SDL_Surface* image;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow(
            appname,
            0,
            2500,
            1500,
            750,
            SDL_WINDOW_SHOWN);

    screen = SDL_GetWindowSurface(window);
    
    image = IMG_Load("/Users/danypineault/Desktop/dex.JPG");
    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_FreeSurface(image);
    SDL_UpdateWindowSurface(window);

    bool gameIsRunning = true;
    while(gameIsRunning){
        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            if(event.type == SDL_MOUSEMOTION){
                std::cout << "mouse has been moved\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << "a key has been pressed\n";
                if(event.key.keysym.sym == SDLK_0){
                    std::cout << "0 was pressed\n";
                }else{
                    std::cout << "0 was not pressed\n";
                }
            }
        }
    }

    SDL_Delay(1000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

