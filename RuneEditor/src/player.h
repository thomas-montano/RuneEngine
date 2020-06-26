/**
 * @class Player
 * @brief Main game object for the player controller.
 * 
 * @author Thomas Montano
 * @date March 3 2020
*/

#ifndef PLAYER_OBJECT_DEFINED
#define PLAYER_OBJECT_DEFINED

#include <RuneEngine.h>

class Player : public rune::GameObject
{

public:
  //Adding components
  rune::RectangleShape rectangle;
  
  //ParticleEmitter* testParticle = new ParticleEmitter(Vec2(100,635), Vec2(0,20), Color::Blue, 2, Vec2(0,-80));
  Player()
  {

    transform.setPosition(rune::Vec3(0, 0));
    transform.setScale(rune::Vec3(16, 32));
    transform.setRotationZ(45);

    addComponent(rectangle);

    rectangle.setFillColor(rune::Color::Blue);

  };

};

#endif
