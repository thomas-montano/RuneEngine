/**
 * @class physics::Collider
 * @brief A collider that is to be used for registering collisions between objects in the scene.
 *
 * @author Thomas Montano
 * @date June 9 2020
 */

#pragma once

#include "core.h"
#include <Entities/component.h>
#include <Math/vec2.h>
#include <Physics/AABB.h>
#include <Renderer/rectangleShape.h>
#include <Events/subject.h>

#ifndef COLLIDER_H_DEFINED
#define COLLIDER_H_DEFINED

namespace physics{

class RUNE_ENGINE Collider : public rune::Subject
{
protected:
  ///The axis aligned bounding box that surrounds the collider.
  AABB boundingBox;
  ///The amount of offset from the center of the AABB that should be applied.
  rune::Vec2 offset;

public: 
  ///Default empty constructor to make a new collider.
  Collider();
  ///Computes the appropriate physics::AABB that should be given to the collider.
  virtual AABB computeAABB(void) = 0;




};
}

#endif