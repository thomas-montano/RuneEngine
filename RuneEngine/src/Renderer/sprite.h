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
#include <Math\vec2.h>
#include <string>

class RUNE_ENGINE Sprite : public Drawable
{
private:
  Texture spriteTexture;
  Shader spriteShader;
  Vec2 origin;

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
  ///Default empty constructor for generating a sprite
  Sprite();
  ///Default constructor that initializes the sprite to a drawable state.
  Sprite(Vec2 dimensions,Vec2 position, std::string spriteLocation);
  ///Draw overload so that sprite can be displayed to the screen.
  virtual void draw(RenderWindow&);
  ///Set the texture of the sprite.
  void setTexture(std::string texture);
  ///Add to the current position of the sprite.
  void addPosition(Vec2 newPos);
  ///Overwrite the position of the sprite.
  void setPosition(Vec2 newPos);
  ///Set the offset of the sprite with respect to the bottom left corner.
  void setOrigin(Vec2 newOrigin);
  ///Set the dimensions of the sprite.
  void setSize(Vec2);
  ///Get the current position of the center of the sprite.
  Vec2 getPosition(void);
  ///Get the current dimensions of the sprite.
  Vec2 getSize(void);

};

#endif