#include "transform.h"
#include <Entities/gameObject.h>

/**
 * \param newPosition The position of the Transform.
 * \param newScale The scale of the Transform.
 * \param newRotation the rotation of the Transform.
 */
rune::Transform::Transform(rune::Vec3 newPosition, rune::Vec3 newScale, rune::Vec3 newRotation)
  : position(newPosition), scale(newScale), rotation(newRotation)
{
  
}

void rune::Transform::update()
{
  if(parentTransform != nullptr)
  {
    position = parentTransform->position + localPosition;
  }
}

/**
 * \return The position vector of the Transform.
 */
rune::Vec3 rune::Transform::getPosition(void)
{
  return position;
}

/**
 * \return The scale of the Transform.
 */
rune::Vec3 rune::Transform::getScale(void)
{
  return scale;
}

/**
 * \return The rotation of the Transform.
 */
rune::Vec3 rune::Transform::getRotation(void)
{
  return rotation;
}

/**
 * \param newLocalPosition The new position of the Transform with respect to the parent Transform.
 */
void rune::Transform::setLocalPosition(rune::Vec3 newLocalPosition)
{
  if(parentTransform != nullptr)
  {
    localPosition = newLocalPosition;
  }
}

/**
 * \return The position of the Transform with respect to the parent Transform.
 */
rune::Vec3 rune::Transform::getLocalPosition(void)
{
  return localPosition;
}

/**
 * \param newScale The new scale of the Transform.
 */
void rune::Transform::setScale(rune::Vec3 newScale)
{
  scale = newScale;
}

/**
 * \param newX The new X scale of the Transform.
 */
void rune::Transform::setScaleX(double newX)
{
  scale.x = newX;
}

/**
 * \param newY The new Y scale of the Transform.
 */
void rune::Transform::setScaleY(double newY)
{
  scale.y = newY;
}

/**
 * \param newZ The new Z scale of the Transform.
 */
void rune::Transform::setScaleZ(double newZ)
{
  scale.z = newZ;
}

/**
 * \param newRotation The new rotation vector of the Transform.
 */
void rune::Transform::setRotation(rune::Vec3 newRotation)
{
  rotation = newRotation;
}

/**
 * \param newX The new X rotation of the Transform.
 */
void rune::Transform::setRotationX(double newX)
{
  rotation.x = newX;
}

/**
 * \param newY The new Y rotation of the Transform.
 */
void rune::Transform::setRotationY(double newY)
{
  rotation.y = newY;
}

/**
 * \param newZ The new Z rotation of the Transform.
 */
void rune::Transform::setRotationZ(double newZ)
{
  rotation.z = newZ;
}

/**
 * \param newPosition The new position vector of the Transform.
 */
void rune::Transform::setPosition(rune::Vec3 newPosition)
{
  position = newPosition;
}

/**
 * \param newX The new X position of the Transform.
 */
void rune::Transform::setPositionX(double newX)
{
  position.x = newX;
}

/**
 * \param newY The new Y position of the Transform.
 */
void rune::Transform::setPositionY(double newY)
{
  position.y = newY;
}

/**
 * \param newZ The new Z position of the Transform.
 */
void rune::Transform::setPositionZ(double newZ)
{
  position.z = newZ;
}

/**
 * \param newBounds The new boundary of the Transform.
 */
void rune::Transform::setBounds(rune::Vec2 newBounds)
{
  bounds = newBounds;
}

/**
 * \return The boundary of the Transform in pixel coordinates.
 */
rune::Vec2 rune::Transform::getBounds(void)
{
  return rune::Vec2(bounds.x * scale.x, bounds.y * scale.y);
}