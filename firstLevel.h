/*

First level (actual level design remaining)
Thomas Montano
2/29/20

*/

#ifndef FIRSTLEVEL_H_INCLUDED
#define FIRSTLEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameState.h"
#include "physicsEngine.h"
#include "player.h"
#include "gameObject.h"

class FirstLevel : public GameState
{
private:

  bool isStateActive = false;

  Player m_player;
  GameObject m_ball;

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
