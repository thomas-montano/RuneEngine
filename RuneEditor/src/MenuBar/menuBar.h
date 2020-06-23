#pragma once

#include <RuneEngine.h>
#include "menuBarComponent.h"

class MenuBar : public rune::GameObject
{

public:
  MenuBarComponent menuBar;


  MenuBar()
  {
  
    addComponent(menuBar);

  }

};