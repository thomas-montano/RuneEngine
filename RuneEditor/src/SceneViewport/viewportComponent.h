#pragma once

#include <RuneEngine.h>

class ViewportComponent : public rune::Component
{

  void update() override
  {
  
    ImGui::Begin("View Port", NULL, ImGuiWindowFlags_NoCollapse);

    ImGui::End();

  
  }

};