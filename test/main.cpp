#include<AirChart/Core/window.h>
#include<AirChart/Renderer/ogl.h>
#include<AirChart/Renderer/shader.h>
#include<AirChart/Graphs/BarGraph.h>

#include<glm/vec2.hpp>
#include<glm/mat3x3.hpp>
#include<glm/gtx/matrix_transform_2d.hpp>

#include<vector>
#include<iostream>

#include<random>

#include<GLFW/glfw3.h>


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
    Window window(800, 600, "AirChart");
    window.setScrollCallback(scroll_callback);

    GLFWcursor* hand = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
    GLFWcursor* arrow = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);

    window.setCursor(arrow);

    GL::init();

    Shader shader("./shaders/shader.vert", "./shaders/shader.frag");

    GL::setClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    std::vector<float> graph;

    AirChart::Graph::BarGraph bar(&graph, 0.1f, 0.05f, 0.1f);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0f, 15.0f);

    for(int i = 0; i < 40; i++)
    {
        graph.push_back(dis(gen));
    } 

    glm::vec2 dpos(0.0f);

    // delta time
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;


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
            *bar.gap += 0.01f*deltaTime;
            *bar.width += 0.02f*deltaTime;
            *bar.height += 0.02f*deltaTime;
        }
        // check minus key
        if(glfwGetKey(window.getWindow(), GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
        {
            *bar.gap -= 0.01f*deltaTime;
            *bar.width -= 0.02f*deltaTime;
            *bar.height -= 0.02f*deltaTime;
        }
        

        dpos = cpos;

        GL::clear();

        glm::mat3 sca = glm::scale(glm::mat3(1.0f), scale);

        shader.use();
        shader.setVec3("atranslate", translate);
        shader.setMat3("ascale", &sca);

        bar.draw_graph(glm::vec2(-1.0f, -1.0f));
        
        window.update();
    }
    Window::terminate();
    
    return 0;
}