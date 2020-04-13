/*

  Function file for gameObject.h

*/

#include "gameObject.h"
#include "messageManager.h"
#include <iostream>

//This function must always be called when creating an object
//Sets up position, size, and texture
void GameObject::objectInit(float xPos, float yPos, int width, int height, std::string filePath, float mass, float gravity)
{

  m_objectSprite.setOrigin(sf::Vector2f(0.5*width,0.5*height));

  m_objectRigidBody.setUpObject(width, height, xPos, yPos, mass, gravity, false);

  m_objectRigidBody.setPreviousPosition(sf::Vector2f(xPos,yPos));  

  //If the actual texture can't be loaded, load the error texture
  if(filePath != "" && !m_objectTexture.loadFromFile(filePath))
  {

    m_objectTexture.loadFromFile("./Assets/Images/textureFailure.png");
    m_objectSprite.setTexture(m_objectTexture);

  }else if (filePath != "")
  {
    m_objectSprite.setTexture(m_objectTexture);
  }
  
  this->start();
  m_objectSprite.setPosition(xPos,yPos);

}

void GameObject::addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName)
{

  ObjectAnimation* newAnimation = new ObjectAnimation;
  sf::Texture* spriteSheet = new sf::Texture;

  newAnimation->setCurrentFame(0);
  newAnimation->setFrameWidth(frameWidth);
  newAnimation->setNumFrames(numFrames);
  newAnimation->setFrameRate(frameRate);

  spriteSheet->loadFromFile(fileName);
  newAnimation->setFile(fileName);
  
  newAnimation->setSheet(*spriteSheet);

  animations.push_back(newAnimation);

}

void GameObject::playAnimation(int animation)
{

  ObjectAnimation* currentAnimation = animations[animation];

  currentAnimation->getSheet()->loadFromFile(currentAnimation->getFile());

  m_objectSprite.setTexture(*currentAnimation->getSheet(),true);

  if(m_mirrorSprite)
  {
    m_objectSprite.setTextureRect(sf::IntRect((currentAnimation->getCurrentFrame() * currentAnimation->getFrameWidth()),0,currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
  }
  else
  {
    m_objectSprite.setTextureRect(sf::IntRect(((currentAnimation->getCurrentFrame()+1) * currentAnimation->getFrameWidth()),0,-currentAnimation->getFrameWidth(), m_objectRigidBody.getBoundingBox().max.y-m_objectRigidBody.getBoundingBox().min.y));
  }
  
  currentAnimation->incCurrentFrame();

}

void GameObject::mirrorSprite(bool mirror)
{
  m_mirrorSprite = mirror;
}

sf::Sprite* GameObject::getSprite(void)
{
  return &m_objectSprite;
}

//This function returns a drawable pointer so that the current state
//can render the object on the screen
sf::Sprite GameObject::getDrawable(void)
{
  return m_objectSprite;
}

//Move the object sprite to the current location
void GameObject::updatePosition(float alpha)
{
  sf::Vector2f oldPosition = m_objectRigidBody.getPreviousPosition();
  sf::Vector2f currentPos = m_objectRigidBody.getPosition();

  sf::Vector2f newPos = sf::Vector2f(oldPosition.x*alpha,oldPosition.y*alpha) + sf::Vector2f(currentPos.x*(1.0-alpha),currentPos.y*(1.0-alpha));

  m_objectSprite.setPosition(newPos);

  m_objectRigidBody.setPreviousPosition(currentPos);

}

void GameObject::update()
{

  return;
}

void GameObject::start()
{

  return;
}

RigidBody* GameObject::getRigidBody(void)
{
  return &m_objectRigidBody;
}

void GameObject::clearCollisions(void)
{
  involvedCollisions.clear();
}

void GameObject::addCollision(collision newCollision)
{
  involvedCollisions.push_back(newCollision);
}

std::vector<collision> GameObject::getCollisions(void)
{
  return involvedCollisions;
}