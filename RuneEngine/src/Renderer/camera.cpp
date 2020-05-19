#include "camera.h"
#include <gameApplication.h>

double rune::Camera::zoom = 1.0;

rune::Camera::Camera() //: upVector(0,rune::GameApplication::getWindow()->getSize().y), rightVector(rune::GameApplication::getWindow()->getSize().x,0)
{

}

/**
 * @param zoomLevel The zoom factor to be applied to the camera.
 */
void rune::Camera::setZoom(double zoomLevel)
{
  zoom = zoomLevel;
}

/**
 * @param newCenter The new center coordinate of the camera.
 */
void rune::Camera::setCenter(rune::Vec2 newCenter)
{
  centerPosition = newCenter;
}

void rune::Camera::zoomIn(double increment)
{
  zoom += increment;
}

void rune::Camera::zoomOut(double decrement)
{
  zoom -= decrement;
}

double rune::Camera::getZoom()
{
  if(zoom < 0)
    zoom = 0;

  return zoom;
}
