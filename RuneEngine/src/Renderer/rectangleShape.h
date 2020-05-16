/**
 * @class RectangleShape
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
#include "drawable.h"
#include <Math\vec2.h>

class RUNE_ENGINE RectangleShape : public Drawable
{

private:

  Shader rectangleShader;

  unsigned int buffer;
  unsigned int VAO;
  rune::Vec2 position;
  rune::Vec2 size;

  rune::Vec2 vertices[4];

public:
  virtual void draw(RenderWindow&);
  
  RectangleShape();
  RectangleShape(rune::Vec2 position, rune::Vec2 Size);

  void addPosition(rune::Vec2);
  void setPosition(rune::Vec2);

  void setSize(rune::Vec2);

};

#endif