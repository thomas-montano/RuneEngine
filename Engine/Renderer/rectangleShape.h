/**
 * @class RectangleShape
 * @brief Base class for a rectangle to be drawn on the screen.
 * 
 * @author Thomas Montano
 * @date April 20 2020
*/

#ifndef RECTANGLE_H_DEFINED
#define RECTANGLE_H_DEFINED

#include "renderWindow.h"
#include "drawable.h"
#include "vec2.h"

class RectangleShape : public Drawable
{

private:

  unsigned int buffer;
  unsigned int VAO;
  Vec2 position;
  Vec2 size;

  Vec2 vertices[4];

public:
  virtual void draw(Vec2 windowSize);
  
  RectangleShape(Vec2 position, Vec2 Size);

  void addPosition(Vec2);
  void setPosition(Vec2);

};

#endif