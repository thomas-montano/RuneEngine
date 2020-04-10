#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "rigidBody.h"
#include <math.h>
#include <algorithm>

struct collision
{

    RigidBody* objectOne;
    RigidBody* objectTwo;
    sf::Vector2f normalVector;
    sf::Vector2f contactVectorBox1;
    sf::Vector2f contactVectorBox2;
    float depth;

};

void updatePhysics(std::vector<RigidBody*> objects, float dT);
std::vector<collision> broadPhaseCollisions(std::vector<RigidBody*> boundingBoxes);
std::vector<collision> narrowPhaseCollisions(std::vector<collision> boundingBoxes);
void resolveCollisions(std::vector<collision>);
void positionalCorrection(RigidBody* object1, RigidBody* object2, float penetration, sf::Vector2f normal);

void printVector(sf::Vector2f vector);
float dotProduct(sf::Vector2f vector1, sf::Vector2f vector2);
sf::Vector2f findNormal(sf::Vector2f axis);
RigidBody getRaycast(RigidBody* rigidBodies, float dT);
sf::Vector2f normalize(sf::Vector2f);

float pythagoreanSolve(float,float);
float crossProduct(sf::Vector2f,sf::Vector2f);
sf::Vector2f crossProduct(float,sf::Vector2f);
sf::Vector2f crossProduct(sf::Vector2f,float);

#endif