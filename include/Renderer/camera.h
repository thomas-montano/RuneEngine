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
#include "rect.h"

namespace rune{

class RUNE_ENGINE Camera
{
private:
  Vec2 centerPosition;
  Vec2 cameraSize;
  double zoomFactor;
public:
  ///Default constructor to create a Camera object.
  Camera(void);
  ///Set the zoom factor of the camera.
  void setZoom(double);
  ///Set the viewport size of a camera.
  void setViewPort(FloatRect);
  ///Set the center position of the camera.
  void setCenter(rune::Vec2);
  ///Get the current camera position
  Vec2 getCenter(void);
  ///Get the current zoom level
  double getZoom(void);
  ///Move the camera in a certain direction
  void move(rune::Vec2);
  ///Set the size of the camera viewport.
  void setViewport(FloatRect viewPortSize);
};
}

#endif