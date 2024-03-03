#pragma once

#include <iostream>
#include "ft_OpenGL.h"

class Texture {
public:
	Texture(const std::string& path, GLint imageFormat, int textureSlot);
	~Texture();
	//void Bind(unsigned int slot) const;
	//void Unbind() const;

private:
	unsigned int RendererID;

	int width;
	int height;
	int channels;
	unsigned char* data;

};