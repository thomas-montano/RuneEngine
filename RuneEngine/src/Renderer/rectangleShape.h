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
#include "vec2.h"

class RUNE_ENGINE RectangleShape : public Drawable
{

private:

  Shader rectangleShader;

  unsigned int buffer;
  unsigned int VAO;
  Vec2 position;
  Vec2 size;

  Vec2 vertices[4];

public:
  virtual void draw(RenderWindow&);
  
  RectangleShape();
  RectangleShape(Vec2 position, Vec2 Size);

  void addPosition(Vec2);
  void setPosition(Vec2);

  void setSize(Vec2);

};

#endif