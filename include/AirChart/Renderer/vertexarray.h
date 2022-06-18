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
            static void unbind();
            void vertexAttrib(unsigned int index, int size, int stride, const void* pointer, unsigned int type=0x1406);
            void enableVertexAttribArray(unsigned int index);
            void vertexAttribPointer(unsigned int index, int size, int stride, const void* pointer, unsigned int type=0x1406);
            void vertexAttribDivisor(unsigned int index, unsigned int divisor);

        protected:
            unsigned int vao;
    };
};

#endif