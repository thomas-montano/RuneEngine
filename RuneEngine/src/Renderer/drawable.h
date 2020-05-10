/**
 * @class Drawable
 * @brief Interface class for creating something that can be drawn to the screen.
 * 
 * @author Thomas Montano
 * @date April 20 2020
 */

#ifndef DRAWABLE_DEFINED
#define DRAWABLE_DEFINED

#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>
#include "core.h"
#include <iostream>
#include <Renderer\vec2.h>

class RenderWindow;

class RUNE_ENGINE Drawable
{

public:
  ///Draw the object to a render target.
  virtual void draw(Vec2 windowSize) = 0;

};

#endif