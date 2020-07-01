#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"

class SceneViewPort : public rune::Drawable
{
public:
  rune::FrameBuffer viewBuffer;

  SceneViewPort()
  {
  
    viewBuffer.setSize(rune::GameApplication::getWindow()->getSize());

  }

  virtual void draw(rune::RenderWindow& window) override
  { 

    ImGui::Begin("View Port", NULL, ImGuiWindowFlags_NoCollapse);

    double scalingFactor;

    //Adjust the size of the viewport image to make sure that no image stretching occurs
    if(ImGui::GetContentRegionAvail().x / viewBuffer.getSize().x < ImGui::GetContentRegionAvail().y / viewBuffer.getSize().y)
    {
    
      scalingFactor = ImGui::GetContentRegionAvail().x / viewBuffer.getSize().x;
    
    }
    else
    {
    
      scalingFactor = ImGui::GetContentRegionAvail().y / viewBuffer.getSize().y;
    
    }

    uint32_t textureID = viewBuffer.getColorBuffer();

    ImGui::SetCursorPosY(0.5*(ImGui::GetWindowSize().y + ImGui::GetFrameHeight()) -(0.5*scalingFactor *viewBuffer.getSize().y));

    ImGui::Image((void*)textureID, ImVec2(scalingFactor * viewBuffer.getSize().x, scalingFactor * viewBuffer.getSize().y),ImVec2(0,1),ImVec2(1,0));

    ImGui::End();

  }

};