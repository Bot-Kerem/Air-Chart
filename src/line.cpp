#include <AirChart/Objects/line.h>
#include <AirChart/Renderer/shader.h>

#include <glm/mat3x3.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

#include <glad/glad.h>


namespace AirChart
{
    Line::Line(glm::vec2 p1, glm::vec2 p2)
    {
        VertexArray::bind();
        VertexBuffer::bind();

        float vertices[] = {
            p1.x, p1.y,
            p2.x, p2.y,
        };

        VertexBuffer::bufferData(vertices, sizeof(vertices));
        VertexArray::vertexAttrib(0, 2, sizeof(float) * 2, 0);
    }

    Line::~Line(){}

    void Line::draw(glm::vec2 scale)
    {
        VertexArray::bind();

        glm::mat3 scaleMatrix = glm::scale(glm::mat3(1.0f), scale);

        Shader::currentShader->setMat3("scale", &scaleMatrix);

        glDrawArrays(GL_LINES, 0, 2);
    }
    
    void Line::draw()
    {
        VertexArray::bind();
        glDrawArrays(GL_LINES, 0, 2);
    }

    void Line::drawInstanced(int count)
    {
        VertexArray::bind();
        glDrawArraysInstanced(GL_LINES, 0, 2, count);
    }

};