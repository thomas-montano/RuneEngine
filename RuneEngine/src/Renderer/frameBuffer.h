#pragma once

#ifndef FRAMEBUFFER_H_DEFINED
#define FRAMEBUFFER_H_DEFINED

#include "core.h"
#include <Math/vec2.h>

namespace rune{

struct FrameBufferSpecification
{



};

class RUNE_ENGINE FrameBuffer
{
private:
  unsigned int bufferID, colorAttachment;
  int width, height;

public:

  FrameBuffer();

  ~FrameBuffer();

  void setSize(rune::Vec2 newSize);
  rune::Vec2 getSize(void);

  void invalidate();

  void bind();
  void unbind();

  unsigned int getColorBuffer();


};

}//namespace rune

#endif
