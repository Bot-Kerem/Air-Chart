#ifndef AC_OGL_H
#define AC_OGL_H

namespace AirChart
{
    namespace GL
    {
        void init();

        void setClearColor(float r, float g, float b, float a=1.0f);
        void clear(unsigned int mask=0x00004000);
    }  
};

#endif