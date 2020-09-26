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
  AABB boundingBox;
  rune::Vec2 offset;

public: 
  Collider();

  virtual AABB computeAABB(void) = 0;




};
}

#endif