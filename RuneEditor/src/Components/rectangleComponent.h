#pragma once

#include <RuneEngine.h>
#include "mainEditorWindow.h"
#include <EngineDataStructures/createdComponent.h>
#include <EngineDataStructures/createdGameObject.h>

class RectangleComponent : public CreatedComponent
{
public:
  rune::RectangleShape rectangle;
  float colors[3] = {0.0};
    
  RectangleComponent(std::string newType, std::string newName, rune::GameObject* parent, std::string newFilePath = "")
    : CreatedComponent(newType, newName, parent, newFilePath)
  {

    parent->addComponent(rectangle);
    EditorWindow::getWindow()->currentlyOpenProject.activeScene->scene->submitToRenderer(rectangle);

    rectangle.setFillColor(rune::Color(255 * colors[0], 255 * colors[1], 255 * colors[2]));

    rectangle.start();

  }

  float size[2] = { 0 };

  virtual void inspectComponent()
  {

    toolTip("A rectangle of a single color that can be drawn to the screen");

    ImGui::Columns(2, "mycolumns2", true);  // 3-ways, no border
    ImGui::AlignTextToFramePadding();
    ImGui::Text("Rectangle Dimensions:");
    ImGui::NextColumn();
    ImGui::DragFloat2(" ", size, .1);

    ImGui::Columns(1);

    parentObject->transform.setBounds(rune::Vec2(size[0],size[1]));

    if(ImGui::ColorPicker3("Color", colors))
    {
      rectangle.setFillColor(rune::Color(255*colors[0], 255 * colors[1], 255 * colors[2]));
    }
  }

};