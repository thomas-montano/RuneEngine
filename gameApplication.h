/*

  GameApplication

  Class responsible for managing the game Loop
  The tick system is also created here
  As well as updating the events

  Thomas Montano
  3/2/20

*/

#ifndef GAMEAPP_H_INCLUDED
#define GAMEAPP_H_INCLUDED

#include "stateManager.h"
#include "messageManager.h"
#include  <SFML/Graphics.hpp>
#include <iostream>

class GameApplication
{
private:

  bool m_gameRunning;
  sf::RenderWindow m_mainWindow;
  sf::Event m_windowEvent;
  short m_updateRate;

  StateManager m_stateManager;
  GameState* m_currentState;

public:
  int m_errorCode;

  GameApplication(void);

  int run(void);
  void gameLoop(void);
  void processInput(void);
};


#endif
