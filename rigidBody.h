#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <SFML/Graphics.hpp>

//Forward declaration of rigidbody class
class RigidBody;

struct collision
{

    RigidBody* objectOne;
    RigidBody* objectTwo;
    sf::Vector2f normalVector;
    sf::Vector2f contactVectorBox1;
    sf::Vector2f contactVectorBox2;
    float depth;

};

struct AABB
{

    sf::Vector2f min;
    sf::Vector2f max;

};

struct body
{

    sf::Vector2f vertexes[4]; //Specific Vertexes
    AABB boundingBox; //Broad phase Minimum bounding box
    float xPos; //X position in world coordinates
    float yPos; //Y Position in world coordinates
    sf::Vector2f oldPosition; //Previous position in world coordinates
    sf::Vector2f velocity; //Velocity
    sf::RectangleShape box; //For drawing things
    float invMass; // 1/mass of the object
    float gravityFactor; //How much gravity does this object have
    float restitution = 0; //How bouncy, between 0 and 1

    float staticFriction = .4; //Coefficient of static friction
    float dynamicFriction = .2; //Coefficient of dynamic friction

    float angleOfRotation; //Current angle of rotation
    float angularVelocity; //Rate of change of rotation
    float torque; //Rotational torque on the object
    float invInertia;
    float rotationalRadius;

};

class RigidBody
{

private:
    body objectBody;
    bool isSleeping;
    std::vector<collision> involvedCollisions;

public:
    RigidBody();
    RigidBody(int width, int height, float xPos, float yPos, float mass, float gravity, bool rotation = true);
    void setUpObject(int width, int height, float xPos, float yPos, float mass, float gravity, bool rotation);
    sf::RectangleShape getDrawable(void);
    void setOrigin(sf::Vector2f newOrigin);

    sf::RectangleShape drawAABB(void);
    void updateAABB();
    AABB getBoundingBox(void);

    void addAngularVelocity(float angularVel);
    void setRotation(float angle);
    void setPosition(sf::Vector2f);
    void addPosition(sf::Vector2f newPos);
    sf::Vector2f getPosition(void);

    void addVelocity(sf::Vector2f);
    void updatePosition(float dT);
    float getGravity(void);

    sf::Vector2f getVelocity(void);
    void setVelocity(sf::Vector2f);

    sf::Vector2f getVertex(int);

    float getInvMass(void);
    float getInvIntertia(void);

    float getRestitution(void);
    void setRestitution(float);

    float getStaticFriction(void);
    float getDynamicFriction(void);

    float getOrientation(void);

    float getWidth(void);
    float getHeight(void);

    sf::Vector2f getPreviousPosition(void);
    void setPreviousPosition(sf::Vector2f);

    void clearCollisions(void);
    void addCollision(collision);
    std::vector<collision> getCollisions(void);

};

#endif