#pragma once

#include <string>
#include <vector>

class CreatedComponent
{
public:
  CreatedComponent(std::string newType, std::string newName)
  { 
    componentType = newType;
    componentName = newName;
  }
  
  std::string componentName;
  std::string componentType;

  void buildComponent(void);

};

