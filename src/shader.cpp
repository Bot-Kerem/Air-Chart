#include<AirChart/Renderer/shader.h>
#include<AirChart/Core/file.h>

#include<glad/glad.h>
#include<iostream>

namespace AirChart
{
    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        program = glCreateProgram();
        
        unsigned int vertexShader;
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		std::string sourceCode = File::openFile(vertexPath);
		const char* src = &sourceCode[0];
		glShaderSource(vertexShader, 1, &src, 0);
		glCompileShader(vertexShader);
		status(vertexShader, GL_SHADER);
	}

    unsigned int fragmentShader;
	{
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		std::string sourceCode = File::openFile(fragmentPath);
		const char* src = &sourceCode[0];
		glShaderSource(fragmentShader, 1, &src, 0);

		glCompileShader(fragmentShader);
		status(fragmentShader, GL_SHADER);
	}

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	status(program, GL_PROGRAM);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

    }

    Shader::~Shader()
    {
        glDeleteProgram(program);
    }

    void Shader::use()
    {
        glUseProgram(program);
    }

    int Shader::status(unsigned int T, unsigned int type)
    {
        char log[512];
        if (type == GL_PROGRAM)
        {
            int linkStatus;
            glGetProgramiv(T, GL_LINK_STATUS, &linkStatus);
            if (!linkStatus)
            {
                glGetProgramInfoLog(T, 512, 0, log);
                std::cout << log << std::endl;
                return linkStatus;
            }
        }
        else if (type == GL_SHADER)
        {
            int isCompiled;
            glGetShaderiv(T, GL_COMPILE_STATUS, &isCompiled);
            if (!isCompiled)
            {
                glGetShaderInfoLog(T, 512, 0, log);
                std::cout << log << std::endl;
                return isCompiled;
            }
        }
        return 1;
    }

    int Shader::getUniformLocation(const char* varName)
    {
        return glGetUniformLocation(program, varName);
    }

    void Shader::setFLoat(const char* name, const float value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setInt(const char* name, const int value)
    {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setVec2(const char* name, const glm::vec2& value)
    {
        glUniform2fv(getUniformLocation(name), 1, &value[0]);
    }

    void Shader::setVec3(const char* name, const glm::vec3& value)
    {
        glUniform3fv(getUniformLocation(name), 1, &value[0]);
    }

    void Shader::setVec4(const char* name, const glm::vec4& value)
    {
        glUniform4fv(getUniformLocation(name), 1, &value[0]);
    }

    void Shader::setMat4(const char* name, const glm::mat4* ptrValue)
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, (float*)&ptrValue[0][0]);
    }

    void Shader::setMat3(const char* name, const glm::mat3* ptrValue)
    {
        glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, (float*)&ptrValue[0][0]);
    }

};