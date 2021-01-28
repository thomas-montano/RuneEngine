#pragma once

#include <RuneEngine.h>
#include <string>
#include <vector>

class CreatedGameObject;

class CreatedComponent
{
public:
  CreatedComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : componentType(newType), componentName(newName), parentObject(parent), filePath(newFilePath)
  {

  }
  
  std::string componentName;
  std::string componentType;
  std::string filePath;

  rune::GameObject* parentObject;

  void buildComponent(void);

  virtual void inspectComponent()
  {
  
  }

  ~CreatedComponent()
  {
  
    delete parentObject;
  
  }

};

void toolTip(std::string tooltip);

