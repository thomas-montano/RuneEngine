/**
 * @class rune::Drawable
 * @brief Interface class for creating something that can be drawn to the screen.
 * 
 * @author Thomas Montano
 * @date April 20 2020
 */

#ifndef DRAWABLE_DEFINED
#define DRAWABLE_DEFINED

#include "core.h"
#include "shader.h"
#include <Math\vec2.h>
#include <Renderer\RenderWindow.h>

namespace rune{

class RUNE_ENGINE Drawable
{

public:
  
  ///Draw the object to a render window.
  virtual void draw(rune::RenderWindow&) = 0;

};
}

#endif