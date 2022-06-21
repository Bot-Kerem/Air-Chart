#include <AirChart/Graphs/CandleGraph.h>

#include <AirChart/Renderer/vertexarray.h>
#include <AirChart/Renderer/shader.h>

#include <vector>

namespace AirChart
{
    namespace Graph
    {
        CandleGraph::CandleGraph(std::vector<float>& open, std::vector<float>& close, std::vector<float>& low, std::vector<float>& high, float width, float spacing, float height)
        {
            *(this->width) = width;
            *(this->spacing) = spacing;
            *(this->height) = height;

            size = open.size();

            this->open.bufferData(open.data(), sizeof(float) * size);
            Bar::VertexArray::bind();
            Bar::VertexArray::enableVertexAttribArray(1);
            Bar::VertexArray::vertexAttribPointer(1, 1, sizeof(float), 0);
            Bar::VertexArray::vertexAttribDivisor(1, 1);

            this->close.bufferData(close.data(), sizeof(float) * size);
            Bar::VertexArray::enableVertexAttribArray(2);
            Bar::VertexArray::vertexAttribPointer(2, 1, sizeof(float), 0);
            Bar::VertexArray::vertexAttribDivisor(2, 1);

            std::vector<int> order_data;
            std::vector<int> color_data;
            for (int i = 0; i < size; i++)
            {
                order_data.push_back(i);
                if(open[i]>close[i])
                {
                    color_data.push_back(0);
                    continue;
                }
                color_data.push_back(1);
            }

            this->order.bufferData(order_data.data(), sizeof(int) * size);
            Bar::VertexArray::enableVertexAttribArray(3);
            Bar::VertexArray::vertexAttribPointer(3, 1, sizeof(int), 0);
            Bar::VertexArray::vertexAttribDivisor(3, 1);

            this->color.bufferData(color_data.data(), sizeof(int)*size);
            Bar::VertexArray::enableVertexAttribArray(4);
            Bar::VertexArray::vertexAttribPointer(4, 1, sizeof(int), 0);
            Bar::VertexArray::vertexAttribDivisor(4, 1);
            
            AirChart::VertexBuffer::unbind();
            AirChart::VertexArray::unbind();

            this->high.bufferData(high.data(), sizeof(float) * size);
            line.VertexArray::bind();
            line.enableVertexAttribArray(1);   
            line.vertexAttribPointer(1, 1, sizeof(float), 0);
            line.vertexAttribDivisor(1, 1);

            this->low.bufferData(low.data(), sizeof(float) * size);
            line.enableVertexAttribArray(2);
            line.vertexAttribPointer(2, 1, sizeof(float), 0);
            line.vertexAttribDivisor(2, 1);

            this->order.bind();
            line.enableVertexAttribArray(3);
            line.vertexAttribPointer(3, 1, sizeof(int), 0);
            line.vertexAttribDivisor(3, 1);

            this->color.bind();
            Bar::VertexArray::enableVertexAttribArray(4);
            Bar::VertexArray::vertexAttribPointer(4, 1, sizeof(int), 0);
            Bar::VertexArray::vertexAttribDivisor(4, 1);
            


            this->color.bind();
        }

        CandleGraph::~CandleGraph()
        {
            delete width;
            delete spacing;
            delete height;
        }

        void CandleGraph::draw()
        {
            Shader::currentShader->setFLoat("spacing", *spacing);
            Shader::currentShader->setFLoat("width", *width);
            Shader::currentShader->setFLoat("height", *height);
            Shader::currentShader->setFLoat("offset", 0.0f);
            Shader::currentShader->setVec3("down", glm::vec3(1.0f, 0.0f, 0.0f));
            Shader::currentShader->setVec3("up", glm::vec3(0.0f, 1.0f, 0.0f));
            Bar::VertexArray::bind();
            Bar::drawInstanced(size);
            Shader::currentShader->setFLoat("offset", (*width)/2);
            line.VertexArray::bind();
            line.drawInstanced(size);
        }
    };
};