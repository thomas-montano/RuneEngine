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

#include "core.h"
#include <SceneTools\messageManager.h>
#include <Renderer\rectangleShape.h>
#include <Renderer\color.h>

class RUNE_ENGINE ParticleEmitter// : public Drawable
{

private:
  ///Data container for each individual particle.
  struct particle
  {
    Vec2 m_pixelPosition;
    Color m_pixelColor; //Color of all particles
    Vec2 m_particleSpeed; //Rate at which particles travel
    //RectangleShape m_particleSprite[4];
    int m_timeExisted; //Time the pixel has existed in milliseconds
  };

  const int PARTICLELIMIT = 1000;
  float m_dissolutionRate; //Rate at which particles disappear

  Color m_pixelBaseColor; //Starting color, can apply modifiers later

  Vec2 m_canvasSize = Vec2(100,100);

  Vec2 m_initVel;
  Vec2 m_startPos; //Location at which the particles start
  Vec2 m_gravity; //Influence particle velocities
  
  std::vector<particle> m_particles;

  ///Overloaded draw function to render particles to the screen.
  //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  ///Default constructor for a particle emitter that establishes position, color, and velocity constraints.
  ParticleEmitter(Vec2 startPos, Vec2 initVel, Color color, int dissolutionRate = 5, Vec2 gravity = Vec2(0,0));
  
  ///The amount of time in seconds that a particle will exist before it gets destroyed.
  void setDissolutionRate(float rate);

  ///Sets the gravity that a particle will be subjected to.
  void setGravity(Vec2 gravity);

  ///Spawn particles from the particles emitter.
  void fuel(int particles);

  ///Update the position of the particles based on velocity and gravity.
  void update(float dT);

  //Set the region that the particle is allowed to move around in.
  void setCanvasSize(Vec2);

  //Set the position of the particles emitter.
  void setPosition(Vec2);

};

#endif