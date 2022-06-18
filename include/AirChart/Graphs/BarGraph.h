#ifndef AC_GRAPH_H
#define AC_GRAPH_H

#include<AirChart/Objects/bar.h>
#include<AirChart/Renderer/vertexbuffer.h>
#include<vector>

namespace AirChart 
{
    namespace Graph 
    {
        class BarGraph: private Bar
        {
            public:

                BarGraph(std::vector<float>& graph, float width, float gap, float height);
                BarGraph(float* graph, unsigned int size, float width, float gap, float height);
                
                ~BarGraph();
                
                void draw_graph();
                void draw_graph(glm::vec2 position);

                float* width = new float(0);
                float* gap = new float(0);
                float* height = new float(0);

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