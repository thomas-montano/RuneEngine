/**
 * @class Sprite
 * @brief A sprite that can be given a texture and animated.
 * 
 * @author Thomas Montano
 * @date April 27 2020
*/

#ifndef SPRITE_H_DEFINED
#define SPRITE_H_DEFINED

#include "renderWindow.h"
#include "texture.h"
#include "rectangleShape.h"
#include "vec2.h"
#include <string>

class Sprite : public Drawable
{
private:
  Texture spriteTexture;
  Shader spriteShader;

  float vertices[32] = 
  {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
  };

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
  Sprite(Vec2 dimensions,Vec2 position, std::string spriteLocation);
  virtual void draw(Vec2 windowSize);
  void addPosition(Vec2 newPos);
  void setPosition(Vec2 newPos);

};

#endif