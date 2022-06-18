#ifndef AC_LINE_H
#define AC_LINE_H

#include <AirChart/Renderer/vertexbuffer.h>
#include <AirChart/Renderer/vertexarray.h>

#include <glm/vec2.hpp>

#include <vector>

namespace AirChart
{
    class Line: private VertexArray, VertexBuffer
    {
        public:
            Line(glm::vec2 p1, glm::vec2 p2);
            ~Line();

            void draw(glm::vec2 scale);
            void draw();

        protected:
            void _draw(glm::vec2 scale);
            void _draw();
            void _bind();
            Line(float* array, int size);
            unsigned int size = 2;
    };
};

#endif