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
#include "rect.h"

namespace rune{

class RUNE_ENGINE Sprite : public Drawable, public Component
{
private:

  Texture spriteTexture;

  unsigned int indices[6] =
  {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

  //Texture rectangle
  IntRect textureSpace;

  bool isMirrored;

  unsigned int spriteDrawMode;

  const char* defaultSprite = 
  {
  #include <Shaders/defaultSprite.glsl>
  };

public:
  ///The Shader that should be used to draw the sprite.
  Shader objectShader;
  ///Default empty constructor for generating a sprite, uses default shader.
  Sprite();
  ///Default constructor for generating a sprite from a PNG file, uses default shader.
  Sprite(std::string const& spriteLocation, unsigned int drawMode = LINEAR_FILTER);
  ///Virtual awake method being overloaded.
  virtual void awake() override;
  /// Virtual start method being overloaded
  virtual void start() override;
  ///Initialize opengl for the sprite.
  void setUpBuffers(void);
  ///Draw overload so that sprite can be displayed to the screen.
  virtual void draw(rune::RenderWindow&);
  ///Set the texture of the sprite.
  void setTexture(std::string const& texture, unsigned int drawMode = LINEAR_FILTER);
  ///Set the texture based off another already loaded texture.
  void setTexture(Texture* texture);
  ///Set the area of the texture to be rendered.
  void setTextureRect(int xPos, int yPos, int width, int height);
  ///Return the rectangle.
  IntRect getTextureRect(void);
  ///Returns the filtering mode of the sprite.
  unsigned int getDrawMode();
  ///Sets whether or not the sprite should be drawn in reverse.
  void setMirror(bool mirror);
  ///Gets whether or not the sprite should be drawn in reverse.
  bool getMirror(void);
  ///The Color of the sprite for drawing purposes
  Color spriteColor;

};

}

#endif