#ifndef AC_SHADER_H
#define AC_SHADER_H

#include <glm/glm.hpp>

namespace AirChart
{
    class Shader
    {
        public:
            Shader(const char* vertexPath, const char* fragmentPath);
            ~Shader();

            void use();

            void setFLoat(const char* name, const float value);
            void setInt(const char* name, const int value);
            void setVec2(const char* name, const glm::vec2& value);
            void setVec3(const char* name, const glm::vec3& value);
            void setVec4(const char* name, const glm::vec4& value);
            void setMat4(const char* name, const glm::mat4* ptrValue);
            void setMat3(const char* name, const glm::mat3* ptrValue);

            static Shader* currentShader;

        protected:
            unsigned int program;
            int getUniformLocation(const char* varName);
            int status(unsigned int T, unsigned int type);
    };
};

#endif