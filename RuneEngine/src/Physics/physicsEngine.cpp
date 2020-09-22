#include "physicsEngine.h"

/**
 * @param objects An array of pointers to rigid bodies that should be considered for collision
 * @param dT The amount of time that the physics frame occupies
*/
void physics::updatePhysics(std::vector<physics::RigidBody*> objects, double dT)
{

  //Update the positions of all objects
  for(auto & object : objects)
  {
    object->updatePosition(dT);
    object->addVelocity(object->getGravity());
  }

  //Sort the objects by vertical position so the top ones are checked first
  int i,j;
  physics::RigidBody* key;
  for(i = 1; i < objects.size();i++)
  { 
    key = objects[i];
    
    j = i - 1;

    while(j >= 0 && objects[j]->getPosition().y > key->getPosition().y)
    {
      objects[j + 1] = objects[j];
      j = j - 1;
    }

    objects[j + 1] = key;

  }

  //Check for objects that may possibly be colliding
  std::vector<collision> possibleCollisions = broadPhaseCollisions(objects);

  //Remove any duplicate possible collisions
  for(int i = 0; i < possibleCollisions.size();i++)
  {
    for(int j = 0; j < possibleCollisions.size();j++)
    {
      if(possibleCollisions[i].objectOne == possibleCollisions[j].objectTwo
        && possibleCollisions[i].objectTwo == possibleCollisions[j].objectOne)
        {
          possibleCollisions.erase(possibleCollisions.begin() + j);
        }
    }
  }

  //Check to see if the objects that might be colliding are actually colliding
  std::vector<collision> definiteCollisions = narrowPhaseCollisions(possibleCollisions);

  //Now that we have all the objects that are definitely colliding
  //Resolve the collision and apply physics
  resolveCollisions(definiteCollisions);  

  for(auto & object : objects)
  {
    object->clearCollisions();
  }

  //Tell the objects about the collisions they've been involved with
  for(auto & definiteCollision : definiteCollisions)
  {
    physics::collision oppositeCollision = definiteCollision;
    oppositeCollision.normalVector *= -1;

    definiteCollision.objectOne->addCollision(oppositeCollision);
    definiteCollision.objectTwo->addCollision(definiteCollision);
  }

}

/**
 * @param boundingBoxes An array of pointers to rigid bodies that should be considered for collision.
 * @return Collision manifolds that have been found to be possibly colliding.
*/
std::vector<physics::collision> physics::broadPhaseCollisions(std::vector<RigidBody*> boundingBoxes)
{

  std::vector<collision> collisions(0); //Total collisions detected
  collision currentCollision; //collision currently being resolved
  bool objectsCollided; //Whether or not the two objects have actually collided

  //Determine whether or not two objects are colliding
  for(int i = 0; i < boundingBoxes.size(); i++)
  {

    for(int j = 0; j < boundingBoxes.size(); j++)
    {

      //If the two objects are really the same object, just skip it
      if(i == j)
      {
        continue;
      }

      AABB box1 = boundingBoxes[i]->getBoundingBox();
      AABB box2 = boundingBoxes[j]->getBoundingBox();

      //Default the collision to true
      objectsCollided = true;

      //If there is any x axis separating objects, no collision
      if(box1.max.x < box2.min.x  ||
          box1.min.x > box2.max.x )
      {
        objectsCollided = false;
      }

      //If there is any y axis separating objects, no collision
      if(box1.max.y < box2.min.y  ||
          box1.min.y > box2.max.y )
      {
        objectsCollided = false;
      }

      //If no separating axis can be found, the objects are colliding
      if(objectsCollided == true)
      {

        currentCollision.objectOne = boundingBoxes[i];
        currentCollision.objectTwo = boundingBoxes[j];

        //Generate each normal vector based on the AABB hit box
        double normal1 = std::abs(box2.min.x - box1.max.x); // Left <-1,0>
        double normal2 = std::abs(box2.max.x - box1.min.x); //Right <1,0>
        double normal3 = std::abs(box2.min.y - box1.max.y); //Up <0,1>
        double normal4 = std::abs(box2.max.y - box1.min.y); //Down <0,-1>

        //Determine the minimum axis of penetration
        double xNormal = normal1 < normal2 ? normal1 : normal2;
        double yNormal = normal3 < normal4 ? normal3 : normal4;

        //Assign the appropriate normal vector based on the axis of least penetration
        if(xNormal < yNormal)
        {
          currentCollision.depth = std::abs(xNormal);
          currentCollision.normalVector = normal1 < normal2 ? rune::Vec2(-1,0):rune::Vec2(1,0);
        }
        else if(xNormal > yNormal)
        {
          currentCollision.depth = std::abs(yNormal);
          currentCollision.normalVector = normal3 < normal4 ? rune::Vec2(0,1):rune::Vec2(0,-1);
        }
        //Default to a zero vector normal
        else
        {
          currentCollision.normalVector = rune::Vec2(0,0);
        }

        //Add the resolved collision to the collision vector
        collisions.push_back(currentCollision);

      }

    }

  }

  return collisions;
}

