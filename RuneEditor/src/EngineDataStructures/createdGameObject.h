#pragma once

#include <RuneEngine.h>
#include "createdComponent.h"

class CreatedGameObject
{
public:
  std::string objectName;
  std::vector<CreatedComponent> objectComponents;


  CreatedGameObject(std::string newName)
  {

    objectName = newName;
    
    CreatedComponent defaultTransform("rune::Transform", "Transform", "Entities/transform.h");

    objectComponents.push_back(defaultTransform);

  }

  void buildObject(void);
  

};