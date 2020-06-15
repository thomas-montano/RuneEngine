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
  rune::ShaderProgramSource defaultShader =
  rune::ShaderProgramSource(
    "#version 330 core\n"

    "layout(location = 0) in vec2 aPos;\n"
    "layout(location = 1) in vec4 aColor;\n"
    "layout(location = 2) in vec2 aTexCoord;\n"

    "uniform vec2 cameraPos = vec2(0, 0);\n"
    "uniform float cameraZoom = 1;\n"
    "uniform float rotation = 0;\n"
    "uniform vec2 origin = vec2(0,0);\n"
    "uniform float aspectRatio = 1;\n"

    "out vec4 ourColor;\n"
    "out vec2 TexCoord;\n"

    "void main()\n"
    "{\n"

      "vec2 vertices = aPos;\n"

      "vertices = cameraZoom*(vertices - cameraPos);\n"

      "if(rotation != 0)\n"
      "{\n"
        "float angle = radians(rotation);\n"
        "mat2 rotationMatrix = mat2(cos(angle), aspectRatio*sin(angle), -sin(angle)/aspectRatio, cos(angle));\n"
        
        "vertices = vertices - (cameraZoom*origin);\n"
        "vertices = rotationMatrix * vertices;\n"
        "vertices = vertices + (cameraZoom*origin);\n" 
      "}\n"

      "ourColor = aColor;\n"
      "gl_Position = vec4(vertices,0,1);\n"

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
  ///Default constructor for generating a sprite from a PNG file, uses default shader.
  /// Use NEAREST_FILTER for pixel art sprites. LINEAR_FILTER is used by default.
  Sprite(std::string spriteLocation, unsigned int drawMode = LINEAR_FILTER);
  /// Virtual start method being overloaded
  virtual void start();
  /// Virtual update method being overloaded
  virtual void update();
  ///Initialize opengl for the sprite.
  void setUpBuffers(void);
  ///Draw overload so that sprite can be displayed to the screen.
  virtual void draw(rune::RenderWindow&);
  ///Set the texture of the sprite.
  void setTexture(std::string texture);

};

}

#endif