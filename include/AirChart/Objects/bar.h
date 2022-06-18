#ifndef AC_BAR_H
#define AC_BAR_H

#include <AirChart/Renderer/vertexbuffer.h>
#include <AirChart/Renderer/vertexarray.h>

#include<glm/vec2.hpp>

namespace AirChart
{
    class Bar: protected VertexArray, VertexBuffer
    {
        public:
            Bar();
            ~Bar();

            void draw(glm::vec2 scale);
        protected:
            void drawInstanced(int count);

    };
};

#endif