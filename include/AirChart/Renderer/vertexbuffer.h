#ifndef AC_VERTEXBUFFER_H
#define AC_VERTEXBUFFER_H

#include<vector>

namespace AirChart
{
    class VertexBuffer
    {
        public:

            VertexBuffer();
            ~VertexBuffer();

            void bind();
            void unbind();

            void bufferData(void* data, signed long int size);

            template<typename T> void bufferData(std::vector<T> data, unsigned int vertex_count);

        protected:
            unsigned int vbo;
    };
};

#endif
