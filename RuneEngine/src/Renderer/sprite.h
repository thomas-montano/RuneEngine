/**
 * @class Sprite
 * @brief A sprite that can be given a texture and animated.
 * 
 * @author Thomas Montano
 * @date April 27 2020
*/

#ifndef SPRITE_H_DEFINED
#define SPRITE_H_DEFINED

#include "core.h"
#include "renderWindow.h"
#include "texture.h"
#include "drawable.h"
#include "shader.h"
#include "vec2.h"
#include <string>

class RUNE_ENGINE Sprite : public Drawable
{
private:
  Texture spriteTexture;
  Shader spriteShader;

  float vertices[32] = {0};

  unsigned int indices[6] = 
  {  
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

  Vec2 m_position;
  Vec2 m_size;

public:
  ///Default constructor for generating a sprite
  Sprite();
  Sprite(Vec2 dimensions,Vec2 position, std::string spriteLocation);
  virtual void draw(RenderWindow&);
  void setTexture(std::string texture);
  void addPosition(Vec2 newPos);
  void setPosition(Vec2 newPos);

  void setSize(Vec2);

  Vec2 getPosition(void);
  Vec2 getSize(void);

};

#endif