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

#include "sceneManager.h"
#include "messageManager.h"
#include  <SFML/Graphics.hpp>
#include <iostream>

class GameApplication
{
private:

  bool m_gameRunning;
  sf::RenderWindow m_mainWindow;
  sf::Event m_windowEvent;
  int m_updateRate;

  SceneManager m_sceneManager;
  GameScene* m_currentScene;

public:
  int m_errorCode;

  GameApplication(int updateRate);

  void loadScene(GameScene* newScene);

  int run(void);
  void gameLoop(void);
  void processInput(void);
};


#endif
