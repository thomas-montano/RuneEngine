/*

  GameObject

  This class provides an object for every object in the game
  and allows for movement of objects and rendering of objects

  Thomas Montano
  3/2/20

*/

#ifndef GAMEOBJECT_INCLUDE_H
#define GAMEOBJECT_INCLUDE_H

#include <SFML/Graphics.hpp>
#include "objectAnimation.h"
#include "rigidBody.h"
#include <string.h>
#include <math.h>
#include <memory>

class GameObject
{
private:
  sf::Texture m_objectTexture; //Texture for the object
  sf::Sprite m_objectSprite; //Drawable sprite object
  std::vector<ObjectAnimation*> animations; //Animations to be played

  RigidBody m_objectRigidBody;

  bool m_mirrorSprite;

public:
  virtual void objectInit(float xPos, float yPos, int width, int height, std::string filePath,float mass = 10,float gravity = 10);
  virtual void addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName);
  virtual void playAnimation(int animation);
  virtual sf::Sprite* getSprite(void);
  virtual void mirrorSprite(bool);

  //Functions to allow for customizable game objects
  virtual void update();
  virtual void start();

  virtual void updatePosition(float alpha);
  virtual sf::Sprite getDrawable(void);
  
  virtual RigidBody* getRigidBody(void);

};

#endif
