/**
 * @brief Function file responsible for broad and narrow phase detection and collision resolution.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "rigidBody.h"
#include <math.h>

///Function call made by the game scene to have objects get updated
void updatePhysics(std::vector<RigidBody*> objects, float dT);

///Broad phase collision responsible for determining collisions based off of AABB's only.
std::vector<collision> broadPhaseCollisions(std::vector<RigidBody*> boundingBoxes);

///Narrow phase collision responsible for determining if a possible collision is actually a collision after taking rotation into accout.
std::vector<collision> narrowPhaseCollisions(std::vector<collision> boundingBoxes);

//Resolve the definite collisions in a physically realistic way
void resolveCollisions(std::vector<collision>);

//Correct the position of the object each frame so that it doesn't look like two objects are overlapping.
void positionalCorrection(RigidBody* object1, RigidBody* object2, float penetration, sf::Vector2f normal);

///Print vector function for debugging.
void printVector(sf::Vector2f vector);

///Dot product calculation of two vectors.
float dotProduct(sf::Vector2f vector1, sf::Vector2f vector2);

///Find the vector normal to a surface
sf::Vector2f findNormal(sf::Vector2f axis);

///Divides each component of a vector by the vector magnitude to make the vector magnitude equal to 1.
sf::Vector2f normalize(sf::Vector2f);

///Solve for the hypotenuse given the two sides of a triangle.
float pythagoreanSolve(float,float);

///Cross product of two vectors
float crossProduct(sf::Vector2f,sf::Vector2f);

#endif