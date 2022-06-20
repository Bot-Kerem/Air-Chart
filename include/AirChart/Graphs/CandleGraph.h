#ifndef AC_CANDLEGRAPH_H
#define AC_CANDLEGRAPH_H

#include <AirChart/Objects/bar.h>
#include <AirChart/Objects/line.h>

#include <vector>
#include<glm/vec2.hpp>

namespace AirChart
{
    namespace Graph
    {
        class CandleGraph: protected Bar
        {
            public:
                CandleGraph(std::vector<float>& open, std::vector<float>& close, std::vector<float>& low, std::vector<float>& high, float width, float spacing, float height);
                CandleGraph(float* open, float *close, float *low, float *high, unsigned int size, float width, float spacing, float height);

                void draw();
                
                ~CandleGraph();

                float *width   = new float(0);
                float *height  = new float(0);
                float *spacing = new float(0);

            protected:
                Line line = Line(glm::vec2(0.0f), glm::vec2(0.0f, 1.0f));

                AirChart::VertexBuffer open;
                AirChart::VertexBuffer close;
                AirChart::VertexBuffer high;
                AirChart::VertexBuffer low;

                AirChart::VertexBuffer order;
                
                unsigned int size = 0;
                
                

        };
    };
};

#endif