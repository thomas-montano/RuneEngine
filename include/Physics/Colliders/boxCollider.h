#pragma once

#include <core.h>
#include "collider.h"
#include <Entities/component.h>
#include <Entities/gameObject.h>

namespace physics{

  class RUNE_ENGINE BoxCollider : public Collider, rune::Component
  {
  private:
    double rotation;
    rune::Vec2 boxSize;

  public:
    BoxCollider();

    AABB computeAABB() override;

  };  

}