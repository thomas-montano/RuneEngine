/**
 * @class Player
 * @brief Main game object for the palyer controller.
 * 
 * @author Thomas Montano
 * @date March 3 2020
*/

#ifndef PLAYER_OBJECT_DEFINED
#define PLAYER_OBJECT_DEFINED

#include "Engine/gameObject.h"
#include "Engine/messageManager.h"
#include "Engine/layer.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{

private:
  bool hasJumped;
  bool touchingGround;
  ParticleEmitter* testParticle = new ParticleEmitter(sf::Vector2f(100,635), sf::Vector2f(0,20), sf::Color::Blue, 2,sf::Vector2f(0,-80));
public:
  virtual void update(void);
  virtual void start(void);

};

#endif
