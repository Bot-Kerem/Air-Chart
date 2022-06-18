#include <AirChart/Graphs/CandleGraph.h>

#include <glm/vec2.hpp>

namespace AirChart
{
    namespace Graph
    {
        CandleGraph::CandleGraph(std::vector<float>* graph, float width, float spacing, float height):Line(glm::vec2(0.0f), glm::vec2(0.0f, 1.0f))
        {
            this->graph = graph;
            *(this->width) = width;
            *(this->spacing) = spacing;
            *(this->height) = height;
        }
    };
};