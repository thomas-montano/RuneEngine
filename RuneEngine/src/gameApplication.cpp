#include "gameApplication.h"

//Initialize singleton instance
rune::GameApplication* rune::GameApplication::currentApplication = nullptr;

/**
 * @param title The title for the window to be created.
 * @param updateRate How many times per second the game will run the main update loop.
 */
rune::GameApplication::GameApplication(std::string const& title, int updateRate) : m_mainWindow(1440, 720, title), frameRate(0)
{
  m_updateRate = updateRate; //Update ticks per second
  m_errorCode = 0; //Debugging code
  m_gameRunning = true;
  deltaTime = (1.0 / m_updateRate);
  m_mainWindow.enableVsync(true);

}

/**
 * @return The generated error code
*/
int rune::GameApplication::run(void)
{

  m_mainWindow.enableVsync(false);

  //Default the game to the first available state
  if(m_sceneManager.getNumScenes() == 0)
  {
    m_errorCode = 1;
  }

  //Go ahead and start the game loop
  //Clock object for getting the time
  Clock tickClock;
  tickClock.reset(); //Set the time in milliseconds to 0

  short updates = 0; //Number of updates that have happened

  //nextTick is the time when the next tick should occur
  long nextTick = tickClock.getElapsedTimeAsMilliseconds();

  //currentTime is what time it currently is
  long currentTime;

  //Debugging purposes only, remove later
  long framerateClock = tickClock.getElapsedTimeAsMilliseconds();
  int frames = 0;

  //While window is open, run an infinite loop
  while (m_mainWindow.isOpen() && m_errorCode == 0)
  {

    //Reset the amount of updates that have happened
    updates = 0;

    //Set the currentState pointer to be equal to the current state
    GameScene* activeScene = m_sceneManager.getCurrentScene();

    //Update current time clock
    currentTime = tickClock.getElapsedTimeAsMilliseconds();

    //Every tick run fixed updates and then keep track of how many ticks
    //have happened
    while ((currentTime - nextTick) >= (1000.0 / m_updateRate) && updates++ < m_updateRate)
    {
      //Current Game state updates here
      activeScene->updateFixed();

      deltaTime = (currentTime - nextTick) / 1000.0;

      //Set the next tick to 1/updateRate in milliseconds from now on
      nextTick += (1000.0 / m_updateRate);
    }

    //This is an FPS clock that runs once per second and keeps track of frames
    if ((currentTime - framerateClock) >= 1000)
    {
      framerateClock = tickClock.getElapsedTimeAsMilliseconds();
      frameRate = frames;
      frames = 0;
    }

    //Make sure that each layer gets their collisions updated
    activeScene->updatePhysics();

    //Handle UI that needs reference to window
    activeScene->handleUI(m_mainWindow);

    //Update anything that doesn't depend on ticks such as physics
    activeScene->updateVariable();

    activeScene->updateComponents();

    //Draw the current window
    activeScene->Draw(m_mainWindow);

    //Update the amount of frames that have been rendered
    frames++;

  }

  return m_errorCode;
}

/**
 * @param newScene A pointer to a GameScene object that should be loaded into the scene buffer.
*/
void rune::GameApplication::loadScene(std::string const& sceneName, GameScene* newScene)
{

  m_sceneManager.addScene(sceneName,newScene);

  if (m_sceneManager.getNumScenes() == 1)
  {

    m_sceneManager.setScene(sceneName);

  }

}

///@returns the reference to the currently active render window.
rune::RenderWindow* rune::GameApplication::getWindow(void)
{
  return &m_mainWindow;
}

///@returns The time in seconds since the last game tick.
double rune::GameApplication::getDeltaTime(void)
{
  return deltaTime;
}

///@returns The number of frames since the last game tick.
int rune::GameApplication::getFrameRate(void)
{
  return frameRate;
}

void rune::GameApplication::quitApplication()
{
  m_mainWindow.close();
}

///@param newScene The scene that should be made active.
void rune::GameApplication::changeScene(std::string const& newScene)
{
  m_sceneManager.setScene(newScene);
}

///@return A pointer to the currently active scene.
rune::GameScene* rune::GameApplication::getCurrentScene(void)
{
  return m_sceneManager.getCurrentScene();
}
