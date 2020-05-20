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
  static Vec2 centerPosition;
  Vec2 cameraSize;
  static double zoomFactor;
public:
  Camera(void);
  ///Set the zoom factor of the camera.
  void setZoom(double);
  ///Set the center position of the camera.
  void setCenter(rune::Vec2);
  ///Get the current camera position
  static Vec2 getCenter(void);
  ///Get the current zoom level
  static double getZoom(void);
};
}

#endif