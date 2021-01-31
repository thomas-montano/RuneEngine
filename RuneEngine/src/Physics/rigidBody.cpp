#include "rigidBody.h"
#include <Renderer/sprite.h>
#include <math.h>
#include "gameApplication.h"

/**
 * \param mass The mass in units that the RigidBody will have.
 * \param gravity The gravity vector that this RigidBody will be subjected to.
 */
physics::RigidBody::RigidBody(double mass /*= 0*/, rune::Vec2 gravity /*= rune::Vec2(0,0)*/)
{

  if ((int)mass == 0)
  {
    objectBody.invMass = 0;
    objectBody.gravityFactor = 0;
  }
  else
  {
    objectBody.invMass = 1.0 / mass;
    objectBody.gravityFactor = gravity;
  }

  objectBody.restitution = 0.0;
  objectBody.staticFriction = 0.4;
  objectBody.dynamicFriction = 0.2;

  objectBody.angleOfRotation = 0;
  objectBody.angularVelocity = 0;
  objectBody.velocity = rune::Vec2(0, 0);

}

void physics::RigidBody::start()
{
  //This is very temporary and needs to be handled better eventually!
  rune::Vec3 dimensions = rune::Vec3(parentObject->transform.getBounds());//parentObject->transform.getScale();

  setUpObject(dimensions.x,dimensions.y,1.0/objectBody.invMass,false);

  //getGameInstance()->getCurrentScene()->addPhysicsObject(*this);
}


/**
 * @param width Width of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param height Height of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param mass Mass of the RigidBody to be used for physical simulations.
 * @param rotation Whether or not the RigidBody is allowed to rotate in 2D space.
*/
void physics::RigidBody::setUpObject(int width, int height, double mass, bool rotation)
{

    objectBody.vertexes[0] = rune::Vec2(-0.5*width,0.5*height); //Top left
    objectBody.vertexes[1] = rune::Vec2(0.5*width,0.5*height); //Top right
    objectBody.vertexes[2] = rune::Vec2(0.5*width,-0.5*height); //Bottom right
    objectBody.vertexes[3] = rune::Vec2(-0.5*width,-0.5*height); //Bottom left

    objectBody.xPos = parentObject->transform.getPosition().x + 0.5 * width;
    objectBody.yPos = parentObject->transform.getPosition().y + 0.5 * height;
    
    if (rotation == false)
    {
      objectBody.invInertia = 0;
    }
    else
    {
      objectBody.invInertia = 1.0 / (mass * (pow(height, 2) + pow(width, 2)) / 12);
    }

    objectBody.boundingBox.min = rune::Vec2(objectBody.xPos-0.5*width,objectBody.yPos-0.5*height);
    objectBody.boundingBox.max = objectBody.vertexes[1] + objectBody.boundingBox.min;

}

/**
 * @param velocity Velocity vector to be added to the current object velocity.
*/
void physics::RigidBody::addVelocity(rune::Vec2 velocity)
{

    objectBody.velocity.x += velocity.x;
    objectBody.velocity.y += velocity.y;

}

/**
 * @param newVel Velocity vector that will override the current object velocity.
*/
void physics::RigidBody::setVelocity(rune::Vec2 newVel)
{
    objectBody.velocity.x = newVel.x;
    objectBody.velocity.y = newVel.y;
}

/**
 * @param dT Amount of time in seconds that has passed since the last update. Used to calculate change in position based on velocity.
*/
void physics::RigidBody::updatePosition(double dT)
{

    objectBody.xPos += objectBody.velocity.x * dT;
    objectBody.yPos += objectBody.velocity.y * dT;
    objectBody.angleOfRotation += objectBody.angularVelocity * dT;
    updateAABB();

}

/**
 * \param alpha linear interpolation factor.
 */
void physics::RigidBody::interpolatePosition(double alpha)
{

  rune::Vec2 oldPosition = objectBody.oldPosition;
  rune::Vec2 currentPos = rune::Vec2(objectBody.xPos, objectBody.yPos) - rune::Vec2(objectBody.vertexes[1].x, objectBody.vertexes[1].y);

  rune::Vec2 newPos = rune::Vec2(oldPosition.x * alpha, oldPosition.y * alpha) + rune::Vec2(currentPos.x * (1.0 - alpha), currentPos.y * (1.0 - alpha));

  parentObject->transform.setPosition(rune::Vec3(newPos));

  objectBody.angleOfRotation= parentObject->transform.getRotation().z;

  objectBody.oldPosition = currentPos;

}

void physics::RigidBody::updateAABB(void)
{

    double rotation = std::abs(static_cast<int>(objectBody.angleOfRotation)) % 180;
    double width = 2*objectBody.vertexes[1].x;
    double height = 2*objectBody.vertexes[1].y;

    double xProjection;
    double yProjection;

    if(rotation < 90)
    {
        xProjection = height*cos((90-rotation)*(3.14/180)) + width*cos((rotation)*(3.14/180));
        yProjection = height*cos((rotation)*(3.14/180)) + width*cos((90-rotation)*(3.14/180));
    }
    else
    {
        xProjection = height*-cos((90+rotation)*(3.14/180)) + width*-cos((rotation)*(3.14/180));
        yProjection = height*-cos((rotation)*(3.14/180)) + width*-cos((90+rotation)*(3.14/180));
    }
    
    objectBody.boundingBox.min = rune::Vec2(objectBody.xPos - 0.5*xProjection,objectBody.yPos-0.5*yProjection);
    objectBody.boundingBox.max = rune::Vec2(objectBody.xPos + 0.5*xProjection,objectBody.yPos+0.5*yProjection);

}

