#pragma once

#ifndef CAMERA_H_DEFINED
#define CAMERA_H_DEFINED

#include "core.h"
#include <Math\vec2.h>

namespace rune{

class RUNE_ENGINE Camera
{
private:

public:

  void setZoom(double);
  void setCenter(rune::Vec2);

};
}

#endif