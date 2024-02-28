#pragma once

#include <iostream>
#include "ft_OpenGL.h"

class Shader {
private:
	unsigned int m_shaderID;
	std::string& ParseShader(const std::string& path) const;
	int CompileShader(const char* shaderPath, GLuint type);

public:
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	~Shader();
	void Unbind() const;
	void Bind() const;
};