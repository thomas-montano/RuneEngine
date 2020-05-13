/**
 * @class GameObject
 * @brief Entity control system main object used for all objects in the scene
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef GAMEOBJECT_INCLUDE_H
#define GAMEOBJECT_INCLUDE_H

#include "core.h"
#include <Renderer\drawable.h>
#include <Renderer\renderWindow.h>
#include <Entities\objectAnimation.h>
#include <Entities\particleEmitter.h>
#include <Renderer\sprite.h>
#include <Physics\rigidBody.h>

//Forward declaration of layer object
class SceneLayer;

class RUNE_ENGINE GameObject : public Drawable
{
private:
  Sprite m_objectSprite; //Drawable sprite object
  Texture m_objectTexture;

  std::vector<ObjectAnimation*> animations; //Animations to be played

  SceneLayer* myLayer;

  RigidBody m_objectRigidBody;

  bool m_mirrorSprite;

public:

  virtual void draw(RenderWindow&);

  ///Used to initialize the object, serves the same purpose as a constructor and must be called on every object for it to appear in the scene.
  void objectInit(float xPos, float yPos, int width, int height, std::string filePath,float mass = 10,float gravity = 10);

  ///Add an animation to the animation array
  void addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName);

  ///Plays the specified animation on the game object, animation must be defined before it can be played.
  void playAnimation(int animation);

  ///Returns the sprite object for drawing (DEPRECATED).
  Sprite* getSprite(void);

  ///Whether or not the sprite should be flipped around the vertical axis.
  void mirrorSprite(bool);

  ///Virtual function to be overloaded by the user so that object behavior can be customized in a more organized way. Gets called once per frame.
  virtual void update();

  ///Sets up game object components and runs one time setup for customized objects. Run on object initialization.
  virtual void start();

  ///Update the position of the object based on velocities acting on the object.
  void updatePosition(float alpha);
  
  ///Returns a pointer to the rigid body component.
  RigidBody* getRigidBody(void);

  ///Returns a list of collisions that the object is currently involved in.
  std::vector<collision> getCollisions(void);

  ///Set the rotation of the object.
  void setRotation(float angle);

  ///Set the layer pointer for the object.
  void setLayer(SceneLayer* layer);

  ///Returns a pointer to the layer the object is on. Layer pointer is stored in the scene.
  SceneLayer* getLayer(void);

};

#endif
