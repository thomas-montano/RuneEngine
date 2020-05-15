/**
 * @brief Function file responsible for broad and narrow phase detection and collision resolution.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <cmath>
#include <vector>
#include <iostream>
#include <Physics\rigidBody.h>
#include <Math\vec2.h>
#include <math.h>
#include <algorithm>

///Function call made by the game scene to have objects get updated
void updatePhysics(std::vector<RigidBody*> objects, double dT);

///Broad phase collision responsible for determining collisions based off of AABB's only.
std::vector<collision> broadPhaseCollisions(std::vector<RigidBody*> boundingBoxes);

///Narrow phase collision responsible for determining if a possible collision is actually a collision after taking rotation into accout.
std::vector<collision> narrowPhaseCollisions(std::vector<collision> boundingBoxes);

//Resolve the definite collisions in a physically realistic way
void resolveCollisions(std::vector<collision>);

//Correct the position of the object each frame so that it doesn't look like two objects are overlapping.
void positionalCorrection(RigidBody* object1, RigidBody* object2, double penetration, Vec2 normal);

///Solve for the hypotenuse given the two sides of a triangle.
double pythagoreanSolve(double,double);

#endif