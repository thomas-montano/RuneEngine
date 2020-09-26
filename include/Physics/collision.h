#pragma once

#include "rigidBody.h"

namespace physics{

class collision
{

  RigidBody* objectOne;
  RigidBody* objectTwo;
  rune::Vec2 normalVector;
  double depth;

  collision() : objectOne(nullptr), objectTwo(nullptr), normalVector(rune::Vec2(0, 0)), depth(0)
  {

  }

};

}//namespace physics