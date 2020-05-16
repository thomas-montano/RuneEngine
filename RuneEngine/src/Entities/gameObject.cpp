#include "gameObject.h"
#include <SceneTools\layer.h>

/**
 * @param xPos The horizontal position of the object relative to the bottom left corner of the sprite.
 * @param yPos The vertical position of the object relative to the bottom left corner of the sprite.
 * @param width Width of the sprite in pixels.
 * @param height Height of the sprite in pixels.
 * @param filePath Path to the sprite relative to the top level main function.
 * @param mass Mass of the object in units relative to the game. (0 mass = infinite mass)
 * @param gravity Gravity vector that the object will be subject to.
*/
void GameObject::objectInit(float xPos, float yPos, int width, int height, std::string filePath, float mass, float gravity)
{

  m_objectSprite.setOrigin(rune::Vec2(0.5*width,0.5*height));

  m_objectSprite.setTexture(filePath.c_str());
  m_objectSprite.setSize(rune::Vec2(width, height));
  m_objectSprite.setPosition(rune::Vec2(xPos, yPos));

  m_objectRigidBody.setUpObject(width, height, xPos, yPos, mass, gravity, false);

  m_objectRigidBody.setPreviousPosition(rune::Vec2(xPos,yPos));

  /*//If the actual texture can't be loaded, load the error texture
  //if(filePath != "")
  {

    

  }//else if (filePath != "")
  {
    //m_objectSprite.setTexture(m_objectTexture);
  }*/
  
  this->start();

}

void GameObject::draw(RenderWindow& window)
{

  window.draw(m_objectSprite);

}

/**
 * @param frameWidth the width of the individual frame in pixels
 * @param numFrames the total number of frames in the animation
 * @param frameRate the rate in Hz that the animation will be played
 * @param fileName Path to the sprite sheet relative to the top level main function.
*/
void GameObject::addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName)
{

  /*ObjectAnimation* newAnimation = new ObjectAnimation;
  Texture* spriteSheet = new Texture;

  newAnimation->setCurrentFame(0);
  newAnimation->setFrameWidth(frameWidth);
  newAnimation->setNumFrames(numFrames);
  newAnimation->setFrameRate(frameRate);

  spriteSheet->loadFromFile(fileName);
  newAnimation->setFile(fileName);
  
  newAnimation->setSheet(*spriteSheet);

  animations.push_back(newAnimation);*/

}

/**
 * @param animation Integer index in the animation array that refers to the order in which the animations where loaded
*/
void GameObject::playAnimation(int animation)
{

  /*ObjectAnimation* currentAnimation = animations[animation];

  currentAnimation->getSheet()->loadFromFile(currentAnimation->getFile());

  //m_objectSprite.setTexture(*currentAnimation->getSheet());

  if(m_mirrorSprite)
  {
    m_objectSprite.setTextureRect(sf::IntRect((currentAnimation->getCurrentFrame() * currentAnimation->getFrameWidth()),0,currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
  }
  else
  {
    m_objectSprite.setTextureRect(sf::IntRect(((currentAnimation->getCurrentFrame()+1) * currentAnimation->getFrameWidth()),0,-currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
  }
  
  currentAnimation->incCurrentFrame();*/

}

/**
 * @param mirror Whether or not the sprite should be mirrored vertically.
*/
void GameObject::mirrorSprite(bool mirror)
{
  m_mirrorSprite = mirror;
}

/**
 * @param alpha coefficient of linear interpolation
*/
void GameObject::updatePosition(float alpha)
{
  rune::Vec2 oldPosition = m_objectRigidBody.getPreviousPosition();
  rune::Vec2 currentPos = m_objectRigidBody.getPosition();

  rune::Vec2 newPos = rune::Vec2(oldPosition.x*alpha,oldPosition.y*alpha) + rune::Vec2(currentPos.x*(1.0-alpha),currentPos.y*(1.0-alpha));

  m_objectSprite.setPosition(newPos);

  m_objectRigidBody.setPreviousPosition(currentPos);

  //m_objectSprite.setRotation(m_objectRigidBody.getOrientation());

}

void GameObject::update(void)
{

  return;
}

void GameObject::start(void)
{

  return;
}

RigidBody* GameObject::getRigidBody(void)
{
  return &m_objectRigidBody;
}

std::vector<collision> GameObject::getCollisions(void)
{
  return m_objectRigidBody.getCollisions();
}

/**
 * @param angle Angle in degrees that the object should be rotated to.
*/
 void GameObject::setRotation(float angle)
 {
   m_objectRigidBody.setRotation(angle);
 }

/**
 * @param layer SceneLayer object that should be referenced by the game object
*/
void GameObject::setLayer(SceneLayer* layer)
{
  myLayer = layer;
}

SceneLayer* GameObject::getLayer(void)
{
  return myLayer;
}