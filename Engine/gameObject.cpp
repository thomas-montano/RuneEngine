/*

  Function file for gameObject.h

*/

#include "gameObject.h"
#include "layer.h"

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

//Move the object sprite to the current location
void GameObject::updatePosition(float alpha)
{
  sf::Vector2f oldPosition = m_objectRigidBody.getPreviousPosition();
  sf::Vector2f currentPos = m_objectRigidBody.getPosition();

  sf::Vector2f newPos = sf::Vector2f(oldPosition.x*alpha,oldPosition.y*alpha) + sf::Vector2f(currentPos.x*(1.0-alpha),currentPos.y*(1.0-alpha));

  m_objectSprite.setPosition(newPos);

  m_objectRigidBody.setPreviousPosition(currentPos);

  m_objectSprite.setRotation(m_objectRigidBody.getOrientation());

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

std::vector<collision> GameObject::getCollisions(void)
{
  return m_objectRigidBody.getCollisions();
}

 void GameObject::setRotation(float angle)
 {
   m_objectRigidBody.setRotation(angle);
 }

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_objectSprite,states);
}

void GameObject::setLayer(SceneLayer* layer)
{
  myLayer = layer;
}

SceneLayer* GameObject::getLayer(void)
{
  return myLayer;
}