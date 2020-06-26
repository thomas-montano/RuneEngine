#pragma once

#include <RuneEngine.h>

class InspectorTab : public rune::Drawable
{

public:

  virtual void draw(rune::RenderWindow& window)
  {
  
    ImGui::Begin("Inspector", NULL, ImGuiWindowFlags_NoCollapse);

    //ImGui::SetWindowSize(ImVec2(windowSize, rune::GameApplication::getWindow()->getSize().y - ImGui::GetFrameHeight()));
    //ImGui::SetWindowPos(ImVec2(rune::GameApplication::getWindow()->getSize().x-windowSize, ImGui::GetFrameHeight()));

    ImGui::ShowStyleEditor();

    ImGui::End();
  
  }


};