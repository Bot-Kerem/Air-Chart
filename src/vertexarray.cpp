#include<AirChart/Renderer/vertexarray.h>
#include<glad/glad.h>
namespace AirChart
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &vao);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &vao);
    }

    void VertexArray::bind()
    {
        glBindVertexArray(vao);
    }

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::vertexAttrib(unsigned int index, int size, int stride, const void* pointer, unsigned int type)
    {
        bind();
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
        glEnableVertexAttribArray(index);
    }
};