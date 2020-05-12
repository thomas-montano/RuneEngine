#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

/**
 * @param path The file path for the texture that you would like to load relative to the main executable.
*/
Texture::Texture(const std::string& path)
  : m_textureID(0), m_filePath(path), m_localBuffer(nullptr),
  m_width(0), m_height(0), m_BPP(0)
{ 
  //Load the png file and prepare it to be loaded as a texture
  stbi_set_flip_vertically_on_load(1);
  m_localBuffer = stbi_load(path.c_str(),&m_width, &m_height, &m_BPP, 4);

  //Generate and bind a texture
  glGenTextures(1, &m_textureID);
  glBindTexture(GL_TEXTURE_2D, m_textureID);

  //Set wrapping parameters for texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  //Set the border to be invisible
  //float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

  //load image, create texture and generate mipmaps
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
  glGenerateMipmap(GL_TEXTURE_2D);

  if(m_localBuffer)
  {
    stbi_image_free(m_localBuffer);
  }
  else
  {
    std::cout << "Failed to load texture" << std::endl;
  }
  
}

Texture::Texture()
:m_textureID(0), m_filePath(" "), m_localBuffer(nullptr),
m_width(0), m_height(0), m_BPP(0)
{

}

bool Texture::loadFromFile(const std::string& path)
{

  m_textureID = 0;
  m_filePath = path;
  m_localBuffer = nullptr;
  m_width = 0;
  m_height = 0;
  m_BPP = 0;

  //Load the png file and prepare it to be loaded as a texture
  stbi_set_flip_vertically_on_load(1);
  m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

  //Generate and bind a texture
  glGenTextures(1, &m_textureID);
  glBindTexture(GL_TEXTURE_2D, m_textureID);

  //Set wrapping parameters for texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  //Set the border to be invisible
  //float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

  //load image, create texture and generate mipmaps
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
  glGenerateMipmap(GL_TEXTURE_2D);

  if (m_localBuffer)
  {
    stbi_image_free(m_localBuffer);

    return true;
  }
  else
  {
    std::cout << "Failed to load texture" << std::endl;
    return false;
  }

}

Texture::~Texture()
{
  glDeleteTextures(1,&m_textureID);
}

/**
 * @param slot The texture slot on the GPU that you would like to bind this texture to.
*/
void Texture::bind(unsigned int slot)
{
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void Texture::unbind()
{
  glBindTexture(GL_TEXTURE_2D,0);
}

/**
 * @return The index of the texture in OpenGL.
*/
unsigned int Texture::getTextureID(void)
{
  return m_textureID;
}

/**
 * @return The total height of the texture.
*/
unsigned int Texture::getHeight(void)
{
  return m_height;
}

/**
 * @return The total width of the texture.
*/
unsigned int Texture::getWidth(void)
{
  return m_width;
}