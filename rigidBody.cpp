#include "rigidBody.h"
#include "math.h"
#include <iostream>

RigidBody::RigidBody(int width, int height, float xPos, float yPos, float mass, float gravity, bool rotation)
{

    objectBody.vertexes[0] = sf::Vector2f(-0.5*width,0.5*height); //Top left
    objectBody.vertexes[1] = sf::Vector2f(0.5*width,0.5*height); //Top right
    objectBody.vertexes[2] = sf::Vector2f(0.5*width,-0.5*height); //Bottom right
    objectBody.vertexes[3] = sf::Vector2f(-0.5*width,-0.5*height); //Bottom left

    objectBody.xPos = xPos;
    objectBody.yPos = yPos;

    if(mass == 0)
    {
        objectBody.invMass = 0;
    }
    else
    {
        objectBody.invMass = 1.0 / mass;
    }
    
    if(rotation == false)
    {
        objectBody.invInertia = 0;
    }
    else
    {
        objectBody.invInertia = 1.0 / (mass*(pow(height,2)+pow(width,2))/12);
    }

    objectBody.gravityFactor = gravity;

    objectBody.box.setPosition(sf::Vector2f(xPos,yPos));
    objectBody.box.setSize(sf::Vector2f(width,height));
    objectBody.box.setOrigin(0.5*width,0.5*height);
    objectBody.box.setFillColor(sf::Color(255,102,178,128));
    objectBody.box.setOutlineThickness(-1);
    objectBody.box.setOutlineColor(sf::Color::White);

    objectBody.boundingBox.min = sf::Vector2f(xPos-0.5*width,yPos-0.5*height);
    objectBody.boundingBox.max = objectBody.vertexes[1] + objectBody.boundingBox.min;

    objectBody.angleOfRotation = 0;
    objectBody.angularVelocity = 0;
    objectBody.velocity = sf::Vector2f(0,0);

}

RigidBody::RigidBody()
{

}

void RigidBody::setUpObject(int width, int height, float xPos, float yPos, float mass, float gravity, bool rotation)
{

    objectBody.vertexes[0] = sf::Vector2f(-0.5*width,0.5*height); //Top left
    objectBody.vertexes[1] = sf::Vector2f(0.5*width,0.5*height); //Top right
    objectBody.vertexes[2] = sf::Vector2f(0.5*width,-0.5*height); //Bottom right
    objectBody.vertexes[3] = sf::Vector2f(-0.5*width,-0.5*height); //Bottom left

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

    objectBody.box.setPosition(sf::Vector2f(xPos,yPos));
    objectBody.box.setSize(sf::Vector2f(width,height));
    objectBody.box.setOrigin(0.5*width,0.5*height);
    objectBody.box.setFillColor(sf::Color(255,102,178,128));
    objectBody.box.setOutlineThickness(-1);
    objectBody.box.setOutlineColor(sf::Color::White);

    objectBody.boundingBox.min = sf::Vector2f(xPos-0.5*width,yPos-0.5*height);
    objectBody.boundingBox.max = objectBody.vertexes[1] + objectBody.boundingBox.min;

    objectBody.angleOfRotation = 0;
    objectBody.angularVelocity = 0;
    objectBody.velocity = sf::Vector2f(0,0);

}

void RigidBody::addVelocity(sf::Vector2f velocity)
{

    objectBody.velocity.x += velocity.x;
    objectBody.velocity.y += velocity.y;

}

void RigidBody::setVelocity(sf::Vector2f newVel)
{
    objectBody.velocity.x = newVel.x;
    objectBody.velocity.y = newVel.y;
}

void RigidBody::updatePosition(float dT)
{

    objectBody.xPos += objectBody.velocity.x * dT;
    objectBody.yPos -= objectBody.velocity.y * dT;
    objectBody.angleOfRotation += objectBody.angularVelocity * dT;
    updateAABB();

}

