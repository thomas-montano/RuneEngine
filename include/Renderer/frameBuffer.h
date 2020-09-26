/**
 * @class rune::FrameBuffer
 * @brief An off screen frame buffer that can be bound and rendered to.
 *
 * @author Thomas Montano
 * @date June 30 2020
*/

#pragma once

#ifndef FRAMEBUFFER_H_DEFINED
#define FRAMEBUFFER_H_DEFINED

#include "core.h"
#include <Math/vec2.h>

namespace rune{

class RUNE_ENGINE FrameBuffer
{
private:
  unsigned int bufferID, colorAttachment;
  int width, height;

public:
  ///Default constructor to initialize an opengl frame buffer.
  FrameBuffer();
  ///Default destructor to clean up frame buffer.
  ~FrameBuffer();
  ///Set the size of the frame buffer in pixels.
  void setSize(rune::Vec2 newSize);
  ///Get the size of the frame buffer in pixels.
  rune::Vec2 getSize(void);
  ///Tell the frame buffer it is invalid and should be recreated.
  void invalidate();
  ///Bind the frame buffer for drawing.
  void bind();
  ///Unbind the frame buffer for drawing.
  void unbind();
  ///Get a handle to the color buffer for drawing.
  unsigned int getColorBuffer();

};

}//namespace rune

#endif
