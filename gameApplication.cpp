/*

Function file for gameApplication.h

*/

#include "gameApplication.h"
#include "messageManager.h"
#include "icon.c"

//Game Application constructor to initialize variables
GameApplication::GameApplication(void)
{

  m_updateRate = 60; //Update ticks per second
  m_errorCode = 0; //Debugging code

}

//Main run loop responsible for starting the game loop and
//initializing the window
int GameApplication::run(void)
{

  //Create the render window
  m_mainWindow.create(sf::VideoMode(1280, 720), "Private Eye");
  MessageManager::setWindow(&m_mainWindow);

  //Change the icon on the task bar to the image in icon.c
  m_mainWindow.setIcon(icon.width,icon.height,icon.pixel_data);

  //Default the game to the first available state
  //In this case its the main menu
  m_stateManager.setState(0);

  //Go ahead and start the game loop
  gameLoop();

  return m_errorCode;
}

//Main game loop that runs indefinitely until the player quits
void GameApplication::gameLoop(void)
{

  //Clock object for getting the time
  sf::Clock tickClock;
  tickClock.restart(); //Set the time in milliseconds to 0

  short updates = 0; //Number of updates that have happened

  //nextTick is the time when the next tick should occur
  sf::Int32 nextTick = tickClock.getElapsedTime().asMilliseconds();

  //currentTime is what time it currently is
  sf::Int32 currentTime;

  //Debugging purposes only, remove later
  sf::Int32 framerateClock = tickClock.getElapsedTime().asMilliseconds();
  int frames = 0;

  //While window is open, run an infinite loop
  while(m_mainWindow.isOpen())
  {
    //Reset the amount of updates that have happened
    updates = 0;

    //Check for events
    processInput();

    //Check to see if the state manager has thrown any flags
    m_stateManager.checkFlags();

    //Set the currentState pointer to be equal to the current state
    m_currentState = m_stateManager.getCurrentState();

    //If the state threw a quit flag, close game
    if(m_currentState->getQuitFlag())
    {

      m_mainWindow.close();

    }

    //Update current time clock
    currentTime = tickClock.getElapsedTime().asMilliseconds();

    //Every tick run fixed updates and then keep track of how many ticks
    //have happened
    while((currentTime - nextTick) >= (1000/m_updateRate) && updates++ < m_updateRate)
    {
      //Current Game state updates here
      m_currentState->updateFixed();

      MessageManager::setDeltaTime(currentTime - nextTick);

      //Set the next tick to 1/updateRate in milliseconds from now
      nextTick += (1000/m_updateRate);

    }

    //This is an FPS clock that runs once per second and keeps track of frames
    if((currentTime - framerateClock) >= 1000)
    {
      framerateClock = tickClock.getElapsedTime().asMilliseconds();
      std::cout << frames << " FPS" << std::endl;
      frames = 0;
    }

    //This is to handle state level events
    m_currentState->handleEvents(m_windowEvent);

    //Handle UI that needs reference to window
    m_currentState->handleUI(m_mainWindow, m_windowEvent);

    //Update anything that doesnt depend on ticks such as physics
    m_currentState->updateVariable();

    //Draw the current window
    m_currentState->Draw(m_mainWindow);

    //Update the amount of frames that have been rendered
    frames++;

  }

}

//Deal with any event input from the window, and update the events
//Object for other functions
void GameApplication::processInput(void)
{

  //Loop to poll events and updates the m_windowEvent object
  while(m_mainWindow.pollEvent(m_windowEvent))
  {

    if(m_windowEvent.type == sf::Event::Closed)
    {
      m_mainWindow.close();
    }

  }

}
