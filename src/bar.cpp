#include<glad/glad.h>

#include<AirChart/Objects/bar.h>
#include<AirChart/Renderer/shader.h>

#include<glm/gtx/matrix_transform_2d.hpp>
#include<glm/mat3x3.hpp>

namespace AirChart
{
    Bar::Bar()
    {
        VertexArray::bind();
        VertexBuffer::bind();

        // Square vertices
        float vertices[] = {
            0.0f, 0.0f, // Top left
            1.0f, 0.0f, // Top right
            1.0f, 1.0f, // Bottom right

            1.0f, 1.0f, // Bottom right
            0.0f, 1.0f, // Bottom left
            0.0f, 0.0f, // Top left
        };

        VertexBuffer::bufferData(vertices, sizeof(vertices));
        VertexArray::vertexAttrib(0, 2, sizeof(float) * 2, 0);
    };

    Bar::~Bar()
    {

    };

    void Bar::draw(glm::vec2 scale)
    {
        VertexArray::bind();

        glm::mat3 scaleMatrix = glm::scale(glm::mat3(1.0f), scale);

        Shader::currentShader->setMat3("scale", &scaleMatrix);

        glDrawArrays(GL_TRIANGLES, 0, 6);
    };

    void Bar::_draw()
    {
        glDrawArrays(GL_TRIANGLES, 0, 6);
    };

    void Bar::_bind()
    {
        VertexArray::bind();
    };
};