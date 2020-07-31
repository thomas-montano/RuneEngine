#pragma once

#include <core.h>
#include <Entities/component.h>
#include "collider.h"

namespace physics {

  class RUNE_ENGINE CircleCollider : public Collider, rune::Component
  {
  private:
    double radius;

  public:
    AABB computeAABB() override;

  };
}