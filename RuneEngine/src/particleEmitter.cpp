#include "particleEmitter.h"
#include <cmath>

/**
 * @param startPos The location in world coordinates of where the particle emitter should spawn particles.
 * @param initVel The initial velocity that particles should be subjected to.
 * @param color The base color of the particles.
 * @param dissolutionRate The time in seconds that a particle should exist before it gets deleted.
 * @param gravity The gravity vector each particle will be subjected to.
*/
ParticleEmitter::ParticleEmitter(sf::Vector2f startPos, sf::Vector2f initVel, sf::Color color, int dissolutionRate, sf::Vector2f gravity)
{
  m_startPos = startPos;
  m_pixelBaseColor = color;
  m_initVel = initVel;
  m_dissolutionRate = dissolutionRate;
  m_gravity = gravity;

}


/**
 * @param particles The number of particles that should be generated.
*/
void ParticleEmitter::fuel(int particles)
{ 
  
  for(int i = 0; i < particles; i++)
  {
    particle newParticle;

    newParticle.m_pixelPosition = m_startPos;
    newParticle.m_pixelColor = m_pixelBaseColor;
    newParticle.m_timeExisted = 0;

    for(int i = 0; i < 4; i++)
    {
      newParticle.m_particleSprite[1].position = m_startPos;
      newParticle.m_particleSprite[1].color = m_pixelBaseColor;
    }

    sf::Vertex vertices[4] =
    {
      sf::Vertex(sf::Vector2f(m_startPos.x,m_startPos.y), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_startPos.x+1,m_startPos.y), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_startPos.x+1,m_startPos.y+1), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_startPos.x,m_startPos.y+1), m_pixelBaseColor)
    };

    std::copy(vertices, vertices+4,newParticle.m_particleSprite);

    float randomFactor = std::abs(m_initVel.y);
    randomFactor = rand()%((int)randomFactor*1000) - 500*randomFactor;
    
    newParticle.m_particleSpeed = sf::Vector2f(m_initVel.x+randomFactor/1000.0,m_initVel.y);

    m_particles.push_back(newParticle);
  }

  //Limit number of particles
  while(m_particles.size() > PARTICLELIMIT)
  {
    m_particles.erase(m_particles.begin());
  }
}

/**
 * @param dT The amount of time that has passed since the last update call, used to update position of particles.
*/
void ParticleEmitter::update(float dT)
{

  for(int i = 0; i < m_particles.size();i++)
  {
    m_particles[i].m_pixelPosition.x += m_particles[i].m_particleSpeed.x * dT;
    m_particles[i].m_pixelPosition.y -= m_particles[i].m_particleSpeed.y * dT;

    m_particles[i].m_particleSpeed.x += m_gravity.x * dT;
    m_particles[i].m_particleSpeed.y += m_gravity.y * dT;

    //Enforce boundary conditions
    if(m_particles[i].m_pixelPosition.x - m_startPos.x > 0.5*m_canvasSize.x)
    {
      m_particles.erase(m_particles.begin() + i);
    }
    else if(m_particles[i].m_pixelPosition.x - m_startPos.x < -0.5*m_canvasSize.x)
    {
      m_particles.erase(m_particles.begin() + i);
    }

    if(m_particles[i].m_pixelPosition.y - m_startPos.y < -m_canvasSize.y)
    {
      m_particles.erase(m_particles.begin() + i);
    }

    if(m_particles[i].m_pixelPosition.y - m_startPos.y > m_canvasSize.y)
    {
      m_particles[i].m_pixelPosition.y = m_startPos.y + m_canvasSize.y;
    }

    sf::Vertex vertices[4] =
    {
      sf::Vertex(sf::Vector2f(m_particles[i].m_pixelPosition.x,m_particles[i].m_pixelPosition.y), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_particles[i].m_pixelPosition.x+1,m_particles[i].m_pixelPosition.y), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_particles[i].m_pixelPosition.x+1,m_particles[i].m_pixelPosition.y+1), m_pixelBaseColor),
      sf::Vertex(sf::Vector2f(m_particles[i].m_pixelPosition.x,m_particles[i].m_pixelPosition.y+1), m_pixelBaseColor)
    };

    std::copy(vertices, vertices+4,m_particles[i].m_particleSprite);

    //Update the amount of time a particle has existed, and then delete it if its existed for too long
    m_particles[i].m_timeExisted += dT * 1000;

    if(m_particles[i].m_timeExisted > (m_dissolutionRate * 1000))
    { 
      m_particles.erase(m_particles.begin() + i);
    }

  }

}

/**
 * @param window Overloaded draw function for rendering the particles to the screen.
*/
void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(int i = 0; i < m_particles.size();i++)
  {
    target.draw(m_particles[i].m_particleSprite,4,sf::Quads,states);
  }
}

/**
 * @param rate The amount of time in seconds that a particle should exist before being deleted.
*/
void ParticleEmitter::setDissolutionRate(float rate)
{
  m_dissolutionRate = rate;
}

/**
 * @param gravity The gravity vector that each particle will be subjected to.
*/
void ParticleEmitter::setGravity(sf::Vector2f gravity)
{
  m_gravity = gravity;
}

/**
 * @param canvas A vector describing the area that a particle will be allowed to exist in.
*/
void ParticleEmitter::setCanvasSize(sf::Vector2f canvas)
{
  m_canvasSize = canvas;
}

/**
 * @param newPos The new position that the particle emitter should start generating particle from.
*/
void ParticleEmitter::setPosition(sf::Vector2f newPos)
{  m_startPos = newPos;
}