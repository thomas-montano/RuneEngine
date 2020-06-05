#include "sceneManager.h"
#include "gameScene.h"

int rune::SceneManager::m_currentScene = 0;
std::vector<rune::GameScene*> rune::SceneManager::m_scenes = {};

/**
 * @return A pointer to the currently active GameScene
*/
rune::GameScene* rune::SceneManager::getCurrentScene(void)
{
  return m_scenes[m_currentScene];
}

/**
 * @param newScene Index in the scene buffer that determines what scene should be set as 
*/
void rune::SceneManager::setScene(int newScene)
{

  if(!m_scenes.empty())
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
    m_scenes[m_currentScene]->startComponents();
  }

}

void rune::SceneManager::checkFlags(void)
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

/**
 * @return The total number of scenes currently stored in the SceneManager scene buffer.
*/
int rune::SceneManager::getNumScenes(void)
{

  return m_scenes.size();

}

/**
 * @param newScene New GameScene to be added into the SceneManager scene buffer. 
*/
void rune::SceneManager::addScene(rune::GameScene* newScene)
{

  m_scenes.push_back(newScene);

}
