#include "player.h"
#include <iostream>

void Player::start()
{

  touchingGround = false;
  hasJumped = true;
  this->addAnimation(16, 2, 2, "./Assets/Images/knoxIdleSheet.png"); // Animation 0, idle state

}

// /brief This function gets called once per frame for every object
void Player::update()
{

  //Get some info from the message manager needed later
  sf::Vector2f moveVelocity;
  sf::RenderWindow* window = MessageManager::getWindow();

  this->playAnimation(0);

  float shapeXMin = this->getRigidBody()->getBoundingBox().min.x;
  float shapeXMax = this->getRigidBody()->getBoundingBox().max.x;

  //Flipping the sprite based on mouse position
  if(window->mapCoordsToPixel(sf::Vector2f(shapeXMin + (0.5)*(shapeXMax - shapeXMin),0) ).x > sf::Mouse::getPosition(*MessageManager::getWindow()).x)
  {
    this->mirrorSprite(false);
  }
  else
  {
    this->mirrorSprite(true);
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
      this->getRigidBody()->addVelocity(sf::Vector2f(20,0));
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
      this->getRigidBody()->addVelocity(sf::Vector2f(-20,0));
  }

  //If the player is standing on something, set touchingGround to TRUE
  std::vector<collision> playerCollisions = this->getCollisions();

  for(int i = 0; i < playerCollisions.size();i++)
  {
    if(playerCollisions[0].normalVector.y>0)
    {
      touchingGround = true;
    }
    
  }

  //Jump if the player hits space bar
  if(hasJumped == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    hasJumped = true;
    touchingGround = false;
    this->getRigidBody()->addVelocity(sf::Vector2f(0,200));
  }

  //If the player is standing on the ground, let them jump again
  if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && touchingGround == true)
  {
    hasJumped = false;
  }

  //Don't let the player go off the left side of the screen
  if(shapeXMin < 0)
  {
    this->getRigidBody()->setVelocity(sf::Vector2f(0,this->getRigidBody()->getVelocity().y));
    this->getRigidBody()->setPosition(sf::Vector2f(0.501*this->getRigidBody()->getWidth(),this->getRigidBody()->getPosition().y));
  }

}
