/**
 * @class rune::Transform
 * @brief A data structure that contains position, size, and rotation.
 *
 * @author Thomas Montano
 * @date June 9 2020
*/

#pragma once

#ifndef TRANSFORM_H_DEFINED
#define TRANSFORM_H_DEFINED

#include "core.h"
#include <Entities\component.h>
#include <Math\vec3.h>
#include <Math\vec2.h>
#include <Math\mat3.h>

namespace rune{

class RUNE_ENGINE Transform : public rune::Component
{
private:

  rune::Vec3 position;
  rune::Vec3 scale;
  rune::Vec3 rotation;
  rune::Vec3 localPosition = rune::Vec3(0,0,0);
  rune::Vec2 bounds;

public:
  ///Pointer to parent object
  Transform* parentTransform = nullptr;

  ///Default constructor
  Transform(rune::Vec3 newPosition = rune::Vec3(0,0,0), rune::Vec3 newScale = rune::Vec3(1,1,1), rune::Vec3 newRotation = rune::Vec3(0,0,0));

  ///Override of the update component function to update the position of the transform if there is a parent Transform.
  virtual void update() override;

  ///Set the scale vector.
  void setScale(rune::Vec3);
  ///Set the X scale.
  void setScaleX(double);
  ///Set the Y scale.
  void setScaleY(double);
  ///Set the Z scale.
  void setScaleZ(double);

  ///Set the position vector.
  void setPosition(rune::Vec3);
  ///Set the X position.
  void setPositionX(double);
  ///Set the Y position.
  void setPositionY(double);
  ///Set the Z position.
  void setPositionZ(double);

  ///Set the rotation vector.
  void setRotation(rune::Vec3);
  ///Set the X rotation.
  void setRotationX(double);
  ///Set the Y rotation.
  void setRotationY(double);
  ///Set the Z rotation.
  void setRotationZ(double);

  ///Set the position of the transform relative to the transform parent.
  void setLocalPosition(rune::Vec3 newLocalPosition);

  ///Get the position of the transform in world coordinates.
  rune::Vec3 getPosition(void);
  ///Get the scale factor of the transform.
  rune::Vec3 getScale(void);
  ///Get the rotation vector of the transform.
  rune::Vec3 getRotation(void);
  ///Get the position of the transform with respect to the parent object.
  rune::Vec3 getLocalPosition(void);

  ///Set the boundaries of the current renderer.
  void setBounds(rune::Vec2 newBounds);
  ///Get the boundaries of the current renderer.
  rune::Vec2 getBounds(void);

};

}

#endif