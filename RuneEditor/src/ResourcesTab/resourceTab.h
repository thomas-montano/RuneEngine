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

    ImGui::End();

    //ImGui::ShowDemoWindow();

  }

};