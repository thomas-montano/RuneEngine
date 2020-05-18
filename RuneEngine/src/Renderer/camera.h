#pragma once

/**
 * @class rune::Camera
 * @brief This class is used to control the viewport of the scene.
 *
 * @author Thomas Montano
 * @date May 17 2020
 */

#ifndef CAMERA_H_DEFINED
#define CAMERA_H_DEFINED

#include "core.h"
#include <Math\vec2.h>
#include <Math\mat2.h>

namespace rune{

class RUNE_ENGINE Camera
{
private:
  Mat2 viewport;
public:
  ///Set the zoom factor of the camera.
  void setZoom(double);
  ///Set the center position of the camera.
  void setCenter(rune::Vec2);

};
}

#endif