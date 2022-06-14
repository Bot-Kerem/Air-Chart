#include<glad/glad.h>

#include<AirChart/Core/window.h>
#include<AirChart/Renderer/ogl.h>
#include<AirChart/Renderer/shader.h>
#include<AirChart/Renderer/vertexarray.h>
#include<AirChart/Renderer/vertexbuffer.h>
using namespace AirChart;

int main() {

    Window::init();
    Window window(800, 600, "AirChart");

    GL::init();

    Shader shader("./../shaders/shader.vert", "./../shaders/shader.frag");

    float vertices[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f,
    };


    VertexArray va;
    va.bind();
    VertexBuffer vb;
    vb.bind();
    vb.bufferData(vertices, sizeof(vertices));
    va.vertexAttrib(0, 2, sizeof(float) * 2, 0);

    GL::setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    while(!window.isClosed()) {
        window.pollEvents();
        GL::clear();

        shader.use();
        va.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.update();
    }
    Window::terminate();
    
    return 0;
}