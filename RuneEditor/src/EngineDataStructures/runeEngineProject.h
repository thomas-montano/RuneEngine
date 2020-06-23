#pragma once

#include "createdScene.h"

class RuneEngineProject
{
public:
  std::string projectName;
  std::vector<CreatedScene> projectScenes;
  std::string projectSaveLocation;

  RuneEngineProject(std::string newName)
  {
    projectName = newName;
    CreatedScene defaultScene("Sample Scene");
    projectScenes.push_back(defaultScene);

  }

  void buildProject(void)
  {
  
    for(int i = 0; i < projectScenes.size();i++)
    {
    
      projectScenes[i].buildScene();
    
    }
  
  }

};