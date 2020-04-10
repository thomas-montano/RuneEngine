/*

  Function file for gameObject.h

*/

#include "gameObject.h"
#include "messageManager.h"

//This function must always be called when creating an object
//Sets up position, size, and texture
void GameObject::objectInit(float xPos, float yPos, int width, int height, std::string filePath, float mass, float gravity)
{

  m_objectRigidBody.setUpObject(width, height, xPos, yPos, mass, gravity, false);

  m_objectSprite.setOrigin(sf::Vector2f(0.5*width,0.5*height));

  this->start();

  //If the actual texture can't be loaded, load the error texture
  if(filePath != "" && !m_objectTexture.loadFromFile(filePath))
  {

    m_objectTexture.loadFromFile("./Assets/Images/textureFailure.png");
    m_objectSprite.setTexture(m_objectTexture);

  }else if (filePath != "")
  {
    m_objectSprite.setTexture(m_objectTexture);
  }

}

void GameObject::addAnimation(int frameWidth, int numFrames, int frameRate, std::string fileName)
{

  ObjectAnimation* newAnimation = new ObjectAnimation;
  sf::Texture* spriteSheet = new sf::Texture;

  newAnimation->setFrameWidth(frameWidth);
  newAnimation->setNumFrames(numFrames);
  newAnimation->setFrameRate(frameRate);

  newAnimation->setFile(fileName);
  spriteSheet->loadFromFile(fileName);
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
void GameObject::updatePosition(void)
{

  m_objectSprite.setPosition(m_objectRigidBody.getPosition());

}

void GameObject::setHasJumped(bool value)
{

  m_hasJumped = value;

}

bool GameObject::getHasJumped(void)
{

  return m_hasJumped;

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