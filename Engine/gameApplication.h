/**
 * @class GameApplication
 * @brief Entry point for all programs using the engine, must instantiate a game application for every new game
 * @author Thomas Montano
 * 
 * @date March 2 2020
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

  ///Default constructor for setting up a new game.
  GameApplication(int updateRate);

  ///Loads in a scene file and stores it in the game application.
  void loadScene(GameScene* newScene);

  ///Starts the main game loop
  int run(void);

  ///Main game loop used to keep the game running and updating.
  void gameLoop(void);

  ///Window level input handling.
  void processInput(void);
};


#endif
