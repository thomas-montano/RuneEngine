#pragma once
#include "createdComponent.h"

class CreatedGameObject
{
public:
  std::string objectName;
  std::vector<CreatedComponent> objectComponents;

  CreatedGameObject(std::string newName)
  {

    objectName = newName;
    
    CreatedComponent defaultTransform("rune::Transform", "transform");

    objectComponents.push_back(defaultTransform);

  }

  void buildObject(void);
  

};