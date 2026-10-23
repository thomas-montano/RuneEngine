/**
 * @file physicsEngine.h
 * @brief The physics module responsible for handling and resolving collisions between rune::RigidBody components.
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

namespace rune{

///Function call made by the game scene to have objects get updated.
void updatePhysics(std::vector<rune::RigidBody*> objects, double dT);
///Broad phase collision responsible for determining collisions based off of AABB's only.
std::vector<rune::collision> broadPhaseCollisions(std::vector<rune::RigidBody*> boundingBoxes);
///Narrow phase collision responsible for determining if a possible collision is actually a collision after taking rotation into account.
std::vector<rune::collision> narrowPhaseCollisions(std::vector<rune::collision> possibleCollisions);
///Resolve the definite collisions in a physically realistic way.
void resolveCollisions(std::vector<rune::collision> currentCollision);
///Correct the position of the object each frame so that it doesn't look like two objects are overlapping.
void positionalCorrection(rune::RigidBody* object1, rune::RigidBody* object2, double penetration, rune::Vec2 normal);
///Solve for the hypotenuse given the two sides of a triangle.
double pythagoreanSolve(double a, double b);

}

#endif