/*!
 * @page entryPoint How To Create Your First Rune Application
 * In order to start a new project, you have to create an entry point for the game and then load in the scenes you want to use.
 * 
 * \section Intro Create Your Entry Point
 * 
 * Once you have created your entry point, go ahead and create some GameScenes to load into the rune::GameApplication.
 * 
 * @code
 *
 * //Add this pragma comment to disable the console if you haven't already done so.
 * #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
 *
 * //You should include your scene headers and the RuneEngine header.
 * #include <RuneEngine.h>
 * #include "firstLevel.h"
 * #include <iostream>
 *
 * int main(void)
 * {
 *   //Initialize our game application to have a really awesome title.
 *   GameApplication* mainApplication = new GameApplication("My game");
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
 * 
 * @section GameScene Create your first GameScene:
 * 
 * By creating these GameScenes, you will have a scene to load into your rune::GameApplication.
 * 
 * firstLevel.h:
 * @code
 * 
 * 
 * #ifndef FIRSTLEVEL_H_INCLUDED
 * #define FIRSTLEVEL_H_INCLUDED
 * 
 * #include <RuneEngine.h>
 * 
 * //This is a rune::GameObject that is created in a later guide.
 * #include "playerCharacter.h"
 * 
 * class FirstLevel : public GameScene
 * {
 * private:
 *  Player m_player;
 * 
 *  //If you want to have a non static camera, go ahead and create that here.
 *  rune::Camera m_sceneCamera;
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
 *  //Set up the background color for your scene.
 *  clearColor = rune::Color::Blue; 
 * 
 *  //Set up your level layout here
 *  addObjectToScene(m_player);
 *  
 *  //Make sure to set the zoom to something greater than zero.
 *  m_sceneCamera.setZoom(4);
 * 
 * }
 * 
 * @endcode
 * 
 * 
 * @author Thomas Montano
 * @date June 17 2020 
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
#include <SceneManager\sceneManager.h>
#include <Renderer\RenderWindow.h>
#include <Events\clock.h>
#include <Events\event.h>

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
  ///Shuts down the game
  static void quitGame();

};
}

#endif

/**
 * @mainpage
 * 
 * @section Welcome Welcome to the RuneEngine!
 * 
 * You can use the Rune Engine API to create 2D games. This is the manual that will show you how to do that. 
 * 
 * If it's your first time using Rune, you should check out the [Programming Guides.](pages.html)
 * 
 * @subsection startup Getting Started
 * 
 * Visual Studio 2017 or 2019 is recommended. Rune is officially untested on other development environments and is only supported by Windows.
 *
 * You can clone the repository to a local destination using git:
 *
 * `git clone https://github.com/ThomasMontanoGames/PrivateEye.git`
 *
 * @subsection setup Setting up a New Rune Project
 * 
 * 1. Link the LIB file in the linker settings of your project.
 * 2. Move the DLL file into your game's working directory. 
 * 3. Declare `RUNE_PLATFORM_WINDOWS` in the preprocessor definitions of your project.
 * 4. Add the path "Rune Engine Directory"/include in the C/C++ settings of your project.
 * 5. ```#include <RuneEngine.h>``` in the files using the engine.
 * 
 * 
 * @subsection features Engine Features
 * 
 * - Custom 2D renderer
 * - Custom Physics Engine
 * - Customizable Game Objects
 * - Particle System
 * - Lighting System
 * - Physically Accurate Collisions
 * - Animated Sprites
 * - Debug Interface with ImGUI
 * - Tile work flow and sprite work flow
 * 
 * @subsection bugs Engine Issues
 * 
 * Found something that you think isn't working the way it's supposed to? Please submit a bug report on the github repository.
 * 
 */