/**
 * @param possibleCollisions Collision manifolds for AABB's that were found to be colliding
 * @return Collision manifolds that have been found to be definitely colliding.
*/
std::vector<physics::collision> physics::narrowPhaseCollisions(std::vector<collision> possibleCollisions)
{

  std::vector<collision> definiteCollisions(0);
  
  
  //Run through all possible collisions
  for(auto & possibleCollision : possibleCollisions)
  {
    collision currentCollision;
    rune::Vec2 normals[4];
    double penetrations[4] = {0.0};

    RigidBody& object1 = *possibleCollision.objectOne;
    RigidBody& object2 = *possibleCollision.objectTwo;
    
    //Min and max projections of the boxes
    double minProjBox1;
    double maxProjBox1;
    double minProjBox2;
    double maxProjBox2;

    //Axis P
    normals[0] = rune::findNormal(rune::Vec2(object1.getVertex(1)-object1.getVertex(0)));

    //Axis Q
    normals[1] = rune::findNormal(rune::Vec2(object1.getVertex(2)-object1.getVertex(1)));

    //Axis R
    normals[2] = rune::findNormal(rune::Vec2(object2.getVertex(1)-object2.getVertex(0)));
    
    //Axis S
    normals[3] = rune::findNormal(rune::Vec2(object2.getVertex(2)-object2.getVertex(1)));

    //One boolean for each of the four axes
    bool axisSeperation[4] = {false};

    //Go through all of the axes
    for(int j = 0; j < 4; j++)
    {

      //Default the min and max to be the first projection
      minProjBox1 = maxProjBox1 = rune::dotProduct(object1.getVertex(0),normals[j]);
      minProjBox2 = maxProjBox2 = rune::dotProduct(object2.getVertex(0),normals[j]);

      //Find the max and min point for each vertex on the current axis
      for(int k = 0; k < 4; k++)
      { 

        if(rune::dotProduct(object1.getVertex(k),normals[j]) < minProjBox1)
        {
          minProjBox1 = rune::dotProduct(object1.getVertex(k),normals[j]);
        }

        if(rune::dotProduct(object1.getVertex(k),normals[j]) > maxProjBox1)
        {
          maxProjBox1 = rune::dotProduct(object1.getVertex(k),normals[j]);
        }

        if(rune::dotProduct(object2.getVertex(k),normals[j]) < minProjBox2)
        {
          minProjBox2 = rune::dotProduct(object2.getVertex(k),normals[j]);
        }

        if(rune::dotProduct(object2.getVertex(k),normals[j]) > maxProjBox2)
        {
          maxProjBox2 = rune::dotProduct(object2.getVertex(k),normals[j]);
        }

      }

      //Determine if there is a separation on the current axis
      if(minProjBox2 > maxProjBox1 || minProjBox1 > maxProjBox2)
      {
        axisSeperation[j] = true;
      }
      else
      {
        penetrations[j] = std::min(std::abs(minProjBox1 - maxProjBox2),std::abs(minProjBox2 - maxProjBox1));
      }

      //Find the penetration depth and normal
      if(j==0)
      {
        currentCollision.depth = penetrations[0];
      }

      if(penetrations[j] <= currentCollision.depth)
      {
        currentCollision.depth = penetrations[j];
        currentCollision.normalVector = std::abs(minProjBox1 - maxProjBox2) < std::abs(minProjBox2 - maxProjBox1) ? rune::Vec2(normals[j].x,normals[j].y):rune::Vec2(-1.0*normals[j].x, -1.0*normals[j].y);
      }

    }
    
    //Check to see if the two objects are oriented similarly
    //If they are, its a face to face collision
    //Otherwise, its a vertex to face collision
    /*if(std::abs(static_cast<int>(object1.getOrientation())%90 - static_cast<int>(object2.getOrientation())%90) < 1)
    {
      currentCollision.contactVectorBox1 = rune::Vec2(-1*(object2.getPosition().x - object1.getPosition().x + (0.5*object1.getHeight()*currentCollision.normalVector.x)), object2.getPosition().y - object1.getPosition().y - (0.5*object1.getHeight()*currentCollision.normalVector.y));
      currentCollision.contactVectorBox2 = currentCollision.contactVectorBox1;
    }
    else
    {
      currentCollision.contactVectorBox1 = currentCollision.contactVectorBox1;
      currentCollision.contactVectorBox2 = currentCollision.contactVectorBox1;
    }*/
    
    //If there was an overlap, exit loop and resolve collision
      if(!axisSeperation[0] && 
        !axisSeperation[1] && 
        !axisSeperation[2] &&
        !axisSeperation[3])
      {
        //Add the current objects to the current collision
        currentCollision.objectOne = possibleCollision.objectOne;
        currentCollision.objectTwo = possibleCollision.objectTwo;

        //Add the current collision to the list of definite collisions
        definiteCollisions.push_back(currentCollision);

      }

  }

  return definiteCollisions;

}

