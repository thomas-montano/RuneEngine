/*!
 * @mainpage
 * In order to start a new project, all you have to do is load in your scenes, create a new
 * rune::GameApplication object, pass the scenes in, and set the rune::GameApplication to run. 
 * 
 * The window will open with a default title of "Rune Engine", but you can change this by calling mainApplication->setWindowTitle("Your Title");
 * 
 * \section Intro How to Start a New Project
 * 
 * 
 * Create your first GameScene:
 * 
 * firstLevel.h:
 * @code
 * 
 * #ifndef FIRSTLEVEL_H_INCLUDED
 * #define FIRSTLEVEL_H_INCLUDED
 * 
 * #include <RuneEngine.h>
 * 
 * class FirstLevel : public GameScene
 * {
 * private:
 * 
 * public:
 * 
 * };
 * 
 * @endcode
 * 
 * firstLevel.cpp:
 * 
 * @code
 * 
 * #include "firstLevel.h"
 * 
 * void FirstLevel::doInit(void)
 * {
 * 
 * }
 * 
 * @endcode
 * 
 * Load that scene into the game application:
 * 
 * @code 
 * #include <RuneEngine.h>
 * #include "firstLevel.h"
 * #include <iostream>
 * 
 * int main(void)
 * {
 *   //Initialize our game application at a 60 Hz clock
 *   GameApplication* mainApplication = new GameApplication(60);
 * 
 *   //Load the first level into the game application
 *   FirstLevel* firstLevel = new FirstLevel();
 *   mainApplication->loadScene(firstLevel);
 * 
 *   //Start the game
 *   mainApplication->run();
 * 
 *   //Command line output
 *   std::cout << "Returned code: " << mainApplication->m_errorCode << std::endl;
 * 
 *   //Once the game has ended, clean up
 *   delete mainApplication;
 *   delete firstLevel;
 *   return 0;
 * }
 * 
 * @endcode
 * 
 * @author Thomas Montano
 * @date April 27 2020 
 * 
 */

/**
 * @class rune::GameApplication
 * @brief Entry point for all programs using the engine, must instantiate a game application for every new game
 * @author Thomas Montano
 * 
 * @date March 2 2020
*/



#ifndef GAMEAPP_H_INCLUDED
#define GAMEAPP_H_INCLUDED

#include "core.h"
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#include <SceneTools\sceneManager.h>
#include <Renderer\RenderWindow.h>
#include <Events\clock.h>
#include <Events\event.h>
#include <iostream>

namespace rune{

class RUNE_ENGINE GameApplication
{
private:

  RenderWindow m_mainWindow;

  static RenderWindow* winPtr;
  static double deltaTime;
  static int frameRate;
  
  bool m_gameRunning;
  Event m_windowEvent;
  int m_updateRate;

  SceneManager m_sceneManager;
  GameScene* m_currentScene;

  ///Main game loop used to keep the game running and updating.
  void gameLoop(void);

  ///Window level input handling.
  void processInput(void);

public:
  /** 
   * A code that will be returned when the application closes that says what happened if execution failed.\n
   * 0 = Execution concluded successfully.\n
   * 1 = A rune::GameScene had not been loaded into the application at run time.
   */
  int m_errorCode;
  ///Default constructor for setting up a new game.
  GameApplication(std::string title = "Rune Engine", int updateRate = 60);
  ///Set the title of the window
  void setWindowTitle(std::string);
  ///Loads in a scene file and stores it in the game application.
  void loadScene(GameScene* newScene);
  ///Starts the main game loop
  int run(void);
  ///Returns the reference to the currently active render window.
  static RenderWindow* getWindow(void);
  ///Gets the change in time since the last frame in seconds.
  static double getDeltaTime(void);
  ///Gets the number of frames since the last game tick.
  static int getFrameRate(void);

};
}

#endif
