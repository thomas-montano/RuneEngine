#include "gameApplication.h"

//Initialize Static variables
RenderWindow* rune::GameApplication::winPtr = nullptr;
double rune::GameApplication::deltaTime = 0.0;
int rune::GameApplication::frameRate = 0;

/**
 * @param updateRate How many times per second the game will run the main update loop.
 */
rune::GameApplication::GameApplication(int updateRate) : m_mainWindow(1440, 720, "Rune Engine")
{
  winPtr = &m_mainWindow;
  m_updateRate = updateRate; //Update ticks per second
  m_errorCode = 0; //Debugging code
  m_gameRunning = true;
  m_mainWindow.enableVsync(true);

}

/**
 * @return The generated error code
*/
int rune::GameApplication::run(void)
{

  m_mainWindow.enableVsync(false);

  //If the icon file doesn't exist, dont add an icon
  /*#if __has_include("../icon.c")
    #include "../icon.c"
    m_mainWindow.setIcon(gimp_image.width,gimp_image.height,gimp_image.pixel_data);
  #endif*/

  //Default the game to the first available state
  //In this case its the main menu
  if(m_sceneManager.getNumScenes() > 0)
  {
    deltaTime = 1.0/m_updateRate;
    m_sceneManager.setScene(0);
  }
  else
  {
    m_errorCode = 1;
  }

  //Go ahead and start the game loop
  gameLoop();

  return m_errorCode;
}

void rune::GameApplication::gameLoop(void)
{
  
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
  while(m_mainWindow.isOpen() && m_errorCode == 0)
  {

    //Reset the amount of updates that have happened
    updates = 0;

    //Check for events
    processInput();

    //Check to see if the state manager has thrown any flags
    m_sceneManager.checkFlags();

    //Set the currentState pointer to be equal to the current state
    m_currentScene = m_sceneManager.getCurrentScene();

    //If the state threw a quit flag, close game
    if(m_currentScene->getQuitFlag())
    {

      m_mainWindow.close();

    }

    //Update current time clock
    currentTime = tickClock.getElapsedTimeAsMilliseconds();

    //Every tick run fixed updates and then keep track of how many ticks
    //have happened
    while((currentTime - nextTick) >= (1000.0/m_updateRate) && updates++ < m_updateRate)
    {
      //Current Game state updates here
      m_currentScene->updateFixed();

      deltaTime = (currentTime - nextTick)/1000.0;

      //Set the next tick to 1/updateRate in milliseconds from now on
      nextTick += (1000.0/m_updateRate);
    }

    //This is an FPS clock that runs once per second and keeps track of frames
    if((currentTime - framerateClock) >= 1000)
    {
      framerateClock = tickClock.getElapsedTimeAsMilliseconds();
      frameRate = frames;
      frames = 0;
    }

    //This is to handle state level events
    m_currentScene->handleEvents(m_windowEvent);

    //Handle UI that needs reference to window
    m_currentScene->handleUI(m_mainWindow);

    //Update anything that doesnt depend on ticks such as physics
    m_currentScene->updateVariable();

    //Draw the current window
    m_currentScene->Draw(m_mainWindow);

    //Make sure that each layer gets their collisions updated
    m_currentScene->updateLayerPhysics();

    //Update the amount of frames that have been rendered
    frames++;

  }

}

void rune::GameApplication::processInput(void)
{

  //Loop to poll events and updates the m_windowEvent object
  m_mainWindow.pollEvents(m_windowEvent);

  if(m_windowEvent.type == EventType::Closed)
  {
    m_mainWindow.close();
  }

}

/**
 * @param newScene A pointer to a GameScene object that should be loaded into the scene buffer.
*/
void rune::GameApplication::loadScene(GameScene* newScene)
{

  m_sceneManager.addScene(newScene);

}

///Returns the reference to the currently active render window.
RenderWindow* rune::GameApplication::getWindow(void)
{
  return winPtr;
}

///Gets the change in time since the last frame in seconds.
double rune::GameApplication::getDeltaTime(void)
{
  return deltaTime;
}

int rune::GameApplication::getFrameRate(void)
{
  return frameRate;
}
