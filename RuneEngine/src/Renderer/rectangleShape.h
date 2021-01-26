/**
 * @class rune::RectangleShape
 * @brief A rectangle that can be drawn to the screen.
 * 
 * @author Thomas Montano
 * @date April 25 2020
 * 
*/

#ifndef RECTANGLE_H_DEFINED
#define RECTANGLE_H_DEFINED

#include "core.h"
#include "renderWindow.h"
#include "shader.h"
#include <Entities\component.h>
#include "drawable.h"
#include <Math\vec2.h>

namespace rune{

class GameApplication;
class SceneManager;

class RUNE_ENGINE RectangleShape : public rune::Drawable
{
private:

  rune::Color m_fillColor;
  rune::Vec2 origin;

  unsigned int indices[6] =
  {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

  void setUpBuffers(void);

  Vec2 size;
  Vec2 position;
  double rotation;

  const char* defaultRectangle =
  {
  #include <Shaders\defaultRectangle.glsl>
  };

public:
  ///The shader that should be used to draw this rectangle.
  Shader rectangleShader;
  ///The draw call for rendering the shape to the screen.
  virtual void draw(rune::RenderWindow& window);
  ///Default constructor that will create a white rectangle by default.
  RectangleShape(rune::Color newColor = rune::Color::White);
  ///Set the color used to fill the rectangle.
  void setFillColor(rune::Color newFillColor);

};
}

#endif