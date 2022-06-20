#ifndef AC_GRAPH_H
#define AC_GRAPH_H

#include<AirChart/Objects/bar.h>
#include<AirChart/Renderer/vertexbuffer.h>
#include<vector>

namespace AirChart 
{
    namespace Graph 
    {
        class BarGraph: protected Bar
        {
            public:

                BarGraph(std::vector<float>& graph, float width, float spacing, float height);
                BarGraph(float* graph, unsigned int size, float width, float spacing, float height);
                
                ~BarGraph();
                
                void draw();

                float* width   = new float(0);
                float* spacing = new float(0);
                float* height  = new float(0);

                //void update(std::vector<float>* graph);
                //void update(float* graph, unsigned int size);

            private:
                AirChart::VertexBuffer instance;
                AirChart::VertexBuffer order_buffer;
                unsigned int size;
        };
    };
};

#endif