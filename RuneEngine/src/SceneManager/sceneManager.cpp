#include "sceneManager.h"
#include "gameScene.h"

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
void rune::SceneManager::setScene(std::string const& newScene)
{

  if(m_currentScene != "")
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

/**
 * @return The total number of scenes currently stored in the SceneManager scene buffer.
*/
int rune::SceneManager::getNumScenes(void)
{

  return m_scenes.size();

}

/**
 * @param sceneName A string that is used to refer back to the scene.
 * @param newScene New GameScene to be added into the SceneManager scene buffer. 
*/
void rune::SceneManager::addScene(std::string const& sceneName, GameScene* newScene)
{
  //m_scenes[sceneName] = newScene;
  m_scenes.insert({sceneName,newScene});
}
