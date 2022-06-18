#ifndef AC_CANDLEGRAPH_H
#define AC_CANDLEGRAPH_H

#include <AirChart/Objects/bar.h>
#include <AirChart/Objects/line.h>

#include <vector>

namespace AirChart
{
    namespace Graph
    {
        class CandleGraph: private Bar, Line
        {
            public:
                CandleGraph(std::vector<float>* graph, float width, float spacing, float height);
                CandleGraph(float* graph, unsigned int size, float width, float spacing, float height);
                
                ~CandleGraph();

                float *width;
                float *height;
                float *spacing;

            protected:
                std::vector<float>* graph = nullptr;
                float* graph_data = nullptr;
                unsigned int graph_size = 0;
                

        };
    };
};

#endif