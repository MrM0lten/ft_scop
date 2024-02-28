#include "Shader.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
    unsigned int vertexShader = CompileShader(vertexShaderPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(fragmentShaderPath, GL_FRAGMENT_SHADER);


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

std::string& Shader::ParseShader(const std::string& path) const
{
    //function should take a file path and generate a string to be passed to compile shader
    return (std::string&)"fix me"; //fix!!!!
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

void Shader::Unbind() const
{
    glUseProgram(0);
}

