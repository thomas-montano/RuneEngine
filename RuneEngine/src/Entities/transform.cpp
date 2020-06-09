#include "transform.h"

rune::Transform::Transform(rune::Vec3 newPosition, rune::Vec3 newScale, rune::Vec3 newRotation)
  : position(newPosition), scale(newScale), rotation(newRotation)
{
  
}

rune::Vec3 rune::Transform::getPosition(void)
{
  return position;
}

rune::Vec3 rune::Transform::getScale(void)
{
  return scale;
}

rune::Vec3 rune::Transform::getRotation(void)
{
  return rotation;
}

void rune::Transform::setScale(rune::Vec3 newScale)
{
  scale = newScale;
}

void rune::Transform::setScaleX(double newX)
{
  scale.x = newX;
}

void rune::Transform::setScaleY(double newY)
{
  scale.y = newY;
}

void rune::Transform::setScaleZ(double newZ)
{
  scale.z = newZ;
}

void rune::Transform::setRotation(rune::Vec3 newRotation)
{
  rotation = newRotation;
}

void rune::Transform::setRotationX(double newX)
{
  rotation.x = newX;
}

void rune::Transform::setRotationY(double newY)
{
  rotation.y = newY;
}

void rune::Transform::setRotationZ(double newZ)
{
  rotation.z = newZ;
}

void rune::Transform::setPosition(rune::Vec3 newPosition)
{
  position = newPosition;
}

void rune::Transform::setPositionX(double newX)
{
  position.x = newX;
}

void rune::Transform::setPositionY(double newY)
{
  position.y = newY;
}

void rune::Transform::setPositionZ(double newZ)
{
  position.z = newZ;
}