#pragma once

#include "createdScene.h"
#include <fstream>

class RuneEngineProject
{
private:
  std::string projectName;

public:

  std::string windowTag = " - Rune Engine Editor Version 0.2.7 - alpha";

  std::vector<CreatedScene*> projectScenes;
  std::string projectSaveLocation;
  CreatedScene* activeScene;

  void setProjectName(std::string newName)
  {
    projectName = newName;
    getGameInstance()->getWindow()->setWindowTitle(projectName + windowTag);
  }

  std::string getProjectName(void)
  {
    return projectName;
  }

  RuneEngineProject(std::string newName)
  {
    projectName = newName;
    CreatedScene* defaultScene = new CreatedScene("Default Scene");
    projectScenes.push_back(defaultScene);
    activeScene = projectScenes[0];
  }

  void buildProject(void)
  {
  
    for(int i = 0; i < projectScenes.size();i++)
    {
      
      std::ofstream writeFile;
      writeFile.open(projectSaveLocation + "\\" + projectName + ".rproj");

      writeFile << projectName << std::endl;
      writeFile << projectSaveLocation << std::endl;

      projectScenes[i]->buildScene();
    
      writeFile.close();

    }
  
  }

};
