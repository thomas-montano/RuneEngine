/**
 * @class FirstLevel
 * @brief Main level operating as an engine test bed
 * 
 * @author Thomas Montano
 * @date Februray 29 2020
*/

#ifndef FIRSTLEVEL_H_INCLUDED
#define FIRSTLEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "./Engine/gameScene.h"
#include "player.h"

class FirstLevel : public GameScene
{
private:

  bool isStateActive = false;

  ParticleEmitter* testParticle = new ParticleEmitter(sf::Vector2f(100,635), sf::Vector2f(0,40), sf::Color::Blue, 4,sf::Vector2f(0,-80));

  Player m_player;
  GameObject m_ball;
  GameObject grassTile;

  //Create the level floor
  GameObject m_groundTile1;
  GameObject m_groundTile2;
  GameObject m_groundTile3;
  GameObject m_groundTile4;
  GameObject m_groundTile5;
  GameObject m_groundTile6;
  GameObject m_groundTile7;
  GameObject m_groundTile8;
  GameObject m_groundTile9;
  GameObject m_groundTile10;

  int m_sceneLength;
  int m_sceneHeight;

  sf::SoundBuffer m_soundBuffer;
  sf::Sound m_soundEffect;

public:
  virtual void doInit(void); 
  virtual void reInit(void);
  void deInit(void);
  virtual void pause(void);
  virtual void resume(void);
  virtual void handleEvents(sf::Event theEvent);
  virtual void updateFixed(void);
  virtual void updateVariable(void);
  virtual void handleCleanup(void);
  virtual void handleUI(sf::RenderWindow& window);
  virtual bool isActive(void);

};


#endif
