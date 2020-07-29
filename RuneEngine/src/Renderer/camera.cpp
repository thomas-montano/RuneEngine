#include "camera.h"
#include <gameApplication.h>
#include <GL\glew.h>
#include <GL\glu.h>
#include <GLFW\glfw3.h>

rune::Camera::Camera() 
  : cameraSize(Vec2(0,0)), centerPosition(Vec2(0,0)), zoomFactor(1.0)
{
}

/**
 * \param newZoom The new zoom level to be used by the camera.
 */
void rune::Camera::setZoom(double newZoom)
{
  zoomFactor = newZoom;
}

void rune::Camera::setViewPort(FloatRect view)
{
  glViewport(view.left,view.top,view.width,view.height);
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

void rune::Camera::setViewport(FloatRect viewPortSize)
{
  //Resize the viewport based on a ratio of the screen i.e. viewPortSize = FloatRect(0.25f,0.25f,0.5f,0.5f);
}
