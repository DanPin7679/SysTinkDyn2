#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <string>
#include "renderglwf.h"
#include <vector>
#include "shader.hpp"

void renderGLFW(const char * appname)
{
    std::cout << "In GLFW" << std::endl;
    int screenW = 1280;
    int screenH =  720;
    
    glfwInit();

    const std::vector<GLfloat> vertexPositions 
    {
        -0.9f, -0.9f, 0.0f,
        0.9f, 1.0f, 1.0f,
        1.0f,  0.9f, 0.0f,
    };

    GLFWwindow* window = glfwCreateWindow(screenW, screenH, appname, NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW failed to create Window" << std::endl;
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0,0,screenW, screenH);
    glClearColor(0.0f, 0.05f, 0.15f, 1.0f);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    
}