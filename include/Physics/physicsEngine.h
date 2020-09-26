/**
 * @namespace physics
 * @brief The physics module responsible for handling and resolving collisions between physics::Collider2D.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <cmath>
#include <vector>
#include <Physics\rigidBody.h>
#include <Math\vec2.h>
#include <math.h>
#include <algorithm>

namespace physics{

///Function call made by the game scene to have objects get updated
/// @param objects The RigidBodies to be simulated.
/// @param dT The amount of time in seconds since the last physics call.
void updatePhysics(std::vector<physics::RigidBody*> objects, double dT);

///Broad phase collision responsible for determining collisions based off of AABB's only.
/// @param boundingBoxes The physics::AABB list to be sorted through for possible collisions
std::vector<physics::collision> broadPhaseCollisions(std::vector<physics::RigidBody*> boundingBoxes);

///Narrow phase collision responsible for determining if a possible collision is actually a collision after taking rotation into account.
/// @param boundingBoxes The collision manifolds that have a possible collisions.
std::vector<physics::collision> narrowPhaseCollisions(std::vector<physics::collision> boundingBoxes);

///Resolve the definite collisions in a physically realistic way
/// @param currentCollision The collision that is currently waiting to be resolved.
void resolveCollisions(std::vector<physics::collision> currentCollision);

///Correct the position of the object each frame so that it doesn't look like two objects are overlapping.
/// @param object1 The first object involved in the collision.
/// @param object2 The second object involved in the collision.
/// @param penetration The penetration depth in world coordinates.
/// @param normal The vector normal to the collision.
void positionalCorrection(physics::RigidBody* object1, physics::RigidBody* object2, double penetration, rune::Vec2 normal);

///Solve for the hypotenuse given the two sides of a triangle.
/// @param a The first side of the triangle.
/// @param b The second side of the triangle.
double pythagoreanSolve(double a, double b);

}

#endif