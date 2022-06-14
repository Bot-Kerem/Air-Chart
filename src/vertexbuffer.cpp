#include <AirChart/Renderer/vertexbuffer.h>
#include <glad/glad.h>

namespace AirChart
{
    VertexBuffer::VertexBuffer()
    {
        glGenBuffers(1, &vbo);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &vbo);
    }

    void VertexBuffer::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }

    void VertexBuffer::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::bufferData(void* data, signed long int size)
    {
        bind();
        glBufferData(GL_ARRAY_BUFFER, size ,data, GL_STATIC_DRAW);
    }

    template<typename T>
    void VertexBuffer::bufferData(std::vector<T> data, unsigned int vertex_count)
    {
        glBufferData(GL_ARRAY_BUFFER, data.size()*sizeof(T) ,data.data(), GL_STATIC_DRAW);
    }
};