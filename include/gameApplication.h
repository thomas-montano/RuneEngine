/*!
 * @page entryPoint Entry Point
 * In order to start a new project, you have to create an entry point for the game and then load in the scenes you want to use.
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
 *   GameApplication* mainApplication = mainApplication->getApplication();
 *    
 *   getGameInstance()->getWindow()->setWindowTitle("My Game Title");
 * 
 *   //Load the first level into the game application
 *   FirstLevel* firstLevel = new FirstLevel();
 *   mainApplication->loadScene("First Level", firstLevel);
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
 * To see how to create your own rune::GameScene, [check out that programming guide.](scenes.html)
 * 
 * 
 */

/**
 * @class rune::GameApplication
 * @brief Entry point for all programs using the engine, must instantiate a game application for every new game. Use the macro getGameInstance() to get a pointer to the current game instance.
 * 
 * @warning This class is a singleton, all functions called operate on the same object.
 * 
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

#define getGameInstance() rune::GameApplication::getApplication()

namespace rune{

class RUNE_ENGINE GameApplication
{
private:

  static GameApplication* currentApplication;

  RenderWindow m_mainWindow;

  double deltaTime;
  int frameRate;
  
  bool m_gameRunning;
  int m_updateRate;

  SceneManager m_sceneManager;

  ///Default constructor for setting up a new game.
  GameApplication(std::string const& title = "Rune Engine", int updateRate = 60);

public:
  /** 
   * A code that will be returned when the application closes that says what happened if execution failed.\n
   * 0 = Execution concluded successfully.\n
   * 1 = A rune::GameScene had not been loaded into the application at run time.
   */
  int m_errorCode;

  //Delete the copy constructor
  ///@cond
  GameApplication(const GameApplication&) = delete;
  ///@endcond
  
  ///@return A pointer to the currently open rune::GameApplication.
  static GameApplication* getApplication()
  {
    if(!currentApplication)
    {
      currentApplication = new GameApplication;
    }

    return currentApplication;
  }

  ///Loads in a scene file and stores it in the game application.
  void loadScene(std::string const& sceneName, GameScene* newScene);
  ///Starts the main game loop
  int run(void);
  ///Returns the reference to the currently active render window.
  RenderWindow* getWindow(void);
  ///Gets the change in time since the last frame in seconds.
  double getDeltaTime(void);
  ///Gets the number of frames since the last game tick.
  int getFrameRate(void);
  ///Shut down the game.
  void quitApplication();
  ///Change the currently active scene.
  void changeScene(std::string const& newScene);
  ///Get a pointer to the currently active scene.
  GameScene* getCurrentScene(void);

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
 * You can check out the latest release of the engine here:
 *
 * https://github.com/ThomasMontanoGames/RuneEngine/releases
 *
 * @subsection setup Setting up a New Rune Project
 * 
 * 1. Add the path "Rune Engine Directory"/include in the C/C++ settings of your project.
 * 2. Add the path "Rune Engine Directory"/lib in the linker settings of your project
 * 3. Link the LIB file in the linker settings of your project.
 * 4. Move the DLL file into your game's working directory. 
 * 5. Declare `RUNE_PLATFORM_WINDOWS` in the preprocessor definitions of your project.
 * 6. ```#include <RuneEngine.h>``` in the files using the engine.
 * 
 * @warning Make sure you are building in 64-bit, RUNE does not support 32 bit.
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
