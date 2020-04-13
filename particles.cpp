#include "particles.h"
#include <iostream>

Particles::Particles(sf::Vector2f startPos, sf::Vector2f initVel, sf::Color color, int dissolutionRate, sf::Vector2f gravity)
{
  m_startPos = startPos;
  m_pixelBaseColor = color;
  m_initVel = initVel;
  m_dissolutionRate = dissolutionRate;
  m_gravity = gravity;

  dissolutionClock.restart();

}

void Particles::draw(sf::RenderWindow &window)
{

  for(int i = 0; i < m_particles.size();i++)
  {
    window.draw(m_particles[i].m_particleSprite);
  }

}

void Particles::fuel(int particles)
{ 
  
  for(int i = 0; i < particles; i++)
  {
    particle newParticle;

    newParticle.m_pixelPosition = m_startPos;
    newParticle.m_particleSprite.setPosition(m_startPos);
    newParticle.m_particleSprite.setSize(sf::Vector2f(1,1));
    newParticle.m_particleSprite.setFillColor(m_pixelBaseColor);
    newParticle.m_pixelColor = m_pixelBaseColor;

    float randomFactor = m_initVel.y;
    randomFactor = rand()%((int)randomFactor*1000) - 500*randomFactor;
    
    newParticle.m_particleSpeed = sf::Vector2f(m_initVel.x+randomFactor/1000.0,m_initVel.y);

    m_particles.push_back(newParticle);
  }

  //Limit number of particles
  while(m_particles.size() > 500)
  {
    m_particles.erase(m_particles.begin());
  }
}

void Particles::update(float dT)
{

  for(int i = 0; i < m_particles.size();i++)
  {
    m_particles[i].m_pixelPosition.x += m_particles[i].m_particleSpeed.x * dT;
    m_particles[i].m_pixelPosition.y -= m_particles[i].m_particleSpeed.y * dT;

    m_particles[i].m_particleSpeed.x += m_gravity.x * dT;
    m_particles[i].m_particleSpeed.y += m_gravity.y * dT;

    m_particles[i].m_particleSprite.setPosition(m_particles[i].m_pixelPosition);
  }

  if(m_particles.size() > 0)
  {
    if(dissolutionClock.getElapsedTime().asSeconds()>=1.0/m_dissolutionRate)
    { 
      m_particles.erase(m_particles.begin());
      dissolutionClock.restart();
    }
  }

}

void Particles::setDissolutionRate(int rate)
{
  m_dissolutionRate = rate;
}

void Particles::setGravity(sf::Vector2f gravity)
{
  m_gravity = gravity;
}