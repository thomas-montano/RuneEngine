#include "world.h"
#include <gameApplication.h>

physics::World::World()
  : accumulator(0), dT(getGameInstance()->getDeltaTime()), frameStart(0)
{
  variableClock.reset();
}

void physics::World::step(void)
{

  double currentTime = variableClock.getElapsedTimeAsMilliseconds() / 1000.0;

  accumulator += currentTime - frameStart;
  frameStart = currentTime;

  if (accumulator > 0.2)
  {
    accumulator = 0.2;
  }

  //Deal with physics updates
  while (accumulator > dT)
  {
    updatePhysics(physicsBodies, dT);

    accumulator -= dT;
  }

  const double alpha = accumulator / dT;

  //Update position for every object in every layer

  for (int j = 0; j < physicsBodies.size(); j++)
  {
    physicsBodies[j]->interpolatePosition(alpha);
  }

}

/**
 * @param objects An array of pointers to rigid bodies that should be considered for collision
 * @param dT The amount of time that the physics frame occupies
*/
void physics::World::updatePhysics(rune::List<physics::RigidBody*>& objects, double dT)
{

  //Update the positions of all objects
  for (RigidBody** object = objects.getList(); object != nullptr; object = objects.getNext())
  {
    (*object)->updatePosition(dT);
    (*object)->addVelocity((*object)->getGravity());
  }

  //Sort the objects by vertical position so the top ones are checked first
  int i, j;
  physics::RigidBody* key;
  for (i = 1; i < objects.size(); i++)
  {
    key = objects[i];

    j = i - 1;

    while (j >= 0 && objects[j]->getPosition().y > key->getPosition().y)
    {
      objects[j + 1] = objects[j];
      j = j - 1;
    }

    objects[j + 1] = key;

  }

  //Check for objects that may possibly be colliding
  rune::List<collision> possibleCollisions = broadPhaseCollisions(objects);

  //Remove any duplicate possible collisions
  for (int i = 0; i < possibleCollisions.size(); i++)
  {
    for (int j = 0; j < possibleCollisions.size(); j++)
    {
      if (possibleCollisions[i].objectOne == possibleCollisions[j].objectTwo
        && possibleCollisions[i].objectTwo == possibleCollisions[j].objectOne)
      {
        possibleCollisions.remove(j);
      }
    }
  }

  //Check to see if the objects that might be colliding are actually colliding
  rune::List<collision> definiteCollisions = narrowPhaseCollisions(possibleCollisions);

  //Now that we have all the objects that are definitely colliding
  //Resolve the collision and apply physics
  resolveCollisions(definiteCollisions);

  for (RigidBody** object = objects.getList(); object != nullptr; object = objects.getNext())
  {
    (*object)->clearCollisions();
  }

  //Tell the objects about the collisions they've been involved with
  for (collision* definiteCollision = definiteCollisions.getList(); definiteCollision != nullptr; definiteCollision = definiteCollisions.getNext())
  {
    physics::collision oppositeCollision = *definiteCollision;
    oppositeCollision.normalVector *= -1;

    definiteCollision->objectOne->addCollision(oppositeCollision);
    definiteCollision->objectTwo->addCollision(*definiteCollision);
  }

}

rune::List<physics::collision> physics::World::broadPhaseCollisions(rune::List<physics::RigidBody*>& boundingBoxes)
{
  rune::List<physics::collision> temp;

  return temp;

}

rune::List<physics::collision> physics::World::narrowPhaseCollisions(rune::List<physics::collision>& boundingBoxes)
{

  rune::List<physics::collision> temp;

  return temp;

}

void physics::World::resolveCollisions(rune::List<physics::collision>& currentCollision)
{

}

/**
 * @param object1 The first object in the collision.
 * @param object2 The seconds object in the collision.
 * @param normal The normal vector for the collision.
*/
void physics::World::positionalCorrection(RigidBody* object1, RigidBody* object2, double depth, rune::Vec2 normal)
{

  const double percent = .8; // usually 20% to 80%
  const double slop = 0.01; // usually 0.01 to 0.1

  double correctionFactor = (std::max(depth - slop, 0.00) / (object1->getInvMass() + object2->getInvMass())) * percent;

  rune::Vec2 correction = rune::Vec2(normal.x * correctionFactor, normal.y * correctionFactor);
  object1->addPosition(rune::Vec2(object1->getInvMass() * correction.x, object1->getInvMass() * correction.y));
  object2->addPosition(rune::Vec2(-1 * object2->getInvMass() * correction.x, -1 * object2->getInvMass() * correction.y));

}

/**
 * @param a First side of the triangle.
 * @param b Seconds side of the triangle.
 * @return The length of the hypotenuse.
*/
double physics::World::pythagoreanSolve(double a, double b)
{
  return sqrt(pow(a, 2) + pow(b, 2));
}
