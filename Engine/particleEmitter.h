/*

  ParticleEmitter

  Class responsible for creating particle emitters and managing
  the creation of particles

  Thomas Montano
  3/2/20

*/

#ifndef PARTICLES_H_DEFINED
#define PARTICLES_H_DEFINED

#include <SFML/Graphics.hpp>
#include "messageManager.h"

class ParticleEmitter : public sf::Drawable
{

protected:
  struct particle
  {
    sf::Vector2f m_pixelPosition;
    sf::Color m_pixelColor; //Color of all particles
    sf::Vector2f m_particleSpeed; //Rate at which particles travel
    sf::Vertex m_particleSprite[4];
    int m_timeExisted; //Time the pixel has existed in milliseconds
  };

private:

  const int PARTICLELIMIT = 1000;
  int m_dissolutionRate; //Rate at which particles disappear

  sf::Color m_pixelBaseColor; //Starting color, can apply modifiers later

  sf::Vector2f m_initVel;
  sf::Vector2f m_startPos; //Location at which the particles start
  sf::Vector2f m_gravity; //Influence particle velocities
  
  std::vector<particle> m_particles;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    for(int i = 0; i < m_particles.size();i++)
    {
      target.draw(m_particles[i].m_particleSprite,4,sf::Quads,states);
    }
  }

public:
  ParticleEmitter(sf::Vector2f startPos,  sf::Vector2f initVel, sf::Color color, int dissolutionRate = 5, sf::Vector2f gravity = sf::Vector2f(0,-10));
  
  void setDissolutionRate(int rate);
  void setGravity(sf::Vector2f gravity);
  void draw(sf::RenderWindow &window);
  void fuel(int particles); //Adds new particles
  void update(float dT); //Updates particles

};

#endif