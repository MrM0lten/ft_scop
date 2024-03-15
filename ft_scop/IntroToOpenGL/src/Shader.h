#pragma once

#include <iostream>
#include "ft_OpenGL.h"

class Shader {
private:
	unsigned int m_shaderID;
	std::string ParseShader(const std::string& path) const;
	int CompileShader(const char* shaderPath, GLuint type);

public:
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	~Shader();
	void Unbind() const;
	void Bind() const;

	void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
	void SetUniform1f(const std::string& name, float f0);
	void SetUniform1i(const std::string& name, int i0);
	void SetUniform1b(const std::string& name, bool value);
	void SetUniformMatrix4fv(const std::string& name, glm::mat4 &m);


	unsigned int GetUniformLocation(const std::string& name);
	
};