/**
 * \param newMass The new mass of the object.
 */
void physics::RigidBody::setMass(float newMass)
{
  objectBody.invMass = (int)newMass == 0 ? 0 : (1.0 / newMass);
}

/**
 * @return The current gravity the object is being subjected to.
*/
rune::Vec2 physics::RigidBody::getGravity(void)
{
    return objectBody.gravityFactor;
}

/**
 * @return Get 1 divided by the mass of the RigidBody.
*/
double physics::RigidBody::getInvMass(void)
{
    return objectBody.invMass;
}

/**
 * @return Get the restitution of the object.
*/
double physics::RigidBody::getRestitution(void)
{
    return objectBody.restitution;
}

/**
 * @param newRest Override the restitution of the RigidBody.
*/
void physics::RigidBody::setRestitution(double newRest)
{
    objectBody.restitution = newRest > 1.0 ? 1.0:newRest;
}

/**
 * @param angularVel Angular velocity to be added to the RigidBody.
*/
void physics::RigidBody::addAngularVelocity(double angularVel)
{
    objectBody.angularVelocity += angularVel;
}

/**
 * @param angle New orientation for the RigidBody to be set to.
*/
void physics::RigidBody::setRotation(double angle)
{
    objectBody.angleOfRotation = angle;
}

/**
 * @return the AABB associated with the RigidBody.
*/
physics::AABB physics::RigidBody::getBoundingBox(void)
{
    return objectBody.boundingBox;
}

/**
 * @param newPos Set the position of the RigidBody in world coordinates.
*/
void physics::RigidBody::setPosition(rune::Vec2 newPos)
{
    objectBody.xPos = newPos.x;
    objectBody.yPos = newPos.y;
}

/**
 * @param newPos Position vector to be added to the object's current position.
*/
void physics::RigidBody::addPosition(rune::Vec2 newPos)
{
    objectBody.xPos += newPos.x;
    objectBody.yPos += newPos.y;
}

/**
 * @return A vector that corresponds to the RigidBody position.
*/
rune::Vec2 physics::RigidBody::getPosition(void)
{
    return rune::Vec2(objectBody.xPos,objectBody.yPos);
}

/**
 * @param i The index of the RigidBody vertex starting in the top left and going counter clockwise around.
 * @return The location of the vertex in world coordinates.
*/
rune::Vec2 physics::RigidBody::getVertex(int i)
{
    double xPrime, yPrime;
    double x = objectBody.vertexes[i].x;
    double y = objectBody.vertexes[i].y;
    double angle = objectBody.angleOfRotation * (3.14/180);

    rune::Vec2 finalVertex;

    xPrime = x * cos(angle) - y * sin(angle);
    yPrime = x * sin(angle) + y * cos(angle);


    finalVertex = rune::Vec2(xPrime,yPrime) + rune::Vec2(objectBody.xPos,objectBody.yPos);

    return finalVertex;
}

/**
 * @return The velocity vector of the RigidBody.
*/
rune::Vec2 physics::RigidBody::getVelocity(void)
{
    return objectBody.velocity;
}

/**
 * @return The coefficient of static friction for the RigidBody.
*/
double physics::RigidBody::getStaticFriction(void)
{
    return objectBody.staticFriction;
}

void physics::RigidBody::setStaticFriction(float friction)
{
  objectBody.staticFriction = friction;
}

/**
 * @return The coefficient of dynamic friction for the RigidBody.
*/
double physics::RigidBody::getDynamicFriction(void)
{
    return objectBody.dynamicFriction;
}

void physics::RigidBody::setDynamicFriction(float friction)
{
  objectBody.dynamicFriction = friction;
}

/**
 * @return The current angle of the RigidBody.
*/
double physics::RigidBody::getOrientation(void)
{
    return objectBody.angleOfRotation;
}

/**
 * @return The width in pixels of the RigidBody object.
*/
double physics::RigidBody::getWidth(void)
{
    return 2*objectBody.vertexes[1].x;
}

/**
 * @return The height in pixels of the RigidBody object.
*/
double physics::RigidBody::getHeight(void)
{
    return 2*objectBody.vertexes[1].y;
}

/**
 * @return 1 divided by the rotational inertia of the RigidBody.
*/
double physics::RigidBody::getInvIntertia(void)
{
    return objectBody.invInertia;
}

/**
 * @return The position vector of the RigidBody from last frame.
*/
rune::Vec2 physics::RigidBody::getPreviousPosition(void)
{
    return objectBody.oldPosition;
}

/**
 * @param newPos The position that the RigidBody was last frame.
*/
void physics::RigidBody::setPreviousPosition(rune::Vec2 newPos)
{
    objectBody.oldPosition.x = newPos.x;
    objectBody.oldPosition.y = newPos.y;
}

void physics::RigidBody::clearCollisions(void)
{
  involvedCollisions.clear();
}

/**
 * @param newCollision Collision manifold to be stored in the GameObject associated with the RigidBody.
*/
void physics::RigidBody::addCollision(collision newCollision)
{
  involvedCollisions.push_back(newCollision);
}

/**
 * @return The collision manifolds associated with this RigidBody.
*/
std::vector<physics::collision> physics::RigidBody::getCollisions(void)
{
  return involvedCollisions;
}

/**
 * \return A pointer to the RigidBody data struct.
 */
physics::body* physics::RigidBody::getBodyStruct(void)
{
  return &objectBody;
}
