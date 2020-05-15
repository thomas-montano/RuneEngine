/**
 * @class RigidBody
 * @brief Game object component that allows a game object to have collisions with other objects.
 * 
 * @author Thomas Montano
 * @date March 2 2020
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "core.h"
#include <vector>
#include <Renderer\vec2.h>
#include <Renderer\drawable.h>
#include <Renderer\renderWindow.h>
#include <Renderer\rectangleShape.h>

//Forward declaration of rigidbody class
class RigidBody;

///Collision manifold used for reporting rigid body collisions.
struct collision
{

    RigidBody* objectOne;
    RigidBody* objectTwo;
    Vec2 normalVector;
    Vec2 contactVectorBox1;
    Vec2 contactVectorBox2;
    double depth;

};

///Axis aligned bounding box for each object.
struct AABB
{

  Vec2 min;
  Vec2 max;

};

///Rigid body struct containing all the information for a physically realistic response.
struct body
{

  Vec2 vertexes[4]; ///Specific Vertexes
  AABB boundingBox; //Broad phase Minimum bounding box
  double xPos; //X position in world coordinates
  double yPos; //Y Position in world coordinates
  Vec2 oldPosition; //Previous position in world coordinates
  Vec2 velocity; //Velocity
  double invMass; // 1/mass of the object
  double gravityFactor; //How much gravity does this object have
  double restitution = 0; //How bouncy, between 0 and 1

  double staticFriction = .4; //Coefficient of static friction
  double dynamicFriction = .2; //Coefficient of dynamic friction

  double angleOfRotation; //Current angle of rotation
  double angularVelocity; //Rate of change of rotation
  double torque; //Rotational torque on the object
  double invInertia;
  double rotationalRadius;

};

class RUNE_ENGINE RigidBody// : public Drawable
{

private:
    body objectBody;
    bool isSleeping;
    std::vector<collision> involvedCollisions;
    RectangleShape drawBox;

    ///Overloaded draw functions for rendering the AABB to the screen.
    /*virtual void draw(RenderWindow& window)
    {

        drawBox.setPosition(Vec2(objectBody.xPos,objectBody.yPos));
        drawBox.setSize(Vec2(2 * objectBody.vertexes[1].x,2 * objectBody.vertexes[1].y));

        /*AABB.setFillColor(sf::Color::Transparent);
        AABB.setOutlineThickness(-.5);
        AABB.setOutlineColor(sf::Color::Red);
        AABB.setPosition(objectBody.boundingBox.min);

        AABB.setSize(objectBody.boundingBox.max-objectBody.boundingBox.min);
        
        window.draw(drawBox);
    }*/

public:
    ///Default constructor to initialize an empty rigid body object.
    RigidBody();

    ///Set the parameters for the rigid body to establish a physical object in the scene.
    RigidBody(int width, int height, double xPos, double yPos, double mass, double gravity = 0, bool rotation = true);

    ///Set up the object. Identical to the constructor but can be used to set up an object after it's been created.
    void setUpObject(int width, int height, double xPos, double yPos, double mass, double gravity, bool rotation);

    ///Set the origin of the rigid body.
    void setOrigin(Vec2 newOrigin);

    ///Recalculate the AABB based on the rigid body position.
    void updateAABB();

    ///Return an AABB containing the information about the rigid body bounding box.
    AABB getBoundingBox(void);

    ///Adds to the rigid body angular velocity making it spin faster or slower.
    void addAngularVelocity(double angularVel);

    ///Overwrite the orientation of the rigid body to be something new.
    void setRotation(double angle);

    ///Overwrite the position of the rigid body to be something new.
    void setPosition(Vec2);

    ///Add some vector to the current position.
    void addPosition(Vec2 newPos);

    //Get the current rigid body position
    Vec2 getPosition(void);
    
    ///Add to the objects current velocity vector.
    void addVelocity(Vec2);

    ///Update the position of the object based on collisions and velocities.
    void updatePosition(double dT);

    ///Get the gravity vector of the object.
    double getGravity(void);

    ///Get the current velocity of the rigid body.
    Vec2 getVelocity(void);

    ///Set the current velocity of the rigid body.
    void setVelocity(Vec2);

    ///Return the current position of a vertex in world coordinates.
    Vec2 getVertex(int);

    ///Get the inverse mass of the rigid body.
    double getInvMass(void);

    ///Get the inverse inertia of the rigid body.
    double getInvIntertia(void);

    ///Return the restitution (bounciness) of the rigid body.
    double getRestitution(void);

    ///Set the restitution (bounciness) of the rigid body.
    void setRestitution(double);

    ///Get the coefficient of static friction.
    double getStaticFriction(void);

    //Get the coefficient of dynamic friction.
    double getDynamicFriction(void);

    ///Get the current orientation of the rigid body.
    double getOrientation(void);

    ///Get the width of the AABB.
    double getWidth(void);

    ///Get the height of the AABB.
    double getHeight(void);

    ///Get the position that the rigid body was in last frame.
    Vec2 getPreviousPosition(void);

    ///Set the position that the rigid body was in last frame.
    void setPreviousPosition(Vec2);

    ///Clear the list of collisions that rigid body is involved with.
    void clearCollisions(void);

    ///Add a collision to the list of collisions the rigid body was involved in.
    void addCollision(collision);

    ///Get the list of collisions the rigid body was involved in.
    std::vector<collision> getCollisions(void);

};

#endif