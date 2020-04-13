/*

  function file for stateManager.h

*/

#include "stateManager.h"
#include "gameState.h"
#include "firstLevel.h"
#include "mainMenu.h"

//Return a pointer to the current game state
GameState* StateManager::getCurrentState(void)
{
  return m_states[m_currentState];
}

//Change the current game state
void StateManager::setState(int newState)
{

  if(m_states[m_currentState]->isActive())
  {
    m_states[m_currentState]->pause();
  }
  else
  {
    //Handle cleanup from the old state if state is no longer active
    m_states[m_currentState]->handleCleanup();
  }

  //Set current state index to the new state
  m_currentState = newState;

  if(m_states[m_currentState]->isActive())
  {
    m_states[m_currentState]->resume();
  }
  else
  {
    m_states[m_currentState]->doInit();
  }

}

//Check to see if the current state has thrown any flags
//this lets us know whether or not GameApplication needs to
//do anything
void StateManager::checkFlags(void)
{

  //If the current state is asking to change the state
  if(m_states[m_currentState]->getStateFlag() == true)
  {

    //Reset the state flag
    m_states[m_currentState]->setStateFlag(false);

    //Tell the state manager to get the next state
    this->setState(m_states[m_currentState]->getNextState());

  }

}
