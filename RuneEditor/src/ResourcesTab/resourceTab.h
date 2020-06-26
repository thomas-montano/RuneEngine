#pragma once

#include <RuneEngine.h>

class ResourceTab : public rune::Drawable
{

public:
  void draw(rune::RenderWindow&) override
  {

    ImGui::Begin("Resources", NULL, ImGuiWindowFlags_NoCollapse);

    //ImGui::SetWindowPos(ImVec2(0, rune::GameApplication::getWindow()->getSize().y-300));
    //ImGui::SetWindowSize(ImVec2(rune::GameApplication::getWindow()->getSize().x-400,300));

    ImGui::End();

  }
  

};