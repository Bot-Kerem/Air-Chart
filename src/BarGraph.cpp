#include<AirChart/Graphs/BarGraph.h>
#include<AirChart/Renderer/shader.h>

#include<glm/gtx/matrix_transform_2d.hpp>
#include<glm/mat3x3.hpp>
#include<glm/vec2.hpp>

#include<iostream>

namespace AirChart 
{
    namespace Graph 
    {
        BarGraph::BarGraph(std::vector<float>& graph, float width, float gap, float height)
        { 
            *(this->width) = width;
            *(this->gap) = gap;
            *(this->height) = height;
            size = graph.size();

            instance.bufferData(graph.data(), sizeof(float)*graph.size());
            Bar::VertexArray::enableVertexAttribArray(1);
            instance.bind();
            Bar::VertexArray::vertexAttribPointer(1, 1, sizeof(float), 0);
            Bar::VertexArray::vertexAttribDivisor(1, 1);
            AirChart::VertexBuffer::unbind();
            std::vector<int> order;
            for(int i = 0; i < graph.size(); i++)
            {
                order.push_back(i);
            }
            order_buffer.bufferData(order.data(), order.size()*sizeof(int));
            Bar::VertexArray::enableVertexAttribArray(2);
            order_buffer.bind();
            Bar::VertexArray::vertexAttribPointer(2, 1, sizeof(int), 0, 0x1404);
            Bar::VertexArray::vertexAttribDivisor(2, 1);
            AirChart::VertexBuffer::unbind();

        }

        BarGraph::BarGraph(float* graph, unsigned int size, float width, float gap, float height)
        {
            *(this->width) = width;
            *(this->gap) = gap;
            *(this->height) = 10.0f;
            *(this->height) = height;

            instance.bufferData(graph, sizeof(float)*size);
            Bar::VertexArray::enableVertexAttribArray(2);
            instance.bind();
            Bar::VertexArray::vertexAttribPointer(2, 1, sizeof(float), 0);
            AirChart::VertexBuffer::unbind();
        }

        BarGraph::~BarGraph(){}

        void BarGraph::draw_graph()
        {

        }

        void BarGraph::draw_graph(glm::vec2 position)
        {
            Bar::drawInstanced(size);
        }

    };
};