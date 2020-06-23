#pragma once

#include <RuneEngine.h>
#include "viewportComponent.h"

class SceneViewPort : public rune::GameObject
{

public:
  ViewportComponent viewport;

  SceneViewPort()
  {
  
    addComponent(viewport);  

  }

};