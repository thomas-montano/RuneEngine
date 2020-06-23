#pragma once

#include <RuneEngine.h>

class ResourceTabComponent : public rune::Component
{

public:
  
  void update() override
  {
  
    ImGui::Begin("Resources", NULL, ImGuiWindowFlags_NoCollapse);

    //ImGui::SetWindowPos(ImVec2(0, rune::GameApplication::getWindow()->getSize().y-300));
    //ImGui::SetWindowSize(ImVec2(rune::GameApplication::getWindow()->getSize().x-400,300));

    ImGui::End();

  }

};