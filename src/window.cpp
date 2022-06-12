#include"AirChart/window.h"
#include<GLFW/glfw3.h>

AirChart::Window::Window(int width, int height, const char* title)
{
    this->width = width;
    this->height = height;
    this->posX = 0;
    this->posY = 0;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwGetWindowPos(window, &posX, &posY);
}

AirChart::Window::~Window()
{
    close();
    glfwDestroyWindow(window);
}

void AirChart::Window::close()
{
    glfwSetWindowShouldClose(window, true);
}

void AirChart::Window::update()
{
    glfwSwapBuffers(window);
}

bool AirChart::Window::isClosed()
{
    return glfwWindowShouldClose(window);
}

void AirChart::Window::pollEvents()
{
    glfwPollEvents();
}

void AirChart::Window::init()
{
    glfwInit();
}

void AirChart::Window::terminate()
{
    glfwTerminate();
}