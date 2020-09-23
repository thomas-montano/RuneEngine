/**
 * @class physics::RigidBody
 * @brief Game object component that allows a game object to have collisions with other objects.
 * 
 * @author Thomas Montano
 * @date March 2 2020
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "core.h"
#include <vector>
#include <Math\Vec2.h>
#include <Entities\component.h>
#include <Entities\gameObject.h>
#include <Renderer\rectangleShape.h>

namespace physics{

//Forward declaration of rigid body class
class RigidBody;

///Collision manifold used for reporting rigid body collisions.
struct collision
{

    RigidBody* objectOne;
    RigidBody* objectTwo;
    rune::Vec2 normalVector;
    double depth;

    collision() : objectOne(nullptr), objectTwo(nullptr), normalVector(rune::Vec2(0,0)), depth(0)
    {
    
    }

};

///Axis aligned bounding box for each object.
struct AABB
{

  rune::Vec2 min;
  rune::Vec2 max;

  AABB() : min(rune::Vec2(0,0)), max(rune::Vec2(0,0))
  {
  
  }

};

///Rigid body struct containing all the information for a physically realistic response.
struct body
{
  ///Vertices of the body
  rune::Vec2 vertexes[4]; 
  ///Broad phase Minimum bounding box
  AABB boundingBox; 
  ///X position in world coordinates
  double xPos;
  ///Y Position in world coordinates
  double yPos; 
  ///Previous position in world coordinates
  rune::Vec2 oldPosition; 
  ///Velocity
  rune::Vec2 velocity; 
  /// 1/mass of the object
  double invMass; 
  ///How much gravity does this object have
  rune::Vec2 gravityFactor; 

  ///How bouncy, between 0 and 1
  double restitution; 
  ///Coefficient of static friction
  double staticFriction; 
  ///Coefficient of dynamic friction
  double dynamicFriction; 
  
  ///Coefficient of dynamic friction
  double angleOfRotation; 
  ///Rate of change of rotation
  double angularVelocity; 
  ///Rotational torque on the object
  double torque; 
  ///Inverse inertia of the body
  double invInertia; 
  ///Largest radius that can have a moment applied to it
  double rotationalRadius; 

};

class RUNE_ENGINE RigidBody : public rune::Component
{

private:
    body objectBody;
    std::vector<collision> involvedCollisions;

public:
    ///Initialize the physics::RigidBody to be approximately the same size as the rune::GameObject
    virtual void start();

    ///Constructor to set up mass data of the RigidBody
    RigidBody(double mass = 0, rune::Vec2 gravity = rune::Vec2(0,0));

    ///Set up the object. Identical to the constructor but can be used to set up an object after it's been created.
    void setUpObject(int width, int height, double mass, bool rotation);

    ///Recalculate the AABB based on the rigid body position.
    void updateAABB();

    ///Return an AABB containing the information about the rigid body bounding box.
    AABB getBoundingBox(void);

    ///Adds to the rigid body angular velocity making it spin faster or slower.
    void addAngularVelocity(double angularVel);

    ///Overwrite the orientation of the rigid body to be something new.
    void setRotation(double angle);

    ///Overwrite the position of the rigid body to be something new.
    void setPosition(rune::Vec2);

    ///Add some vector to the current position.
    void addPosition(rune::Vec2 newPos);

    ///Get the current rigid body position
    rune::Vec2 getPosition(void);
    
    ///Add to the objects current velocity vector.
    void addVelocity(rune::Vec2);

    ///Update the position of the object based on collisions and velocities.
    void updatePosition(double dT);

    ///Linearly interpolate the position of the rune::RigidBody for editing to transform of the parent object.
    void interpolatePosition(double alpha);

    ///Get the gravity vector of the object.
    rune::Vec2 getGravity(void);

    ///Get the current velocity of the rigid body.
    rune::Vec2 getVelocity(void);

    ///Set the current velocity of the rigid body.
    void setVelocity(rune::Vec2);

    ///Return the current position of a vertex in world coordinates.
    rune::Vec2 getVertex(int);

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

    ///Set the coefficient of static friction.
    void setStaticFriction(float friction);

    ///Get the coefficient of dynamic friction.
    double getDynamicFriction(void);

    ///Set the coefficient of dynamic friction.
    void setDynamicFriction(float friction);

    ///Get the current orientation of the rigid body.
    double getOrientation(void);

    ///Get the width of the AABB.
    double getWidth(void);

    ///Get the height of the AABB.
    double getHeight(void);

    ///Get the position that the rigid body was in last frame.
    rune::Vec2 getPreviousPosition(void);

    ///Set the position that the rigid body was in last frame.
    void setPreviousPosition(rune::Vec2);

    ///Clear the list of collisions that rigid body is involved with.
    void clearCollisions(void);

    ///Add a collision to the list of collisions the rigid body was involved in.
    void addCollision(collision);

    ///Get the list of collisions the rigid body was involved in.
    std::vector<collision> getCollisions(void);

};
}

#endif

/**
 * @page physics Physics
 * 
 * Adding physical interactions is an important and fun part of making your game! In Rune, adding physics is as simple as attaching a physics::RigidBody component to
 * your rune::GameObject.
 * 
 * In your GameObject constructor, you will be required to initialize the RigidBody in one of two ways. One way is by doing nothing, this will create a RigidBody component
 * with infinite mass that isn't allowed to move, but other RigidBodies will collide with happily.
 * 
 * If you would like to have your object move, you will need to specify the mass of the RigidBody. You can do this like so:
 * 
 * @subsection Initialization Adding a static (non-moving) RigidBody to your GameObject.
 * 
 * @code
 * 
 * #include <RuneEngine.h>
 * 
 * class Player : public rune::GameObject
 * {
 * public:
 *  physics::RigidBody myBody;
 * 
 *  Player();
 * 
 * };
 * 
 * @endcode
 * 
 * @subsection massChange Giving your RigidBody movement.
 * 
 * After you have initialized a RigidBody in your GameObject header file, go ahead and apply it to the GameObject. Remember that both of the arguments in the RigidBody
 * constructor are optional, and can be left out completely. Refer to the physics::RigidBody page for more information about these parameters.
 * 
 * @code
 * 
 * #include "player.h"
 * 
 * Player::Player()
 *  : myBody(10,rune::Vec2(0,-10))
 * {
 * 
 *  addComponent(myBody);
 * 
 * }
 * 
 * @endcode
 * 
 * Now your object will be subjected to gravity and collisions!
 * 
 */