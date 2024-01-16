#include <SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include "shader.hpp"

int gScreenW = 1280;
int gScreenH = 720;
SDL_Window* gG = nullptr;
SDL_GLContext gCtx = nullptr;
bool gQuit = false;

GLuint gGraphPipShader = 0;
GLuint gVertexArrayObject = 0;
GLuint gVertexBufferObject = 0;

void InitProg(const char * appname)
{
     if(SDL_Init(SDL_INIT_VIDEO) < 0)
     {
        std::cout << "SDL2 could not init" << std::endl;
        exit(1);
    };

    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    gG = SDL_CreateWindow(
        appname,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        gScreenW,
        gScreenH,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if(gG==nullptr){
        std::cout << "Win could not init" << std::endl;
        exit(1);
    };

    gCtx = SDL_GL_CreateContext (gG);
    if(gCtx == nullptr)
    {
        std::cout<< "OpenGL context not available\n";
        exit(1);
    };

    if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        std::cout<< "Glad was not init\n";
        exit(1);
    }
}

void VertexSpecification()
{
    const std::vector<GLfloat> vertexPositions 
    {
        -0.9f, -0.9f, 0.0f,
        0.9f, 1.0f, 1.0f,
        1.0f,  0.9f, 0.0f,
    };

    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);

    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    // Give our vertices to OpenGL.
    glBufferData(
        GL_ARRAY_BUFFER, 
        vertexPositions.size() * sizeof(GL_FLOAT), 
        vertexPositions.data(), 
        GL_STATIC_DRAW
    );

    glEnableVertexAttribArray(0);
   
    glVertexAttribPointer(
        0,  3, GL_FLOAT, GL_FALSE, 0, (void*)0         
    );

     glBindVertexArray(0);
     glDisableVertexAttribArray(0);
}

void CreateGraphPipe()
{
    gGraphPipShader  = LoadShaders( 
        "/Users/danypineault/Documents/Code/test/sdl2/src/SimpleVertexShader.vertexshader",
        "/Users/danypineault/Documents/Code/test/sdl2/src/SimpleFragmentShader.fragmentshader"
    );
};

void Input()
{
    SDL_Event e;

    while(SDL_PollEvent (&e) !=0)
    {
         if(e.type == SDL_QUIT)
         {
            std::cout<< "Goodbye!" <<std::endl;
            gQuit= true;
        }
    }   
}

void PreDraw(){
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, gScreenW, gScreenH);
    glClearColor ( 0.05f, 0.05f, 0.15f, 1.f );
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT) ;
    glUseProgram(gGraphPipShader);
}

void Draw()
{
    glBindVertexArray(gVertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glUseProgram(0);
}

void MainLoop()
{
    while(!gQuit)
    {
        Input();
        PreDraw();
        Draw();
        SDL_GL_SwapWindow(gG);
    }
}

void CleanUp()
{
    SDL_DestroyWindow(gG);
    SDL_Quit();
}

void renderSDL2(const char * appname) 
{
    InitProg(appname);

    VertexSpecification();

    CreateGraphPipe();

    MainLoop();

    CleanUp();
}