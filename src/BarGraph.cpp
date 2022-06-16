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
        BarGraph::BarGraph(std::vector<float>* graph, float width, float gap, float height)
        { 
            this->graph = graph;
            *(this->width) = width;
            *(this->gap) = gap;
            *(this->height) = height;
        }

        BarGraph::BarGraph(float* graph, unsigned int size, float width, float gap, float height)
        {
            this->graph_data = graph;
            this->size = size;
            *(this->width) = width;
            *(this->gap) = gap;
            *(this->height) = 10.0f;
            *(this->height) = height;
        }

        BarGraph::~BarGraph(){}
        
        void BarGraph::update(std::vector<float>* graph)
        {
            this->graph = graph;
        }

        void BarGraph::update(float* graph, unsigned int size)
        {
            this->graph_data = graph;
            this->size = size;
        }

        void BarGraph::draw_graph()
        {
            Bar::_bind();
            if(graph)
            {
                for(int i = 0; i < graph->size(); i++)
                {
                    glm::vec3 translate = glm::vec3((i*((*width)+(*gap))+(*gap)), 0.0f, 0.0f);
                    glm::mat3 scale = glm::scale(glm::mat3(1.0f), glm::vec2((*width), ((*graph)[i]*(*height))));
                    Shader::currentShader->setVec3("translate", translate);
                    Shader::currentShader->setMat3("scale", &scale);
                    
                    Bar::_draw();
                }
            }
            else
            {
                for(int i = 0; i < size; i++)
                {
                    glm::vec3 translate = glm::vec3((i*((*width)+(*gap))+(*gap)), 0.0f, 0.0f);
                    glm::mat3 scale = glm::scale(glm::mat3(1.0f), glm::vec2((*width), (graph_data[i]*(*height))));
                    Shader::currentShader->setVec3("translate", translate);
                    Shader::currentShader->setMat3("scale", &scale);
                    
                    Bar::_draw();
                }
            }
        }

        void BarGraph::draw_graph(glm::vec2 position)
        {
            Bar::_bind();
            if(graph)
            {
                for(int i = 0; i < graph->size(); i++)
                {
                    glm::vec3 translate = glm::vec3((i*((*width)+(*gap))+(*gap))+position.x , position.y, 0.0f);
                    glm::mat3 scale = glm::scale(glm::mat3(1.0f), glm::vec2((*width), (*graph)[i]*(*height)));
                    Shader::currentShader->setVec3("translate", translate);
                    Shader::currentShader->setMat3("scale", &scale);

                    Bar::_draw();
                }
            }
            else
            {
                for(int i = 0; i < size; i++)
                {
                    glm::vec3 translate = glm::vec3((i*((*width)+(*gap))+(*gap))+position.x , position.y, 0.0f);
                    glm::mat3 scale = glm::scale(glm::mat3(1.0f), glm::vec2((*width), graph_data[i]*(*height)));
                    Shader::currentShader->setVec3("translate", translate);
                    Shader::currentShader->setMat3("scale", &scale);

                    Bar::_draw();
                }
            }
        }

    };
};