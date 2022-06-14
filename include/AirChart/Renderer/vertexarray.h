#ifndef AC_VERTEXARRAY_H
#define AC_VERTEXARRAY_H

namespace AirChart
{
    class VertexArray
    {
        public:
            VertexArray();
            ~VertexArray();

            void bind();
            void unbind();
            void vertexAttrib(unsigned int index, int size, int stride, const void* pointer, unsigned int type=0x1406);

        protected:
            unsigned int vao;
    };
};

#endif