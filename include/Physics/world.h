/**
 * @class physics::World
 * @brief A physics world that contains all the information needed to run physics
 *
 * @author Thomas Montano
 * @date July 21 2020
*/

#pragma once

#include <core.h>
#include <cmath>
#include <vector>
#include <Physics\rigidBody.h>
#include <Math\vec2.h>
#include <math.h>
#include <algorithm>
#include <DataStructures/list.h>
#include <Events/clock.h>

namespace physics{

class RUNE_ENGINE World
{
private:

  rune::List<RigidBody*> physicsBodies;

  double dT, accumulator, frameStart;

  rune::Clock variableClock;

public:
  ///Default empty constructor for a new physics world.
  World();
  ///Integrates the world over the next timestep.
  void step(void);
  ///Function call made by the game scene to have objects get updated
  void updatePhysics(rune::List<physics::RigidBody*>& objects, double dT);
  ///Broad phase collision responsible for determining collisions based off of AABB's only.
  /// @param boundingBoxes The physics::AABB list to be sorted through for possible collisions
  rune::List<physics::collision> broadPhaseCollisions(rune::List<physics::RigidBody*>& boundingBoxes);
  ///Narrow phase collision responsible for determining if a possible collision is actually a collision after taking rotation into account.
  /// @param boundingBoxes The collision manifolds that have a possible collisions.
  rune::List<physics::collision> narrowPhaseCollisions(rune::List<physics::collision>& boundingBoxes);
  ///Resolve the definite collisions in a physically realistic way
  /// @param currentCollision The collision that is currently waiting to be resolved.
  void resolveCollisions(rune::List<physics::collision>& currentCollision);
  ///Correct the position of the object each frame so that it doesn't look like two objects are overlapping.
  void positionalCorrection(physics::RigidBody* object1, physics::RigidBody* object2, double penetration, rune::Vec2 normal);
  ///Solve for the hypotenuse given the two sides of a triangle.
  double pythagoreanSolve(double a, double b);


};

}//namespace physics

