#pragma once

#include <RuneEngine.h>
#include "resourceTabComponent.h"

class ResourceTab : public rune::GameObject
{

public:
  ResourceTabComponent resourceTab;

  ResourceTab()
  {
  
    addComponent(resourceTab);
  
  }
  

};