/**
 * @param collisions Collision manifolds for OBB's that were found to be definitely colliding. 
*/
void physics::resolveCollisions(std::vector<physics::collision> collisions)
{

  for(auto & collision : collisions)
  {

    RigidBody* object1 = collision.objectOne;
    RigidBody* object2 = collision.objectTwo;

    rune::Vec2 relativeV = rune::Vec2(object2->getVelocity().x - object1->getVelocity().x, object2->getVelocity().y - object1->getVelocity().y);
    rune::Vec2 tangent = rune::Vec2(relativeV.x - rune::dotProduct(relativeV,collision.normalVector) * collision.normalVector.x, relativeV.y - dotProduct(relativeV,collision.normalVector) * collision.normalVector.y);
    
    tangent = rune::normalize(tangent);

    double velAlongNormal = rune::dotProduct(relativeV, collision.normalVector);

    if(velAlongNormal > 0)
    {

      //Move the objects out of each other
      positionalCorrection(object1,object2,collision.depth, collision.normalVector);

      double e = std::max(object1->getRestitution(),object2->getRestitution()); // Restitution factor

      double j = -(1 + e) * velAlongNormal;
      double jt = -1* rune::dotProduct(relativeV,tangent);

      jt /= object1->getInvMass() + object2->getInvMass();
      j /= (object1->getInvMass() + object2->getInvMass());

      double mu = pythagoreanSolve(object1->getStaticFriction(),object2->getStaticFriction());

      //Apply friction force
      rune::Vec2 frictionImpulse;
      if(std::abs(jt) < j * mu)
      {
        frictionImpulse = rune::Vec2(jt*tangent.x, jt * tangent.y);
      }
      else
      {
        double dynamicFriction = pythagoreanSolve(object1->getDynamicFriction(),object2->getDynamicFriction());

        frictionImpulse = rune::Vec2(jt*tangent.x*dynamicFriction, jt * tangent.y*dynamicFriction);
      }
      
      //HandleFriction
      object1->addVelocity(rune::Vec2(-1*object1->getInvMass()*frictionImpulse.x,-1*object1->getInvMass()*frictionImpulse.y));
      object2->addVelocity(rune::Vec2(object2->getInvMass()*frictionImpulse.x,object2->getInvMass()*frictionImpulse.y));

      //Push objects away from each other
      rune::Vec2 impulse = rune::Vec2(j * collision.normalVector.x, j * collision.normalVector.y);
      object1->addVelocity(rune::Vec2(-1*object1->getInvMass()*impulse.x,-1*object1->getInvMass()*impulse.y));
      object2->addVelocity(rune::Vec2(object2->getInvMass()*impulse.x,object2->getInvMass()*impulse.y));

      /*
      //Handle rotation
      double jr = -(1 + e)*rune::dotProduct(relativeV,tangent);
      jr /= object1->getInvMass() + object2->getInvMass() + pow(crossProduct(collisions[i].contactVectorBox1,tangent),2)*object1->getInvIntertia() + pow(crossProduct(collisions[i].contactVectorBox2,tangent),2)*object2->getInvIntertia();
      impulse = rune::Vec2(jr * collisions[i].normalVector.x, jr * collisions[i].normalVector.y);

      collisions[i].objectOne->addAngularVelocity(-1*crossProduct(collisions[i].contactVectorBox1,impulse));
      collisions[i].objectTwo->addAngularVelocity(-1*crossProduct(collisions[i].contactVectorBox2,impulse));*/

    }
  }
}

/**
 * @param object1 The first object in the collision.
 * @param object2 The seconds object in the collision.
 * @param normal The normal vector for the collision. 
*/
void physics::positionalCorrection(RigidBody* object1, RigidBody* object2, double depth, rune::Vec2 normal)
{

  const double percent = .8; // usually 20% to 80%
  const double slop = 0.01; // usually 0.01 to 0.1

  double correctionFactor = (std::max( depth - slop, 0.00 ) / (object1->getInvMass() + object2->getInvMass())) * percent;

  rune::Vec2 correction = rune::Vec2(normal.x*correctionFactor,normal.y*correctionFactor);
  object1->addPosition(rune::Vec2(object1->getInvMass() * correction.x,object1->getInvMass() * correction.y));
  object2->addPosition(rune::Vec2(-1*object2->getInvMass() * correction.x,-1*object2->getInvMass() * correction.y));

}

/**
 * @param a First side of the triangle.
 * @param b Seconds side of the triangle.
 * @return The length of the hypotenuse. 
*/
double physics::pythagoreanSolve(double a, double b)
{
  return sqrt(pow(a,2) + pow(b,2));
}
