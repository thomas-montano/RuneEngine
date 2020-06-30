#pragma once

#include <RuneEngine.h>
#include "createdComponent.h"

class CreatedGameObject
{
public:
  std::string objectName;
  std::vector<CreatedComponent*> objectComponents;
  rune::GameObject* gameObject;

  CreatedGameObject(std::string newName);

  void buildObject(void);

  ~CreatedGameObject()
  {
    delete gameObject;  
  }
  

};