#pragma once

#include <RuneEngine.h>
#include <mainEditorWindow.h>

class SceneViewPort : public rune::Drawable
{
private:

public:
  bool added = false;

  virtual void draw(rune::RenderWindow&) override
  { 

    ImGui::Begin("View Port", NULL, ImGuiWindowFlags_NoCollapse);
    //viewportBuffer->setSize(rune::Vec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y));

    //uint32_t textureID = viewportBuffer->getColorBuffer();

    //ImGui::Image((void*)textureID, ImGui::GetContentRegionAvail());

    ImGui::End();

  }

};