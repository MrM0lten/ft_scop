#include "Texture.h"

Texture::Texture(const std::string& path, GLint imageFormat,int textureSlot)
	:RendererID(-1), width(0), height(0), channels(0),data(nullptr)
{
    glGenTextures(1, &RendererID);
    std::cout << RendererID << path << std::endl;
    glActiveTexture(GL_TEXTURE0 + textureSlot);
    glBindTexture(GL_TEXTURE_2D, RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture fom path: " << path << std::endl;
    }

}

Texture::~Texture()
{
	stbi_image_free(data);
}

//void Texture::Bind(unsigned int slot) const
//{
//    glActiveTexture(GL_TEXTURE0 + slot);
//    glBindTexture(GL_TEXTURE_2D, RendererID);
//}
//
//void Texture::Unbind() const
//{
//
//}