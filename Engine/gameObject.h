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
#include "particleEmitter.h"
#include "rigidBody.h"

//Forward declaration of layer object
class SceneLayer;

class GameObject : public sf::Drawable
{
private:
  sf::Texture m_objectTexture; //Texture for the object
  sf::Sprite m_objectSprite; //Drawable sprite object
  std::vector<ObjectAnimation*> animations; //Animations to be played

  SceneLayer* myLayer;

  RigidBody m_objectRigidBody;

  bool m_mirrorSprite;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  void objectInit(float xPos, float yPos, int width, int height, std::string filePath,float mass = 10,float gravity = 10);
  void addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName);
  void playAnimation(int animation);
  sf::Sprite* getSprite(void);
  void mirrorSprite(bool);

  //Functions to allow for customizable game objects
  virtual void update();
  virtual void start();

  void updatePosition(float alpha);
  
  RigidBody* getRigidBody(void);

  std::vector<collision> getCollisions(void);

  void setRotation(float angle);

  void setLayer(SceneLayer* layer);
  SceneLayer* getLayer(void);

};

#endif
