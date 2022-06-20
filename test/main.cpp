#include<AirChart/Core/window.h>
#include<AirChart/Renderer/ogl.h>
#include<AirChart/Renderer/shader.h>
#include<AirChart/Graphs/BarGraph.h>
#include<AirChart/Graphs/CandleGraph.h>

#include<glm/vec2.hpp>
#include<glm/mat3x3.hpp>
#include<glm/gtx/matrix_transform_2d.hpp>

#include<vector>
#include<iostream>

#include<random>

#include<GLFW/glfw3.h>

#include<cmath>

using namespace AirChart;

glm::vec2 scale(1.0f);
glm::vec3 translate(0.0f);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (yoffset > 0)
    {
        translate.x += 0.1f;
    }
    else
    {
        translate.x -= 0.1f;
    }
}

int main() {

    Window::init();
    Window window(800, 600, "Air Chart");
    window.setScrollCallback(scroll_callback);

    GLFWcursor* hand = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
    GLFWcursor* arrow = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);

    window.setCursor(arrow);

    GL::init();

    Shader shader("./shaders/candlebar.vert", "./shaders/shader.frag");

    GL::setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    std::vector<float> open;
    std::vector<float> close;
    std::vector<float> low;
    std::vector<float> high;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(5.0f, 10.0f);
    std::uniform_real_distribution<> h(7.2f, 10.0f);
    std::uniform_real_distribution<> l(5.0f, 8.0f);

    for(int i = 0; i < 40; i++)
    {
        open.push_back(dis(gen));
        close.push_back(dis(gen));
        low.push_back(l(gen));
        high.push_back(h(gen));
    }

    glm::vec2 dpos(0.0f);

    // delta time
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;


    AirChart::Graph::CandleGraph candle(open, close, low, high, 0.05f, 0.03f, 0.1f);

    while(!window.isClosed()) {
        window.pollEvents();

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        double x, y;
        glfwGetCursorPos(window.getWindow(), &x, &y);
        glm::vec2 cpos(x, y);

        glfwSetCursor(window.getWindow(), arrow);
        if(glfwGetMouseButton(window.getWindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        {
            if(!(cpos == dpos))
            {
                glm::vec2 a = (cpos - dpos) / glm::vec2(400.0f, 300.0f);

                translate.x += a.x;
                translate.y -= a.y;
            }
            glfwSetCursor(window.getWindow(), hand);
        }

        // check plus key
        if(glfwGetKey(window.getWindow(), GLFW_KEY_KP_ADD) == GLFW_PRESS)
        {
            *candle.spacing += 0.01f*deltaTime;
            *candle.width += 0.02f*deltaTime;
            *candle.height += 0.02f*deltaTime;
        }
        // check minus key
        if(glfwGetKey(window.getWindow(), GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
        {
            *candle.spacing -= 0.01f*deltaTime;
            *candle.width -= 0.02f*deltaTime;
            *candle.height -= 0.02f*deltaTime;
        }

        dpos = cpos;

        GL::clear();

        glm::mat3 sca = glm::scale(glm::mat3(1.0f), scale);

        shader.use();
        shader.setVec3("atranslate", translate);
        shader.setMat3("ascale", &sca);

        candle.draw();
        
        window.update();
    }
    Window::terminate();
    
    return 0;
}