#pragma once

#include <RuneEngine.h>
#include "createdGameObject.h"

class CreatedScene
{
public:
  std::string sceneName;
  std::vector<CreatedGameObject> m_sceneObjects;
  rune::GameScene scene;

  CreatedScene(std::string newSceneName)
  {
    sceneName = newSceneName;
  }

  void buildScene(void)
  {
  
    for(int i = 0; i < m_sceneObjects.size();i++)
    {
    
      m_sceneObjects[i].buildObject();
    
    }
  }

};