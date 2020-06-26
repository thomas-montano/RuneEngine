#pragma once

#include <RuneEngine.h>
#include "windowComponent.h"
#include <vector>

class SceneHierarchyWindow : public rune::GameObject
{
private:
  
public:

  windowComponent toolbar;

  SceneHierarchyWindow()
  {
    //addComponent(toolbar);
  }

};
