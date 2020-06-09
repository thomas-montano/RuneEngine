/**
 * @class rune::Sprite
 * @brief A sprite that can be given a texture and animated.
 * 
 * @author Thomas Montano
 * @date April 27 2020
*/

#ifndef SPRITE_H_DEFINED
#define SPRITE_H_DEFINED

#include "core.h"
#include <Entities\component.h>
#include "renderWindow.h"
#include "texture.h"
#include "drawable.h"
#include "shader.h"
#include <Math\vec2.h>
#include <string>

namespace rune{

class RUNE_ENGINE Sprite : public Drawable, public Component
{
private:
  Texture spriteTexture;
  Shader spriteShader;
  rune::Vec2 origin;

  unsigned int indices[6] = 
  {  
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

public:
  ///Default empty constructor for generating a sprite, uses default shader.
  Sprite();
  ///Default constructor that initializes the sprite to a drawable state, uses default shader.
  Sprite(std::string spriteLocation);
  virtual void start();
  /// Virtual update method being overloaded
  virtual void update();
  ///Initialize opengl for the sprite.
  void setUpBuffers(void);
  ///Draw overload so that sprite can be displayed to the screen.
  virtual void draw(rune::RenderWindow&);
  ///Set the texture of the sprite.
  void setTexture(std::string texture);
  ///Add to the current position of the sprite.
  void addPosition(rune::Vec2 newPos);
  ///Overwrite the position of the sprite.
  void setPosition(rune::Vec2 newPos);
  ///Set the offset of the sprite with respect to the bottom left corner.
  void setOrigin(rune::Vec2 newOrigin);
  ///Set the dimensions of the sprite.
  void setSize(rune::Vec2);
  ///Get the current position of the center of the sprite.
  rune::Vec2 getPosition(void);
  ///Get the current dimensions of the sprite.
  rune::Vec2 getSize(void);

  rune::ShaderProgramSource defaultShader=
    ShaderProgramSource(
    "#version 330 core\n"

    "layout(location = 0) in vec2 aPos;\n"
  "layout(location = 1) in vec4 aColor;\n"
  "layout(location = 2) in vec2 aTexCoord;\n"

  "uniform vec4 cameraPos = vec4(0, 0, 0, 0);\n"

  "out vec4 ourColor;\n"
  "out vec2 TexCoord;\n"

  "void main()\n"
  "{\n"
    "gl_Position = vec4(aPos, 1.0, 1.0) - cameraPos;\n"
    "ourColor = aColor;\n"
    "TexCoord = aTexCoord;\n"
  "}\n"
  ,
    "#version 330 core\n"

    "out vec4 FragColor;\n"

  "in vec4 ourColor;\n"
  "in vec2 TexCoord;\n"

  "uniform sampler2D ourTexture;\n"

  "void main()\n"
  "{\n"
    "FragColor = texture(ourTexture, TexCoord) * ourColor;\n"
  "}\n");


};

}

#endif