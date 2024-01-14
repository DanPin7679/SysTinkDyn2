#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include "renderglwf.h"

void renderGLFW(const char * appname)
{
    std::cout << "In GLFW" << std::endl;
    
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){}

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, appname, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {

        //glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

    //     /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
}