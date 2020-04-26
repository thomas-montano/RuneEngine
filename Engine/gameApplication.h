/*!
 * @mainpage
 * In order to start a new project, all you have to do is load in your scenes, create a new
 * GameApplication object, pass the scenes in, and set the GameApplication to run. 
 * \section Intro How to Start a New Project
 * 
 * @code 
 * #include "Engine/gameApplication.h"
 * #include "firstLevel.h"
 * #include <iostream>
 * 
 * int main(int argc, char* argv[])
 * {
 *  //Initialize our game application at a 60 Hz clock
    GameApplication* mainApplication = new GameApplication(60);
    //Load the first level into the game application
    FirstLevel* firstLevel = new FirstLevel();
    mainApplication->loadScene(firstLevel);
    //Start the game
    mainApplication->run();
    //Command line output
    std::cout << "Returned code: " << mainApplication->m_errorCode << std::endl;
    //Once the game has ended, clean up
    delete mainApplication;
    delete firstLevel;
    return 0;
 * }
 * 
 * @endcode
 * 
 * @author Thomas Montano
 * @date February 20 2020 
 * 
 */

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
