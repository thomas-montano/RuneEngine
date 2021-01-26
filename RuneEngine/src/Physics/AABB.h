#pragma once

#include <Renderer/drawable.h>


namespace physics
{

  class AABB : public rune::Drawable
  {
  
  public:
    ///Bottom left corner of the AABB.
    rune::Vec2 min;
    ///Top right corner of the AABB.
    rune::Vec2 max;

    AABB() 
      : min(rune::Vec2(0, 0)), max(rune::Vec2(0, 0))
    {

    }

    void draw(rune::RenderWindow& window) override
    {
    
      //rune::Quad boundingQuad(rune::Vec2(min), rune::Vec2(max.x - min.x, max.y - min.y));

      //boundingQuad.drawQuad(window);
    
    }

  private:

  };

}//namespace physics