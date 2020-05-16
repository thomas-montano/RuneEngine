#include "rigidBody.h"
#include <math.h>

/**
 * @param width Width of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param height Height of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param xPos Horizontal position of the RigidBody with respect to the center of the object.
 * @param yPos Vertical position of the RigidBody with respect to the center of the object.
 * @param mass Mass of the RigidBody to be used for physical simulations.
 * @param gravity Vertical gravity that the RigidBody should be subjected to.
 * @param rotation Whether or not the RigidBody is allowed to rotate in 2D space.
*/
RigidBody::RigidBody(int width, int height, double xPos, double yPos, double mass, double gravity, bool rotation)
{

    objectBody.vertexes[0] = rune::Vec2(-0.5*width,0.5*height); //Top left
    objectBody.vertexes[1] = rune::Vec2(0.5*width,0.5*height); //Top right
    objectBody.vertexes[2] = rune::Vec2(0.5*width,-0.5*height); //Bottom right
    objectBody.vertexes[3] = rune::Vec2(-0.5*width,-0.5*height); //Bottom left

    objectBody.xPos = xPos;
    objectBody.yPos = yPos;

    if(mass == 0)
    {
        objectBody.invMass = 0;
        objectBody.gravityFactor = 0;
    }
    else
    {
        objectBody.invMass = 1.0 / mass;
        objectBody.gravityFactor = gravity;
    }
    
    if(rotation == false)
    {
        objectBody.invInertia = 0;
    }
    else
    {
        objectBody.invInertia = 1.0 / (mass*(pow(height,2)+pow(width,2))/12);
    }

    objectBody.boundingBox.min = rune::Vec2(xPos-0.5*width,yPos-0.5*height);
    objectBody.boundingBox.max = objectBody.vertexes[1] + objectBody.boundingBox.min;

    objectBody.angleOfRotation = 0;
    objectBody.angularVelocity = 0;
    objectBody.velocity = rune::Vec2(0,0);

}

RigidBody::RigidBody()
{

}

/**
 * @param width Width of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param height Height of the rigid body in pixels, should be the same as the GameObject sprite.
 * @param xPos Horizontal position of the RigidBody with respect to the center of the object.
 * @param yPos Vertical position of the RigidBody with respect to the center of the object.
 * @param mass Mass of the RigidBody to be used for physical simulations.
 * @param gravity Vertical gravity that the RigidBody should be subjected to.
 * @param rotation Whether or not the RigidBody is allowed to rotate in 2D space.
*/
void RigidBody::setUpObject(int width, int height, double xPos, double yPos, double mass, double gravity, bool rotation)
{

    objectBody.vertexes[0] = rune::Vec2(-0.5*width,0.5*height); //Top left
    objectBody.vertexes[1] = rune::Vec2(0.5*width,0.5*height); //Top right
    objectBody.vertexes[2] = rune::Vec2(0.5*width,-0.5*height); //Bottom right
    objectBody.vertexes[3] = rune::Vec2(-0.5*width,-0.5*height); //Bottom left

    objectBody.xPos = xPos;
    objectBody.yPos = yPos;

    if(mass == 0)
    {
        objectBody.invMass = 0;
           objectBody.gravityFactor = 0;
    }
    else
    {
        objectBody.invMass = 1.0 / mass;
        objectBody.gravityFactor = gravity;
    }
    
    if(rotation == false)
    {
        objectBody.invInertia = 0;
    }
    else
    {
        objectBody.invInertia = 1.0 / (mass*(pow(height,2)+pow(width,2))/12);
    }

    /*objectBody.box.setPosition(rune::Vec2(xPos,yPos));
    objectBody.box.setSize(rune::Vec2(width,height));
    objectBody.box.setOrigin(0.5*width,0.5*height);
    objectBody.box.setFillColor(sf::Color(255,102,178,128));
    objectBody.box.setOutlineThickness(-1);
    objectBody.box.setOutlineColor(sf::Color::White);*/

    objectBody.boundingBox.min = rune::Vec2(xPos-0.5*width,yPos-0.5*height);
    objectBody.boundingBox.max = objectBody.vertexes[1] + objectBody.boundingBox.min;

    objectBody.angleOfRotation = 0;
    objectBody.angularVelocity = 0;
    objectBody.velocity = rune::Vec2(0,0);

}

/**
 * @param velocity Velocity vector to be added to the current object velocity.
*/
void RigidBody::addVelocity(rune::Vec2 velocity)
{

    objectBody.velocity.x += velocity.x;
    objectBody.velocity.y += velocity.y;

}

/**
 * @param newVel Velocity vector that will override the current object velocity.
*/
void RigidBody::setVelocity(rune::Vec2 newVel)
{
    objectBody.velocity.x = newVel.x;
    objectBody.velocity.y = newVel.y;
}

/**
 * @param dT Amount of time in seconds that has passed since the last update. Used to calculate change in position based on velocity.
*/
void RigidBody::updatePosition(double dT)
{

    objectBody.xPos += objectBody.velocity.x * dT;
    objectBody.yPos += objectBody.velocity.y * dT;
    objectBody.angleOfRotation += objectBody.angularVelocity * dT;
    updateAABB();

}

