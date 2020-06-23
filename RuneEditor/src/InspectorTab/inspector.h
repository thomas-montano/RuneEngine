#pragma once

#include <RuneEngine.h>
#include "inspectorComponent.h"

class InspectorTab : public rune::GameObject
{

public:
  InspectorComponent inspectorTab;

  InspectorTab()
  {
  
    addComponent(inspectorTab);

  }


};