sf::RectangleShape RigidBody::getDrawable(void)
{
    objectBody.box.setPosition(sf::Vector2f(objectBody.xPos,objectBody.yPos));
    objectBody.box.setRotation(objectBody.angleOfRotation);
    
    return objectBody.box;
}

sf::RectangleShape RigidBody::drawAABB(void)
{

    sf::RectangleShape AABB;

    AABB.setFillColor(sf::Color::Transparent);
    AABB.setOutlineThickness(-.5);
    AABB.setOutlineColor(sf::Color::Red);
    AABB.setPosition(objectBody.boundingBox.min);

    AABB.setSize(objectBody.boundingBox.max-objectBody.boundingBox.min);
    
    return AABB;

}

void RigidBody::updateAABB(void)
{

    float rotation = std::abs(static_cast<int>(objectBody.angleOfRotation)) % 180;
    float width = 2*objectBody.vertexes[1].x;
    float height = 2*objectBody.vertexes[1].y;

    float xProjection;
    float yProjection;

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
    
    objectBody.boundingBox.min = sf::Vector2f(objectBody.xPos - 0.5*xProjection,objectBody.yPos-0.5*yProjection);
    objectBody.boundingBox.max = sf::Vector2f(objectBody.xPos + 0.5*xProjection,objectBody.yPos+0.5*yProjection);

}

float RigidBody::getGravity(void)
{
    return objectBody.gravityFactor;
}

float RigidBody::getInvMass(void)
{
    return objectBody.invMass;
}

float RigidBody::getRestitution(void)
{
    return objectBody.restitution;
}

void RigidBody::setRestitution(float newRest)
{
    objectBody.restitution = newRest;
}

void RigidBody::addAngularVelocity(float angularVel)
{
    objectBody.angularVelocity += angularVel;
}

void RigidBody::setRotation(float angle)
{
    objectBody.angleOfRotation = angle;
}

AABB RigidBody::getBoundingBox(void)
{
    return objectBody.boundingBox;
}

void RigidBody::setPosition(sf::Vector2f newPos)
{
    objectBody.xPos = newPos.x;
    objectBody.yPos = newPos.y;
}

void RigidBody::addPosition(sf::Vector2f newPos)
{
    objectBody.xPos += newPos.x;
    objectBody.yPos -= newPos.y;
}

sf::Vector2f RigidBody::getPosition(void)
{
    return sf::Vector2f(objectBody.xPos,objectBody.yPos);
}

sf::Vector2f RigidBody::getVertex(int i)
{
    float xPrime, yPrime;
    float x = objectBody.vertexes[i].x;
    float y = objectBody.vertexes[i].y;
    float angle = objectBody.angleOfRotation * (3.14/180);

    sf::Vector2f finalVertex;

    xPrime = x * cos(angle) - y * sin(angle);
    yPrime = x * sin(angle) + y * cos(angle);


    finalVertex = sf::Vector2f(xPrime,yPrime) + sf::Vector2f(objectBody.xPos,objectBody.yPos);

    return finalVertex;
}

sf::Vector2f RigidBody::getVelocity(void)
{
    return objectBody.velocity;
}

float RigidBody::getStaticFriction(void)
{
    return objectBody.staticFriction;
}

float RigidBody::getDynamicFriction(void)
{
    return objectBody.dynamicFriction;
}

float RigidBody::getOrientation(void)
{
    return objectBody.angleOfRotation;
}

float RigidBody::getWidth(void)
{
    return 2*objectBody.vertexes[1].x;
}

float RigidBody::getHeight(void)
{
    return 2*objectBody.vertexes[1].y;
}

float RigidBody::getInvIntertia(void)
{
    return objectBody.invInertia;
}

sf::Vector2f RigidBody::getPreviousPosition(void)
{
    return objectBody.oldPosition;
}

void RigidBody::setPreviousPosition(sf::Vector2f newPos)
{
    objectBody.oldPosition = newPos;
}