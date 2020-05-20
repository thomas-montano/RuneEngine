#include "camera.h"
#include <gameApplication.h>

rune::Vec2 rune::Camera::centerPosition = rune::Vec2(0,0);

rune::Camera::Camera() : zoomFactor(1), cameraSize(rune::GameApplication::getWindow()->getSize())
{
  centerPosition = rune::Vec2(0,0);
}

void rune::Camera::setZoom(double newZoom)
{
  zoomFactor = newZoom;
}

/**
 * @param newCenter The new center coordinate of the camera.
 */
void rune::Camera::setCenter(rune::Vec2 newCenter)
{
  centerPosition = newCenter;
}

rune::Vec2 rune::Camera::getCenter()
{
  return centerPosition;
}
