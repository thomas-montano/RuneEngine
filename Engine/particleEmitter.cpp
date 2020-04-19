#include "particleEmitter.h"
#include <cmath>

ParticleEmitter::ParticleEmitter(sf::Vector2f startPos, sf::Vector2f initVel, sf::Color color, int dissolutionRate, sf::Vector2f gravity)
{
  m_startPos = startPos;
  m_pixelBaseColor = color;
  m_initVel = initVel;
  m_dissolutionRate = dissolutionRate;
  m_gravity = gravity;

}

void ParticleEmitter::draw(sf::RenderWindow &window)
{

  for(int i = 0; i < m_particles.size();i++)
  {
    window.draw(m_particles[i].m_particleSprite,4,sf::Quads);
  }

}

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

void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(int i = 0; i < m_particles.size();i++)
  {
    target.draw(m_particles[i].m_particleSprite,4,sf::Quads,states);
  }
}

void ParticleEmitter::setDissolutionRate(int rate)
{
  m_dissolutionRate = rate;
}

void ParticleEmitter::setGravity(sf::Vector2f gravity)
{
  m_gravity = gravity;
}

void ParticleEmitter::setCanvasSize(sf::Vector2f canvas)
{
  m_canvasSize = canvas;
}