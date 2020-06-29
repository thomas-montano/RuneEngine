#pragma once

#include <RuneEngine.h>
#include <string>
#include <vector>

class CreatedComponent
{
public:
  CreatedComponent(std::string newType, std::string newName, std::string newFilePath)
    : componentType(newType), componentName(newName), filePath(newFilePath)
  { 
  }
  
  std::string componentName;
  std::string componentType;
  std::string filePath;

  void buildComponent(void);

};

