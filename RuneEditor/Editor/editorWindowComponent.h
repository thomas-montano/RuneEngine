#pragma once

#include <RuneEngine.h>

class EditorWindowComponent : public rune::Component
{

public:
  void update() override
  {

    drawSceneContents();

  }

  void drawSceneContents();

    

};

