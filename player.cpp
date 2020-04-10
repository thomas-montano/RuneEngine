#include "player.h"

void Player::start()
{

this->addAnimation(16, 2, 2, "./Assets/Images/knoxIdleSheet.png"); // Animation 0, idle state

}

// /brief This function gets called once per frame for every object
void Player::update()
{

  //Get some info from the message manager needed later
  sf::Vector2f moveVelocity;
  sf::RenderWindow* window = MessageManager::getWindow();

  float shapeXMin = this->getRigidBody()->getBoundingBox().min.x;
  float shapeXMax = this->getRigidBody()->getBoundingBox().max.x;

  this->playAnimation(0);

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

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
      this->getRigidBody()->addVelocity(sf::Vector2f(0,20));
  }

  //Jump if the player hits space bar
  if(this->getHasJumped() == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {

    this->setHasJumped(true);
    moveVelocity.y = 200;

  }
  else
  {
    moveVelocity.y = this->getRigidBody()->getVelocity().y;
  }

  //If the player is standing on the ground, let them jump again
  if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))// && areObjectsColliding(jumpObject,MessageManager::getMidGroundObjects()))
  {
    this->setHasJumped(false);
  }

  //Don't let the player go off the left side of the screen
  if(shapeXMin < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    moveVelocity.x = 0;
  }

}
