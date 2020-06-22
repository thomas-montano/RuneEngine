#pragma once

#include <RuneEngine.h>

class windowComponent : public rune::Component
{

public:
  void update() override
  {

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 0;

    drawSceneContents();

  }

  void drawSceneContents();

    

};

