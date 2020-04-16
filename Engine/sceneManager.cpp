/*

  function file for stateManager.h

*/

#include "sceneManager.h"
#include "gameScene.h"

//Return a pointer to the current game state
GameScene* SceneManager::getCurrentScene(void)
{
  return m_scenes[m_currentScene];
}

//Change the current game state
void SceneManager::setScene(int newScene)
{

  if(m_scenes[m_currentScene]->isActive())
  {
    m_scenes[m_currentScene]->pause();
  }
  else
  {
    //Handle cleanup from the old state if state is no longer active
    m_scenes[m_currentScene]->handleCleanup();
  }

  //Set current state index to the new state
  m_currentScene = newScene;

  if(m_scenes[m_currentScene]->isActive())
  {
    m_scenes[m_currentScene]->resume();
  }
  else
  {
    m_scenes[m_currentScene]->doInit();
  }

}

//Check to see if the current state has thrown any flags
//this lets us know whether or not GameApplication needs to
//do anything
void SceneManager::checkFlags(void)
{

  //If the current state is asking to change the state
  if(m_scenes[m_currentScene]->getStateFlag() == true)
  {

    //Reset the state flag
    m_scenes[m_currentScene]->setStateFlag(false);

    //Tell the state manager to get the next state
    this->setScene(m_scenes[m_currentScene]->getNextState());

  }

}

int SceneManager::getNumScenes(void)
{

  return m_scenes.size();

}

void SceneManager::addScene(GameScene* newScene)
{

  m_scenes.push_back(newScene);

}
