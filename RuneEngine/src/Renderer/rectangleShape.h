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

class RUNE_ENGINE RectangleShape : public Drawable, public Component
{

private:

  Shader rectangleShader;
  rune::Vec2 origin;
  Color shapeColor;

  unsigned int indices[6] =
  {
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };

  unsigned int VBO;
  unsigned int EBO;
  unsigned int VAO;

public:

  virtual void start();
  virtual void update();

  virtual void draw(rune::RenderWindow&);
  
  RectangleShape(rune::Color newColor = rune::Color(255,255,255), rune::Vec2 newOrigin = rune::Vec2(0,0));

  void setUpBuffers();

  void setFillColor(rune::Color);

};
}

#endif