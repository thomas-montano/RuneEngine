#pragma once

#include <RuneEngine.h>

class InspectorComponent : public rune::Component
{

private:
  int windowSize = 400;

public:

  void update()
  {
  
    ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

    //ImGui::SetWindowSize(ImVec2(windowSize, rune::GameApplication::getWindow()->getSize().y - ImGui::GetFrameHeight()));
    //ImGui::SetWindowPos(ImVec2(rune::GameApplication::getWindow()->getSize().x-windowSize, ImGui::GetFrameHeight()));

    ImGui::ShowStyleEditor();

    ImGui::End();
  
  }

};