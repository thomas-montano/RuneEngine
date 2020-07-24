#include "camera.h"
#include <gameApplication.h>
#include <cassert>

rune::Vec2 rune::Camera::centerPosition = rune::Vec2(0,0);
double rune::Camera::zoomFactor = 1.0;

rune::Camera::Camera() : cameraSize(getGameInstance()->getWindow()->getSize())
{
  centerPosition = rune::Vec2(0,0);
}

/**
 * \param newZoom The new zoom level to be used by the camera.
 */
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

/**
 * \return A vector the describes the current center position of the camera.
 */
rune::Vec2 rune::Camera::getCenter()
{
  return centerPosition;
}

/**
 * \return The current zoom factor of the camera.
 */
double rune::Camera::getZoom(void)
{
  return zoomFactor;
}

/**
 * \param direction The vector to be added to the current camera position.
 */
void rune::Camera::move(rune::Vec2 speed)
{
  centerPosition += speed * getGameInstance()->getDeltaTime();
}
