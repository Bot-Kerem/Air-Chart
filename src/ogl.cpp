#include<AirChart/Renderer/ogl.h>
#include<glad/glad.h>

namespace AirChart
{
    namespace GL
    {
        void init()
        {
            gladLoadGL();
        }

        void clear(unsigned int mask)
        {
            glClear(mask);
        }

        void setClearColor(float r, float g, float b, float a)
        {
            glClearColor(r, g, b, a);
        }
        
    };
};