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
#include <Math\mat3.h>

namespace rune{

class RUNE_ENGINE Transform
{
private:

  rune::Vec3 position;
  rune::Vec3 scale;
  rune::Vec3 rotation;

public:
  ///Default constructor
  Transform(rune::Vec3 newPosition = rune::Vec3(0,0,0), rune::Vec3 newScale = rune::Vec3(1,1,1), rune::Vec3 newRotation = rune::Vec3(0,0,0));

  void setScale(rune::Vec3);
  void setScaleX(double);
  void setScaleY(double);
  void setScaleZ(double);

  void setPosition(rune::Vec3);
  void setPositionX(double);
  void setPositionY(double);
  void setPositionZ(double);

  void setRotation(rune::Vec3);
  void setRotationX(double);
  void setRotationY(double);
  void setRotationZ(double);

  rune::Vec3 getPosition(void);
  rune::Vec3 getScale(void);
  rune::Vec3 getRotation(void);

};

}

#endif