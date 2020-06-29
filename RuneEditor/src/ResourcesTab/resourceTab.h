#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"

class ResourceTab : public rune::Drawable
{
private:

public:
  void draw(rune::RenderWindow&) override
  {

    ImGui::Begin("Resources", NULL, ImGuiWindowFlags_NoCollapse);

    //std::cout << "Size: " << rune::Vec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y) << std::endl;
    //std::cout << "Position: " << rune::Vec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y) << std::endl;

    ImGui::End();

  }
  

};