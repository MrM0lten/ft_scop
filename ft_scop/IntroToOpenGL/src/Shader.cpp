#include "Shader.h"
#include <sstream>
#include <fstream>
#include <stdexcept>

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    unsigned int vertexShader = CompileShader(ParseShader(vertexShaderPath).c_str(), GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(ParseShader(fragmentShaderPath).c_str(), GL_FRAGMENT_SHADER);

    m_shaderID = glCreateProgram();
    glAttachShader(m_shaderID, vertexShader);
    glAttachShader(m_shaderID, fragmentShader);
    glLinkProgram(m_shaderID);

    int  success;
    char infoLog[512];
    glGetProgramiv(m_shaderID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(m_shaderID);
}

std::string Shader::ParseShader(const std::string& path) const
{
    std::ifstream file(path);
    std::stringstream buffer;
    
    if (file.is_open()) {
        std::cout << "Opened file: " << path << std::endl;
        buffer << file.rdbuf();
        file.close();

        return buffer.str(); //fix!!!!
    }
    return "File could not be opend";

}

int Shader::CompileShader(const char *shaderPath, GLuint  type)
{
    unsigned int shaderID;
    shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &shaderPath, NULL);
    glCompileShader(shaderID);

    int  success;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR "<< shaderPath <<" COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shaderID;
}

void Shader::Bind() const
{
    glUseProgram(m_shaderID);
}

void Shader::SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
{
    glUniform4f(GetUniformLocation(name),f0,f1,f2,f3);
}

void Shader::SetUniform1f(const std::string& name, float f0)
{
    glUniform1f(GetUniformLocation(name), f0);
}

void Shader::SetUniform1i(const std::string& name, int i0)
{
    glUniform1i(GetUniformLocation(name), i0);
}

void Shader::SetUniform1b(const std::string& name, bool value)
{
    glUniform1i(GetUniformLocation(name), value);
}

unsigned int Shader::GetUniformLocation(const std::string& name)
{
    return glGetUniformLocation(m_shaderID, name.c_str());
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

