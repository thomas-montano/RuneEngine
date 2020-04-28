/**
 * @class ParticleEmitter
 * @brief Class responsible for creating particle emitters and managing
 * the creation of particles.
 * 
 * @author Thomas Montano
 * @date March 2 2020
*/

#ifndef PARTICLES_H_DEFINED
#define PARTICLES_H_DEFINED

#include <SFML/Graphics.hpp>
#include "messageManager.h"

class ParticleEmitter : public sf::Drawable
{

private:
  ///Data container for each individual particle.
  struct particle
  {
    sf::Vector2f m_pixelPosition;
    sf::Color m_pixelColor; //Color of all particles
    sf::Vector2f m_particleSpeed; //Rate at which particles travel
    sf::Vertex m_particleSprite[4];
    int m_timeExisted; //Time the pixel has existed in milliseconds
  };

  const int PARTICLELIMIT = 1000;
  float m_dissolutionRate; //Rate at which particles disappear

  sf::Color m_pixelBaseColor; //Starting color, can apply modifiers later

  sf::Vector2f m_canvasSize = sf::Vector2f(100,100);

  sf::Vector2f m_initVel;
  sf::Vector2f m_startPos; //Location at which the particles start
  sf::Vector2f m_gravity; //Influence particle velocities
  
  std::vector<particle> m_particles;

  ///Overloaded draw function to render particles to the screen.
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  ///Default constructor for a particle emitter that establishes position, color, and velocity constraints.
  ParticleEmitter(sf::Vector2f startPos,  sf::Vector2f initVel, sf::Color color, int dissolutionRate = 5, sf::Vector2f gravity = sf::Vector2f(0,-10));
  
  ///The amount of time in seconds that a particle will exist before it gets destroyed.
  void setDissolutionRate(float rate);

  ///Sets the gravity that a particle will be subjected to.
  void setGravity(sf::Vector2f gravity);

  ///Spawn particles from the particles emitter.
  void fuel(int particles);

  ///Update the position of the particles based on velocity and gravity.
  void update(float dT);

  //Set the region that the particle is allowed to move around in.
  void setCanvasSize(sf::Vector2f);

  //Set the position of the particles emitter.
  void setPosition(sf::Vector2f);

};

#endif