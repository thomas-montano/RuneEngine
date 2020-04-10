/*

stateManager

The state manager is responsible for handling the transfer of the
current state pointer that refers to the overwritten state class
for each instance of the game.

Thomas Montano
3/2/20

*/

#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED

#include "gameState.h"

//Include all of the instances here
#include "firstLevel.h"
#include "mainMenu.h"

class StateManager
{
private:
  int m_currentState; //Index for the current state
  FirstLevel m_firstLevel; //A gamestate for the first level
  MainMenu m_mainMenu; //A gamestate for the main menu

  //Array to hold all of the object pointers for the virtual functions
  GameState* m_states[2] = {&m_mainMenu, &m_firstLevel};
public:
  
  void checkFlags(void);
  GameState* getCurrentState(void);
  void setState(int newState);
};

#endif