/**
 * @return A drawable sprite object (DEPRECATED).
*/
/*sf::RectangleShape RigidBody::getDrawable(void)
{
    objectBody.box.setPosition(rune::Vec2(objectBody.xPos,objectBody.yPos));
    objectBody.box.setRotation(objectBody.angleOfRotation);
    
    return objectBody.box;
}*/

/**
 * @return A drawable RectangleShape that represents the AABB (DEPRECATED).
*/
/*sf::RectangleShape RigidBody::drawAABB(void)
{

    sf::RectangleShape AABB;

    AABB.setFillColor(sf::Color::Transparent);
    AABB.setOutlineThickness(-.5);
    AABB.setOutlineColor(sf::Color::Red);
    AABB.setPosition(objectBody.boundingBox.min);

    AABB.setSize(objectBody.boundingBox.max-objectBody.boundingBox.min);
    
    return AABB;

}*/

void RigidBody::updateAABB(void)
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
 * @return The current gravity the object is being subjected to.
*/
double RigidBody::getGravity(void)
{
    return objectBody.gravityFactor;
}

/**
 * @return Get 1 divided by the mass of the RigidBody.
*/
double RigidBody::getInvMass(void)
{
    return objectBody.invMass;
}

/**
 * @return Get the restitution of the object.
*/
double RigidBody::getRestitution(void)
{
    return objectBody.restitution;
}

/**
 * @param newRest Override the restitution of the RigidBody.
*/
void RigidBody::setRestitution(double newRest)
{
    objectBody.restitution = newRest;
}

/**
 * @param angularVel Angular velocity to be added to the RigidBody.
*/
void RigidBody::addAngularVelocity(double angularVel)
{
    objectBody.angularVelocity += angularVel;
}

/**
 * @param angle New orientation for the RigidBody to be set to.
*/
void RigidBody::setRotation(double angle)
{
    objectBody.angleOfRotation = angle;
}

/**
 * @return the AABB associated with the RigidBody.
*/
AABB RigidBody::getBoundingBox(void)
{
    return objectBody.boundingBox;
}

/**
 * @param newPos Set the position of the RigidBody in world coordinates.
*/
void RigidBody::setPosition(rune::Vec2 newPos)
{
    objectBody.xPos = newPos.x;
    objectBody.yPos = newPos.y;
}

/**
 * @param newPos Position vector to be added to the object's current position.
*/
void RigidBody::addPosition(rune::Vec2 newPos)
{
    objectBody.xPos += newPos.x;
    objectBody.yPos += newPos.y;
}

/**
 * @return A vector that corresponds to the RigidBody position.
*/
rune::Vec2 RigidBody::getPosition(void)
{
    return rune::Vec2(objectBody.xPos,objectBody.yPos);
}

/**
 * @param i The index of the RigidBody vertex starting in the top left and going counter clockwise around.
 * @return The location of the vertex in world coordinates.
*/
rune::Vec2 RigidBody::getVertex(int i)
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
rune::Vec2 RigidBody::getVelocity(void)
{
    return objectBody.velocity;
}

/**
 * @return The coefficient of static friction for the RigidBody.
*/
double RigidBody::getStaticFriction(void)
{
    return objectBody.staticFriction;
}

/**
 * @return The coefficient of dynamic friction for the RigidBody.
*/
double RigidBody::getDynamicFriction(void)
{
    return objectBody.dynamicFriction;
}

/**
 * @return The current angle of the RigidBody.
*/
double RigidBody::getOrientation(void)
{
    return objectBody.angleOfRotation;
}

/**
 * @return The width in pixels of the RigidBody object.
*/
double RigidBody::getWidth(void)
{
    return 2*objectBody.vertexes[1].x;
}

/**
 * @return The height in pixels of the RigidBody object.
*/
double RigidBody::getHeight(void)
{
    return 2*objectBody.vertexes[1].y;
}

/**
 * @return 1 divided by the rotational inertia of the RigidBody.
*/
double RigidBody::getInvIntertia(void)
{
    return objectBody.invInertia;
}

/**
 * @return The position vector of the RigidBody from last frame.
*/
rune::Vec2 RigidBody::getPreviousPosition(void)
{
    return objectBody.oldPosition;
}

/**
 * @param newPos The position that the RigidBody was last frame.
*/
void RigidBody::setPreviousPosition(rune::Vec2 newPos)
{
    objectBody.oldPosition.x = newPos.x;
    objectBody.oldPosition.y = newPos.y;
}

void RigidBody::clearCollisions(void)
{
  involvedCollisions.clear();
}

/**
 * @param newCollision Collision manifold to be stored in the GameObject associated with the RigidBody.
*/
void RigidBody::addCollision(collision newCollision)
{
  involvedCollisions.push_back(newCollision);
}

/**
 * @return The collision manifolds associated with this RigidBody.
*/
std::vector<collision> RigidBody::getCollisions(void)
{
  return involvedCollisions;
}