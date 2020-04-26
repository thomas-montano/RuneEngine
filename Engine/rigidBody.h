/**
 * @brief Game object component that allows a game object to have collisions with other objects.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <SFML/Graphics.hpp>

//Forward declaration of rigidbody class
class RigidBody;

///Collision manifold used for reportingrigid body collisions.
struct collision
{

    RigidBody* objectOne;
    RigidBody* objectTwo;
    sf::Vector2f normalVector;
    sf::Vector2f contactVectorBox1;
    sf::Vector2f contactVectorBox2;
    float depth;

};

///Axis aligned bounding box for each object.
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

class RigidBody : public sf::Drawable
{

private:
    body objectBody;
    bool isSleeping;
    std::vector<collision> involvedCollisions;

    ///Overloaded draw functions for rendering the AABB to the screen.
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

        sf::RectangleShape AABB;

        AABB.setFillColor(sf::Color::Transparent);
        AABB.setOutlineThickness(-.5);
        AABB.setOutlineColor(sf::Color::Red);
        AABB.setPosition(objectBody.boundingBox.min);

        AABB.setSize(objectBody.boundingBox.max-objectBody.boundingBox.min);

        target.draw(AABB);
    }

public:
    ///Default constructor to initialize an empty rigid body object.
    RigidBody();

    ///Set the parameters for the rigid body to establish a physical object in the scene.
    RigidBody(int width, int height, float xPos, float yPos, float mass, float gravity = 0, bool rotation = true);

    ///Set up the object. Identical to the constructor but can be used to set up an object after it's been created.
    void setUpObject(int width, int height, float xPos, float yPos, float mass, float gravity, bool rotation);

    ///Get the bounding box sprite (DEPRECATED).
    sf::RectangleShape getDrawable(void);

    ///Set the origin of the rigid body.
    void setOrigin(sf::Vector2f newOrigin);

    ///Get a rectangle shape object for the bounding box.
    sf::RectangleShape drawAABB(void);

    ///Recalculate the AABB based on the rigid body position.
    void updateAABB();

    ///Return an AABB containing the information about the rigid body bounding box.
    AABB getBoundingBox(void);

    ///Adds to the rigid body angular velocity making it spin faster or slower.
    void addAngularVelocity(float angularVel);

    ///Overwrite the orientation of the rigid body to be something new.
    void setRotation(float angle);

    ///Overwrite the position of the rigid body to be something new.
    void setPosition(sf::Vector2f);

    ///Add some vector to the current position.
    void addPosition(sf::Vector2f newPos);

    //Get the current rigid body position
    sf::Vector2f getPosition(void);
    
    ///Add to the objects current velocity vector.
    void addVelocity(sf::Vector2f);

    ///Update the position of the object based on collisions and velocities.
    void updatePosition(float dT);

    ///Get the gravity vector of the object.
    float getGravity(void);

    ///Get the current velocity of the rigid body.
    sf::Vector2f getVelocity(void);

    ///Set the current velocity of the rigid body.
    void setVelocity(sf::Vector2f);

    ///Return the current position of a vertex in world coordinates.
    sf::Vector2f getVertex(int);

    ///Get the inverse mass of the rigid body.
    float getInvMass(void);

    ///Get the inverse inertia of the rigid body.
    float getInvIntertia(void);

    ///Return the restitution (bounciness) of the rigid body.
    float getRestitution(void);

    ///Set the restitution (bounciness) of the rigid body.
    void setRestitution(float);

    ///Get the coefficient of static friction.
    float getStaticFriction(void);

    //Get the coefficient of dynamic friction.
    float getDynamicFriction(void);

    ///Get the current orientation of the rigid body.
    float getOrientation(void);

    ///Get the width of the AABB.
    float getWidth(void);

    ///Get the height of the AABB.
    float getHeight(void);

    ///Get the position that the rigid body was in last frame.
    sf::Vector2f getPreviousPosition(void);

    ///Set the position that the rigid body was in last frame.
    void setPreviousPosition(sf::Vector2f);

    ///Clear the list of collisions that rigid body is involved with.
    void clearCollisions(void);

    ///Add a collision to the list of collisions the rigid body was involved in.
    void addCollision(collision);

    ///Get the list of collisions the rigid body was involved in.
    std::vector<collision> getCollisions(void);

};

#endif