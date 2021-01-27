/**
 * @class rune::Texture
 * @brief A texture that can be applied to drawable objects.
 * 
 * @author Thomas Montano
 * @date April 27 2020
*/

#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

///Tells the texture to use the GL_LINEAR filter for generating mipmaps.
#define LINEAR_FILTER 0x2601
///Tells the texture to use the GL_NEAREST filter for generating mipmaps.
#define NEAREST_FILTER 0x2600

#include "core.h"
#include <string>

namespace rune{

class RUNE_ENGINE Texture
{
private:
  unsigned int m_textureID;
  std::string m_filePath;
  unsigned char* m_localBuffer;
  int m_width, m_height, m_BPP;

public:
  ///Default constructor to generate a texture that can be bound and drawn.
  Texture(std::string const& path, unsigned int filerMode = LINEAR_FILTER);
  ///Default empty constructor that sets all members to 0.
  Texture();
  ///Default constructor to clean up a no longer needed texture.
  ~Texture(void);
  ///Loads in a texture from a file and stores it in the current rune::Texture object.
  bool loadFromFile(std::string const& path, unsigned int filterMode = LINEAR_FILTER);
  ///Binds the texture to one of the texture slots on the GPU.
  void bind(unsigned int slot = 0);
  ///Unbind the texture to free up space.
  void unbind();
  ///Get the index of the texture ID.
  unsigned int getTextureID(void);
  ///Get the height of the texture.
  unsigned int getHeight(void);
  //Get the width of the texture.
  unsigned int getWidth(void);
  ///Get the raw texture data in byte form.
  unsigned char* getTextureData(void);

};
}

#endif